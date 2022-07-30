using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Windows.Forms;

namespace ATM
{
    public partial class ATMForm : Form
    {
       
        private string input = null;
        private Bank Bank;
        private Account[] acs;
        private Account activeAccount = null;
        private Boolean race_state = true;
        //This will be either 0, 1, 2, 3, 4, or 5. If it's 0, the ATM class is NOT expecting a return, if it's 1, it's expecting an account number, if it's 2, a PIN, if it's 3, a deposit/withdrawal cash ammount, 4 in the state of withdrawal, 5 at the end of a transaction waiting to move back to log in for the next customer
        int atmState = 0;
        //0 if not expecting a cancel, 1 if it IS expecting a cancel.
        int cancelState = 0;

        public ATMForm(Bank currentBank)
        {
            InitializeComponent();
            this.Bank = currentBank;
            getAccounts();
            loginToAccount();
        }

        
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        //Stores local reference to Accounts
        private void getAccounts()
        {
            this.acs = Bank.getBankAccounts();
        }

        //Find the account based on account number.
        private Account findAccount()
        {
            for (int i = 0; i < this.acs.Length; i++)
            {
                try
                {
                    if (acs[i].getAccountNum() == Convert.ToInt32(input))
                    {
                        return acs[i];
                    }
                }
                catch (System.FormatException e) { }
            }
            return null;
        }

        //Sets ATM State
        private void dispWithdraw()
        {
            this.rtbScreen.Text = "Please Choose An Amount To Withdraw \n1) 10\t2) 20\t3) 40\n4) 100 \t5) 500";
            atmState = 4;
        }


        //Large Method to deal with Withdrawing Cash
        private void withdrawAction()
        {
            if (input != "")
            {
                if (Convert.ToInt32(input) > 0 && Convert.ToInt32(input) < 6)
                {

                    //opiton one is entered by the user
                    if (Convert.ToInt32(input) == 1)
                    {
                        //attempt to decrement account by 10 punds
                        if (activeAccount.decrementBalance(10, this.race_state))
                        {
                            //if this is possible display new balance and await key press
                            this.rtbScreen.Text = "Your new balance is £" + activeAccount.getBalance() + "\nPress any key to continue.";
                        }
                        else
                        {
                            //if this is not possible inform user and await key press
                            this.rtbScreen.Text = "Insufficent funds. Press any key to continue.";
                        }
                    }
                    else if (Convert.ToInt32(input) == 2)
                    {
                        //20 pounds
                        if (activeAccount.decrementBalance(20, this.race_state))
                        {
                            this.rtbScreen.Text = "Your new balance is £" + activeAccount.getBalance() + "\nPress any key to continue.";
                        }
                        else
                        {
                            this.rtbScreen.Text = "Insufficent funds. Press any key to continue.";
                        }
                    }
                    else if (Convert.ToInt32(input) == 3)
                    {
                        if (activeAccount.decrementBalance(40, this.race_state))
                        {
                            this.rtbScreen.Text = "Your new balance is £" + activeAccount.getBalance() + "\nPress any key to continue.";
                        }
                        else
                        {
                            this.rtbScreen.Text = "Insufficent funds. Press any key to continue.";
                        }
                    }
                    else if (Convert.ToInt32(input) == 4)
                    {
                        if (activeAccount.decrementBalance(100, this.race_state))
                        {
                            this.rtbScreen.Text = "Your new balance is £" + activeAccount.getBalance() + "\nPress any key to continue.";
                        }
                        else
                        {
                            this.rtbScreen.Text = "Insufficent funds. Press any key to continue.";
                        }
                    }
                    else if (Convert.ToInt32(input) == 5)
                    {
                        if (activeAccount.decrementBalance(500, this.race_state))
                        {
                            this.rtbScreen.Text = "Your new balance is £" + activeAccount.getBalance() + "\nPress any key to continue.";
                        }
                        else
                        {
                            this.rtbScreen.Text = "Insufficent funds. Press any key to continue.";
                        }
                    }
                }
                else
                {
                    this.rtbScreen.Text = "That is not a valid selection. Press any key to return back to account and restart transaction.";
                }

                input = "";
                this.rtbScreenInput.Text = input;

                atmState = 5;
            }
            else if (input == "")
            {
                dispWithdraw();
            }
        }

        //Method to show current balance - access accounts class.
        private void dispBalance()
        {
            if (this.activeAccount != null)
            {
                this.rtbScreen.Text = " Your current balance is : " + activeAccount.getBalance() + "\nPress any key to continue.";
            }

            input = "";
            this.rtbScreenInput.Text = input;

            atmState = 5;
        }

        //Sets ATM State
        private void loginToAccount()
        {
            atmState = 1;
            this.rtbScreen.Text = "Please enter your account number.";
        }

        //Sets ATM State
        private void enterPIN()
        {
            atmState = 2;
            this.rtbScreen.Text = "Please enter your PIN number.";
        }

        //Sets ATM State
        private void enterOption()
        {
            atmState = 3;
            this.rtbScreen.Text = "Please choose one of the following options. \n1) Take Out Cash\n2) Balance\n3) Exit";
        }


        //THE FOLLOWING BUTTONS FROM 0 to 9 ARE ALL THE KEYPAD
        private void btn1_Click(object sender, EventArgs e)
        {
            if (atmState == 5)
            {
                //Stage 5 is waiting to move from the end of the transaction back to 
                enterOption();
            }
            else
            {
                this.rtbScreenInput.Text = "";
                input += "1";
                this.rtbScreenInput.Text += input;
            }
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            if (atmState == 5)
            {
                //Stage 5 is waiting to move from the end of the transaction back to 
                enterOption();
            }
            else
            {
                this.rtbScreenInput.Text = "";
                input += "2";
                this.rtbScreenInput.Text += input;
            }
        }

        private void btn3_Click(object sender, EventArgs e)
        {
            if (atmState == 5)
            {
                //Stage 5 is waiting to move from the end of the transaction back to 
                enterOption();
            }
            else
            {
                this.rtbScreenInput.Text = "";
                input += "3";
                this.rtbScreenInput.Text += input;
            }
        }

        private void btn4_Click(object sender, EventArgs e)
        {
            if (atmState == 5)
            {
                //Stage 5 is waiting to move from the end of the transaction back to 
                enterOption();
            }
            else
            {
                this.rtbScreenInput.Text = "";
                input += "4";
                this.rtbScreenInput.Text += input;
            }
        }

        private void btn5_Click(object sender, EventArgs e)
        {
            if (atmState == 5)
            {
                //Stage 5 is waiting to move from the end of the transaction back to 
                enterOption();
            }
            else
            {
                this.rtbScreenInput.Text = "";
                input += "5";
                this.rtbScreenInput.Text += input;
            }
        }

        private void btn6_Click(object sender, EventArgs e)
        {
            if (atmState == 5)
            {
                //Stage 5 is waiting to move from the end of the transaction back to 
                enterOption();
            }
            else
            {
                this.rtbScreenInput.Text = "";
                input += "6";
                this.rtbScreenInput.Text += input;
            }
        }

        private void btn7_Click(object sender, EventArgs e)
        {
            if (atmState == 5)
            {
                //Stage 5 is waiting to move from the end of the transaction back to 
                enterOption();
            }
            else
            {
                this.rtbScreenInput.Text = "";
                input += "7";
                this.rtbScreenInput.Text += input;
            }
        }

        private void btn8_Click(object sender, EventArgs e)
        {
            if (atmState == 5)
            {
                //Stage 5 is waiting to move from the end of the transaction back to 
                enterOption();
            }
            else
            {
                this.rtbScreenInput.Text = "";
                input += "8";
                this.rtbScreenInput.Text += input;
            }
        }

        private void btn9_Click(object sender, EventArgs e)
        {
            if (atmState == 5)
            {
                //Stage 5 is waiting to move from the end of the transaction back to 
                enterOption();
            }
            else
            {
                this.rtbScreenInput.Text = "";
                input += "9";
                this.rtbScreenInput.Text += input;
            }
        }

        private void btn0_Click(object sender, EventArgs e)
        {
            if (atmState == 5)
            {
                //Stage 5 is waiting to move from the end of the transaction back to 
                enterOption();
            }
            else
            {
                this.rtbScreenInput.Text = "";
                input += "0";
                this.rtbScreenInput.Text += input;
            }
        }


        //The Enter Button, uses the states to keep track of what it should do.
        private void btnEnter_Click(object sender, EventArgs e)
        {
            if (cancelState == 1)
            {
                cancelState = 0;
                if (atmState == 1)
                {
                    loginToAccount();
                    input = "";
                    this.rtbScreenInput.Text = input;
                }
                else if (atmState == 2)
                {
                    loginToAccount();
                    input = "";
                    this.rtbScreenInput.Text = input;
                }
                else if (atmState == 3)
                {
                    loginToAccount();
                    input = "";
                    this.rtbScreenInput.Text = input;
                }
                else if (atmState == 4)
                {
                    enterOption();
                }
                else if (atmState == 5)
                {
                    enterOption();
                }
            }
            else if (atmState == 0)
            {
                //State 0 is meant to be empty, just means the ATM is not expecting anything from the User right now.
                input = "";
                this.rtbScreenInput.Text = input;
            }
            else if (atmState == 1)
            {
                //State 1 is where the ATM is expecting an account number when the user presses "enter"
                if (findAccount() != null && input != "")
                {
                    activeAccount = findAccount();
                    if (activeAccount.flaggedAccount == true)
                    {
                        this.rtbScreen.Text = "This account cannot be accessed. Please contact your bank for more information.";
                    }else enterPIN();
                    
                } 
                else
                {
                        this.rtbScreen.Text = "That is not a valid account number. Try Again.";
                }
                input = "";
                this.rtbScreenInput.Text = input;
            }
            else if (atmState == 2)
            {
                //State 2 is where the ATM is expecting an account PIN when the user presses "enter"

                bool correctPIN = activeAccount.checkPin(Convert.ToInt32(input));
                if (correctPIN == true)
                {
                    enterOption();
                }
                else
                {
                    this.rtbScreen.Text = "You have entered an incorrect PIN.\nPlease Enter An Account Number";
                    atmState = 1;
                }
                input = "";
                this.rtbScreenInput.Text = input;
            }
            else if (atmState == 3)
            {
                //State 3 is where the is expecting the user to select an account option when they press enter.
                
                if (input == "1")
                {
                    input = "";
                    this.rtbScreenInput.Text = input;
                    dispWithdraw();
                }
                else if (input == "2")
                {
                    input = "";
                    this.rtbScreenInput.Text = input;
                    dispBalance();
                }
                else if (input == "3")
                {
                    loginToAccount();
                }    
            }
            else if (atmState == 4)
            {
                //State 4 is where the ATM is expecting a cash amount when the user presses "enter"
                if (input == "")
                {
                    withdrawAction();
                }
                else
                {
                    //this.rtbScreen.Text = "Processing Your Request - Please Wait";
                    withdrawAction();
                }
            }
            else if (atmState == 5)
            {
                    //Stage 5 is waiting to move from the end of the transaction back to log in
                    enterOption();
            }
            else
            {
                this.rtbScreen.Text = "1) Please select a valid option.\n1) Take Out Cash\n2) Balance\n3) Exit";
            }

            input = "";
            this.rtbScreenInput.Text = input;
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            if (cancelState == 1)
            {
                cancelState = 0;
                if (atmState == 1)
                {
                    loginToAccount();
                }
                else if (atmState == 2)
                {
                    enterPIN();
                }
                else if (atmState == 3)
                {
                    enterOption();
                }
                else if (atmState == 4)
                {
                    dispWithdraw();
                }
                else if (atmState == 5)
                {
                    dispBalance();
                }
            }
            else if (atmState == 5)
            {
                //Stage 5 is waiting to move from the end of the transaction back to 
                enterOption();
            }

            this.rtbScreenInput.Text = "";
            input = "";
            
        }

        private void raceCondition_On(object sender, EventArgs e)
        {
            this.race_state = true;
            this.yesToolStripMenuItem.Checked = false;
            this.noToolStripMenuItem.Checked = true;
        }

        private void raceCondition_Off(object sender, EventArgs e)
        {
            this.race_state = false;
            this.yesToolStripMenuItem.Checked = true;
            this.noToolStripMenuItem.Checked = false;
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            if (atmState == 5)
            {
                //Stage 5 is waiting to move from the end of the transaction back to 
                enterOption();
            } 
            else
            {
                this.rtbScreen.Text = "Would you like to cancel?\nPress 'Enter' for Yes.\nPress 'Clear' for No.";
                cancelState = 1;
            }
        }

        private void rtbScreen_TextChanged(object sender, EventArgs e)
        {

        }

        private void rtbScreenInput_TextChanged(object sender, EventArgs e)
        {

        }

        private void rtbScreen_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void onToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
    }
}
