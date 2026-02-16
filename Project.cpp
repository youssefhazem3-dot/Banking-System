#include <iostream>
#include "Bank.h"
using namespace std;
int main()
{
    int QWE;
    int TN = 0;
    Validation b;
    Menu a;
    int n;
    a.displayWelcome();
    cout << "Please enter the number of accounts: ";
    n = stoi(b.VnumericIn());
    int v = n * 200;
    Bank* account = new Bank[n];
    Transaction* Tra = new Transaction[v];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of account #" << i + 1 << ": ";
        account[i].setN();
        cout << "Enter the mobile number that consist of 10 digits for account #" << i + 1 << ": ";
        account[i].setM();
        cout << "Enter the account #" << i + 1 << " type: "<<endl;
        cout << "1.Savings.\n";
        cout << "2.Current.\n";
        cout << "3.Recurring Deposit.\n";
        cout << "4.Fixed Deposit.\n";
        cout << "5.DEMAT.\n";
        cout << "6.NRI\n";
        cout << "Your choice: ";
        QWE = b.Vchoice(6);
        switch (QWE)
        {
        case 1:
            account[i].setAT("Savings");
            break;
        case 2:
            account[i].setAT("Current");
            break;
        case 3:
            account[i].setAT("Recurring Deposit");
            break;
        case 4:
            account[i].setAT("Fixed Deposit");
            break;
        case 5:
            account[i].setAT("DEMAT");
            break;
        case 6:
            account[i].setAT("NRI");
            break;
        }
        cout << "Account number: " << account[i].getAN() << endl;
        cout << "------------------------------------------------------------\n";
    }
    a.displayMainMenu(n, account, Tra, TN, v);
    return 0;
}
