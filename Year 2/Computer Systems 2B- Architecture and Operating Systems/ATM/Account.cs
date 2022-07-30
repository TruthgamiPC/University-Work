using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace ATM
{
    public class Account
    {
        //the attributes for the account
        private int balance;
        private int pin;
        private int accountNum;
        private int cardBlockCount;
        public bool flaggedAccount = false;
        int atmAccesscount = 0;

        //semaphore to prevent data races
        SemaphoreSlim semaphore = new SemaphoreSlim(1);


        // a constructor that takes initial values for each of the attributes (balance, pin, accountNumber)
        public Account(int balance, int pin, int accountNum)
        {
            this.balance = balance;
            this.pin = pin;
            this.accountNum = accountNum;
            cardBlockCount = 0;
        }

        //getter and setter functions for balance
        public int getBalance()
        {
            return balance;
        }
        public void setBalance(int newBalance)
        {
            this.balance = newBalance;
        }

        /*
         *   This funciton allows us to decrement the balance of an account
         *   it perfomes a simple check to ensure the balance is greater tha
         *   the amount being debeted
         *   
         *   reurns:
         *   true if the transactions if possible
         *   false if there are insufficent funds in the account
         */
        public Boolean decrementBalance(int amount, Boolean setting)
        {
            atmAccesscount++;

            if (setting)
            {
                // Console.WriteLine("YES YES YES YES");                  Testing
                semaphore.Wait();
                {
                    Thread.Sleep(3000);
                    if (cardBlockCount == 3)
                    {
                        semaphore.Release();
                        return false;
                    }
                    if (this.balance >= amount)
                    {
                        balance -= amount;
                        atmAccesscount--;
                        semaphore.Release();
                        return true;
                    }
                    else
                    {
                        semaphore.Release();
                        atmAccesscount--;
                        return false;
                    }
                }
            }
            else
            {
                //Console.WriteLine("NO NO  -=------------------------");     Testing
                int loc_balance = balance;
                Thread.Sleep(3000);
                if (cardBlockCount == 3)
                {
                    semaphore.Release();
                    return false;
                }
                if (this.balance >= amount)
                {
                    loc_balance -= amount;
                    balance = loc_balance;
                    atmAccesscount--;
                    semaphore.Release();
                    return true;
                }
                else
                {
                    semaphore.Release();
                    atmAccesscount--;
                    return false;
                }
            }
        }

        /*
         * This funciton check the account pin against the argument passed to it
         *
         * returns:
         * true if they match
         * false if they do not
         */
        public Boolean checkPin(int pinEntered)
        {
            if (pinEntered == pin)
            {
                return true;
            }
            else
            {
                cardBlockCount++;
                return false;
            }

        }
        public int getAccountNum()
        {
            if(cardBlockCount == 3)
            {
                flaggedAccount = true;
            }
            return accountNum;
        }
    }
}
