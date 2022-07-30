using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Threading;
using System.Windows.Forms;

namespace ATM
{
    class Program
    {

        static void Main(string[] args)
        {
            Bank Bank = new Bank();
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);


            //code adapted from https://stackoverflow.com/questions/13776846/pass-parameters-through-parameterizedthreadstart
            var runAnotherATM = new Thread(
        () => runATM(Bank));
            //Thread runAnotherATM = new Thread(runATM);
            runAnotherATM.Start();
            var runDoubleATM = new Thread(
        () => runATM(Bank));
            runDoubleATM.Start();

        }

        private static void runATM(Bank bank)
        {
            Application.Run(new ATMForm(bank));
        }
    }
}
