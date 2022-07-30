using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ATM
{
    public class Bank
    {
        // Threads enter the semaphore by calling the WaitOne method, which is inherited from the WaitHandle class, and release the semaphore by calling the Release method.
        //semaphore(minimum number of entries to the resources, max number of entry to resources)
        //Semaphore semaphore = new Semaphore(0, 3);

        private Account[] acs = new Account[3];
        
        public Bank()
        {
            //Initializes 3 Accounts
            acs[0] = new Account(300, 1111, 111111);
            acs[1] = new Account(750, 2222, 222222);
            acs[2] = new Account(3000, 3333, 333333);

  
        }

        public Account[] getBankAccounts()
        {
            return acs;
        }

        public void confirmAccount(Account a)
        {

        }

    }
}
