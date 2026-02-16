#include "Bank.h"
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<cmath>
#include <cctype>
#include <regex>
using namespace std;
int NumberOacc;
Account::Account() {
	balance = 0;
	mobile = "";
	name = "";
	accountN = rand();
	AccountT = "";
}
Transaction::Transaction() {
	AN = 0;
	IDT = rand();
	date[0] = 1;
	date[1] = 1;
	date[2] = 2024;
	Ttype = "";
	Tamount = 0;
}
Loan::Loan() {
	IDL = rand();
	Lamount = 0;
	installment = 0;
	Ltype = "";
	interestRate = 0;
	TBP = 0;
	Lmons = 0;
}
void Account::setN() {
	name = Vname();
}
void Account::setM() {
	mobile = VMnumber();
}
void Account::deposit(Transaction J[], int TN) {
	J[TN].setAN(accountN);
	cout << "Enter the amount you want to deposit into the account: ";
	J[TN].setTA();
	balance += J[TN].getTA();
	J[TN].setTt("Deposit");
	J[TN].setD();
	cout << "Transaction ID: " << J[TN].getIDT() << endl;
	cout << "Transaction completed." << endl;
}

void Account::withdraw(Transaction J[], int TN) {
	if (balance != 0) {
		J[TN].setAN(accountN);
		cout << "Enter the amount you want to withdraw from the account: ";
		while (true) {
			J[TN].setTA();
			if (balance < J[TN].getTA())
			{
				cout << "Error your balance is lower than the withdrawl amount\n";
				cout << "Try again: ";
				continue;
			}
			else {
				balance -= J[TN].getTA();
				break;
			}
		}
		J[TN].setTt("Withdraw");
		J[TN].setD();
		cout << "Transaction ID: " << J[TN].getIDT() << endl;
		cout << "Transaction completed." << endl;
	}
	else
		cout << "You cant withdraw as there is no money yet in your account." << endl;
}
void Account::displayA() {
	cout << "The account information:" << endl;
	cout << "Name: " << name << endl;
	cout << "Mobile number: " << mobile << endl;
	cout << "Account number: " << accountN << endl;
	cout << "Current balance: " << balance << endl;
	cout << "Account type: " << AccountT << endl;
}
void Account::close() {
	balance = 0;
	mobile = "";
	name = "";
	accountN = 0;
	cout << "Account deleted sucessfuly." << endl;
}
void Transaction::setD() {
	cout << "Please enter the current date:\n";
	int* D = Vdate();
	date[0] = D[0];
	date[1] = D[1];
	date[2] = D[2];
}
void Transaction::displayT() {
	cout << "The transaction information: " << endl;
	cout << "Transaction ID:" << IDT << endl;
	cout << "Account number: " << AN << endl;
	cout << "Transaction type: " << Ttype << endl;
	cout << "Amount: " << Tamount << endl;
	cout << "Date: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
}
void Transaction::searchT(Transaction b[], int v) {
	bool h = 0;
	int* D;
	int a, e, n;
	cout << "Choose the way of searching for a transaction:\n";
	cout << "1. By account number.\n";
	cout << "2. By Transaction ID.\n";
	cout << "3. By date of the transaction.\n";
	cout << "Your choice: ";
	a = Vchoice(3);
	switch (a) {
	case 1:
		cout << "Enter the account number: ";
		while (true) {
			e = stod(VnumericIn());
			for (int i = 0; i < v; i++)
			{
				if (e == b[i].getAN()) {
					h = 1;
					b[i].displayT();
				}
			}
			if (h)
				break;
			else
			{
				cout << "Not found please try again: ";
				continue;
			}
		}
		break;
	case 2:
		cout << "Enter the Transaction ID: ";
		while (true) {
			n = stod(VnumericIn());
			for (int i = 0; i < v; i++)
			{
				if (n == b[i].getIDT()) {
					h = 1;
					b[i].displayT();
				}
			}
			if (h)
				break;
			else
			{
				cout << "Not found please try again: ";
				continue;
			}
		}
		break;
	case 3:
		cout << "Please enter the date of the transaction:\n";
		while (true) {
			D = Vdate();
			for (int i = 0; i < v; i++) {
				if (D[0] == b[i].getD(0) && D[1] == b[i].getD(1) && D[2] == b[i].getD(2))
				{
					h = 1;
					b[i].displayT();
				}
			}
			if (h)
				break;
			else {
				cout << "Not found try again: ";
				continue;
			}
		}
		break;
	}
}
void Loan::Apply() {
	int a;
	cout << "What type of Loan do you desire:\n";
	cout << "1.Personal Loan" << endl;
	cout << "2.Auto Loan" << endl;
	cout << "3.Student Loan" << endl;
	cout << "4.Mortgage Loan" << endl;
	cout << "5.Home Equity Loan" << endl;
	cout << "6.Credit-builder Loan" << endl;
	cout << "7.Debt Consolidation Loan" << endl;
	cout << "8.Payday Loan" << endl;
	cout << "9.Small Business Loan" << endl;
	cout << "10.Title Loan" << endl;
	cout << "11.Pawnshop Loan" << endl;
	cout << "12.Boat Loan" << endl;
	cout << "13.Recreational Vehicle (RV) Loan" << endl;
	cout << "14.Family Loan" << endl;
	cout << "15.Land Loan" << endl;
	cout << "16.Pool Loan" << endl;
	cout << "Your choice: ";
	a = Vchoice(16);
	switch (a) {
	case 1:
		Ltype = "Personal Loan";
		interestRate = 0.2;
		break;
	case 2:
		Ltype = "Auto Loan";
		interestRate = 0.3;
		break;
	case 3:
		Ltype = "Student Loan";
		interestRate = 0.09;
		break;
	case 4:
		Ltype = "Mortgage Loan";
		interestRate = 0.32;
		break;
	case 5:
		Ltype = "Home Equity Loan";
		interestRate = 0.37;
		break;
	case 6:
		Ltype = "Credit-builder Loan";
		interestRate = 0.04;
		break;
	case 7:
		Ltype = "Debt Consolidation Loan";
		interestRate = 0.16;
		break;
	case 8:
		Ltype = "Payday Loan";
		interestRate = 0.26;
		break;
	case 9:
		Ltype = "Small Business Loan";
		interestRate = 0.4;
		break;
	case 10:
		Ltype = "Title Loan";
		interestRate = 0.25;
		break;
	case 11:
		Ltype = "Pawnshop Loan";
		interestRate = 0.24;
		break;
	case 12:
		Ltype = "Boat Loan";
		interestRate = 0.22;
		break;
	case 13:
		Ltype = "Recreational Vehicle (RV) Loan";
		interestRate = 0.31;
		break;
	case 14:
		Ltype = "Family Loan";
		interestRate = 0.12;
		break;
	case 15:
		Ltype = "Land Loan";
		interestRate = 0.41;
		break;
	case 16:
		Ltype = "Pool Loan";
		interestRate = 0.33;
		break;
	}
	cout << "How much do you want to loan: ";
	setLA();
	addToB(getLA());
	cout << "Your current balance: " << getB() << endl;
	cout << "For how many months do you want to pay the loan for: ";
	setLM();
	calcInst();
}
void Loan::calcInst() {
	TBP = static_cast<double>(Lamount) * (interestRate / (1 - pow(1 + interestRate, -Lmons)));
	TBP += Lamount;
	installment = static_cast<double>(TBP) / static_cast<double>(Lmons);
	cout << "The amount to be paid is: " << TBP << endl;
	cout << "Your installment per month is: " << installment << endl;
}
void Loan::payInst() {
	cout << "Your installment is: " << installment << endl;
	if (getB() < installment && getB() < TBP)
	{
		cout << "Error your balance is lower than the monthly fee."<<endl;
		cout << "The amount of the installment is: " << installment << endl;
	}
	 else if (TBP - installment <= 0) {
		 redFB(TBP);
		 TBP = 0;
		 Lamount = 0;
		 installment = 0;
		 Ltype = "None";
		 cout << "You have paid all your debt.\n";
	 }
	else
	{
		redFB(installment);
		TBP -= installment;
		cout << "Monthly fee paid sucessfuly.\n";
		cout << "The amount to be paid is: " << TBP << endl;
	}
}
void Loan::displayL() {
	cout << "Loan ID: " << IDL << endl;
	cout << "Account number: " << getAN() << endl;
	cout << "Loan amount: " << Lamount << endl;
	cout << "Loan type: " << Ltype << endl;
	cout << "Installment: " << installment << endl;
	cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
	cout << "The amount to be paid is: " << TBP << endl;
}
string Validation::Vname() {
	string n;
	int h = 0;
	while (true) {
		getline(cin, n);
		cin.sync();
		if (n.empty()) {
			cout << "Invalid enter an input: ";
			continue;
		}
		for (char c : n)
		{
			if (!isalpha(c) && c != ' ')
			{
				cout << "Please enter alphabetics only, try again: ";
				h = 0;
				break;
			}
			else
				h = 1;
		}
		if (h == 0)
			continue;
		else
			break;
	}
	return n;
}
string Validation::VMnumber() {
	string m;
	bool h;
	regex pattern("(\\+\\d{1,3}[- ]?)?\\d{10}");
	while (true)
	{
		getline(cin, m);
		cin.sync();
		if (m.empty()) {
			cout << "Invalid enter an input: ";
			continue;
		}
		h = regex_match(m, pattern);
		if (h == false)
		{
			cout << "Your number should contain numbers only and consist of 10 digits.\n"
				<< "Try again: ";
			continue;
		}
		else
			break;
	}
	return m;
}
string Validation::VnumericIn() {
	string a;
	int h = 0;
	while (true)
	{
		getline(cin, a);
		cin.sync();
		if (a.empty()) {
			cout << "Invalid enter an input: ";
			continue;
		}
		for (char c : a)
		{
			if (!isdigit(c) && c != '\n' && c != '.')
			{
				cout << "Please enter positive numbers only with no symbols, try again: ";
				h = 0;
				break;
			}
			else
				h = 1;
		}
		if (h == 0)
			continue;
		else
			break;
	}
	return a;
}
int Validation::Vchoice(int size) {
	int c, h;
	int* a = new int[size];
	for (int i = 0; i < size; i++)
		a[i] = i + 1;
	while (true)
	{
		c = stod(VnumericIn());
		for (int i = 0; i < size; i++)
		{
			if (a[i] != c)
			{
				h = 0;
			}
			else
			{
				h = 1;
				break;
			}
		}
		if (h == 0)
		{
			cout << "Not a valid choice try again: ";
			continue;
		}
		else
			break;
	}
	return c;
}
int* Validation::Vdate() {
	int n;
	cout << "Enter the year between 2024 to 2200: ";
	while (true) {
		date[2] = stod(VnumericIn());
		if (date[2] < 2024 || date[2] > 2200)
		{
			cout << "Invalid year, try again: ";
			continue;
		}
		else
			break;
	}
	cout << "Enter the month: ";
	while (true) {
		date[1] = stod(VnumericIn());
		if (date[1] <= 0 || date[1] > 12)
		{
			cout << "Invalid month, try again: ";
			continue;
		}
		else
			break;
	}
	if (date[1] == 2)
		n = 28;
	else if (date[1] == 1 || date[1] == 3 || date[1] == 5 || date[1] == 7 || date[1] == 8 || date[1] == 10 || date[1] == 12)
		n = 31;
	else
		n = 30;
	if (((date[2] % 4 == 0 && date[2] % 100 != 0) || date[2] % 400 == 0) && (date[1] == 2))
		n = 29;
	cout << "Enter the day: ";
	while (true) {
		date[0] = stod(VnumericIn());
		if (date[0] <= 0 || date[0] > n)
		{
			cout << "Invalid day, try again: ";
			continue;
		}
		else
			break;
	}
	return date;
}
void Transfer::trans(Bank a[], int e, int o, Transaction J[], int& TN) {
	J[TN].setTt("Transfer");
	J[TN].setAN(a[e].getAN());
	cout << "How much do you want to transfer: ";
	while (true) {
		J[TN].setTA();
		if (a[e].getB() < J[TN].getTA())
		{
			cout << "Error your balance is lower than the withdrawl amount\n";
			cout << "Your current balance: " << a[e].getB() << endl;
			cout << "Try again: ";
			continue;
		}
		else {
			a[e].redFB(J[TN].getTA());
			break;
		}
	}
	a[o].addToB(J[TN].getTA());
	J[TN].setD();
	cout << "Transaction ID for the first account: " << J[TN].getIDT() << endl;
	double be = J[TN].getTA();
	int D[3];
	D[0] = J[TN].getD(0);
	D[1] = J[TN].getD(1);
	D[2] = J[TN].getD(2);
	TN++;
	J[TN].setTA2(be);
	J[TN].setTt("Transfer");
	J[TN].setAN(a[o].getAN());
	J[TN].setD2(0, D[0]);
	J[TN].setD2(1, D[1]);
	J[TN].setD2(2, D[2]);
	cout << "Transaction ID for the second account: " << J[TN].getIDT() << endl;
	cout << "Transfer completed." << endl;
}
void Bank::trans(Bank a[], int e, int o, Transaction J[], int& TN) {
	J[TN].setTt("Transfer");
	J[TN].setAN(a[e].getAN());
	cout << "How much do you want to transfer: ";
	while (true) {
		J[TN].setTA();
		if (a[e].getB() < J[TN].getTA())
		{
			cout << "Error your balance is lower than the withdrawl amount\n";
			cout << "Your current balance: " << a[e].getB() << endl;
			cout << "Try again: ";
			continue;
		}
		else {
			a[e].redFB(J[TN].getTA());
			break;
		}
	}
	a[o].addToB(J[TN].getTA());
	J[TN].setD();
	cout << "Transaction ID for the first account: " << J[TN].getIDT() << endl;
	double be = J[TN].getTA();
	int D[3];
	D[0] = J[TN].getD(0);
	D[1] = J[TN].getD(1);
	D[2] = J[TN].getD(2);
	TN++;
	J[TN].setTA2(be);
	J[TN].setTt("Transfer");
	J[TN].setAN(a[o].getAN());
	J[TN].setD2(0, D[0]);
	J[TN].setD2(1, D[1]);
	J[TN].setD2(2, D[2]);
	cout << "Transaction ID for the second account: " << J[TN].getIDT() << endl;
	cout << "Transfer completed." << endl;
}
void Menu::displayWelcome() {
	cout << "Welcome to our bank.\n";
	cout << "----------------------" << endl;
	int n;
	cout << "To continue press 1: ";
	n = Vchoice(1);
}
Bank* Bank::addAcc(Bank a[], int b) {
	int num;
	cout << "How many accounts do you want to add: ";
	num = stod(VnumericIn());
	NumberOacc = num + b;
	Bank* A = new Bank[NumberOacc];
	for (int i = 0; i < b; i++)
	{
		A[i].setAN(a[i].getAN());
		A[i].setM(a[i].getM());
		A[i].setAT(a[i].getAT());
		A[i].addToB(a[i].getB());
		A[i].setN(a[i].getN());
		A[i].setIDL(a[i].getIDL());
		A[i].setLA(a[i].getLA());
		A[i].setIns(a[i].getIns());
		A[i].setLT(a[i].getLT());
		A[i].setINTR(a[i].getINTR());
		A[i].setTBP(a[i].getTBP());
		A[i].setLM(a[i].getLM());
	}
	for (int i = b; i < NumberOacc; i++)
	{
		cout << "Enter the name of account #" << i + 1 << ": ";
		A[i].setN();
		cout << "Enter the mobile number that consist of 10 digits for account #" << i + 1 << ": ";
		A[i].setM();
		cout << "Account number: " << A[i].getAN() << endl;
	}
	return A;
}
void Menu::displayMainMenu(int N, Bank H[], Transaction T[], int& TN, int v) {
	int num, n2;
	bool po = 0;
	int Z;
	cout << "------------------------------------------------------------\n";
	cout << "Which account by account number do you want to operate on: ";
	while (true) {
		Z = stod(VnumericIn());
		for (int i = 0; i < N; i++) {
			if (Z == H[i].getAN())
			{
				num = i;
				po = 1;
			}
		}
		if (po)
			break;
		else {
			cout << "Number not found try again: ";
			continue;
		}
	}
	cout << "Choose which operation to do:\n";
	cout << "1. Make a transaction.\n";
	cout << "2. Loan options.\n";
	cout << "3. Search and Display info.\n";
	cout << "4. Delete account.\n";
	cout << "5. Add accounts.\n";
	cout << "6. Close system.\n";
	cout << "Your choice: ";
	n2 = Vchoice(6);
	cout << "----------------------\n";
	displaySubMenu(n2, N, H, num, T, TN, v);
}
void Menu::displaySubMenu(int Num, int N2, Bank P[], int NUM, Transaction Q[], int& TN, int v) {
	int choice, b, c2, Z;
	bool co = 0;
	Bank* U;
	switch (Num) {
	case 1:
		cout << "1. Deposit.\n";
		cout << "2. Withdraw.\n";
		cout << "3. Transfer to another account.\n";
		cout << "4. Return to Main Menu.\n";
		cout << "Your choice: ";
		choice = Vchoice(4);
		switch (choice) {
		case 1:
			P[NUM].deposit(Q, TN);
			TN++;
			displayMainMenu(N2, P, Q, TN, v);
			break;
		case 2:
			P[NUM].withdraw(Q, TN);
			TN++;
			displayMainMenu(N2, P, Q, TN, v);
			break;
		case 3:
			cout << "Which account by account number do you want to tranfer to: ";
			while (true) {
				Z = stod(VnumericIn());
				for (int i = 0; i < N2; i++) {
					if (Z == P[i].getAN())
					{
						b = i;
						co = 1;
					}
				}
				if (co)
					break;
				else {
					cout << "Number not found try again: ";
					continue;
				}
			}
			P[NUM].trans(P, NUM, b, Q, TN);
			TN++;
			displayMainMenu(N2, P, Q, TN, v);
			break;
		case 4:
			displayMainMenu(N2, P, Q, TN, v);
			break;
		}
		break;
	case 2:
		cout << "1. Apply for a Loan.\n";
		cout << "2. Pay installment.\n";
		cout << "3. Display Loan info.\n";
		cout << "4. Return to Main Menu.\n";
		cout << "Your choice: ";
		choice = Vchoice(4);
		cout << "----------------------------------------\n";
		switch (choice) {
		case 1:
			if (P[NUM].getLA() > 0) {
				cout << "You already took a loan, please pay your debt first befor taking another loan.\n";
			}
			else{
				P[NUM].Apply();
			}
			displayMainMenu(N2, P, Q, TN, v);
			break;
		case 2:
			P[NUM].payInst();
			displayMainMenu(N2, P, Q, TN, v);
			break;
		case 3:
			P[NUM].displayL();
			displayMainMenu(N2, P, Q, TN, v);
			break;
		case 4:
			displayMainMenu(N2, P, Q, TN, v);
			break;
		}
		break;
	case 3:
		cout << "1. Search and display account info.\n";
		cout << "2. Search and display Transaction info.\n";
		cout << "3. Return to Main Menu.\n";
		cout << "Your choice: ";
		choice = Vchoice(3);
		cout << "---------------------------------------\n";
		switch (choice) {
		case 1:
			cout << "Search by:\n";
			cout << "1. Search by account number.\n";
			cout << "2. Search by date of a transaction.\n";
			cout << "3. Search by balance anount range.\n";
			cout << "4. Search by account type.\n";
			cout << "5. Return to Main Menu.\n";
			cout << "Your choice: ";
			c2 = Vchoice(5);
			switch (c2) {
			case 1:
				findANum(P, N2);
				displayMainMenu(N2, P, Q, TN, v);
				break;
			case 2:
				findD(P, N2, Q, TN);
				displayMainMenu(N2, P, Q, TN, v);
				break;
			case 3:
				findARange(P, N2);
				displayMainMenu(N2, P, Q, TN, v);
				break;
			case 4:
				findAType(P, N2);
				displayMainMenu(N2, P, Q, TN, v);
				break;
			case 5:
				displayMainMenu(N2, P, Q, TN, v);
			}
			break;
		case 2:
			searchT(Q, v);
			displayMainMenu(N2, P, Q, TN, v);
			break;
		case 3:
			displayMainMenu(N2, P, Q, TN, v);
			break;
		}
		break;
	case 4:
		P[NUM].close();
		displayMainMenu(N2, P, Q, TN, v);
		break;
	case 5:
		U = addAcc(P, N2);
		cout << "Accounts add sucessfuly.\n";
		displayMainMenu(NumberOacc, U, Q, TN, v);
	case 6:
		cout << "It was nice having you." << endl;
	}
}
void Search::findANum(Bank W[], int size) {
	int Z;
	bool po = 0;
	cout << "Please enter the account number: ";
	while (true) {
		Z = stod(VnumericIn());
		for (int i = 0; i < size; i++) {
			if (Z == W[i].getAN())
			{
				po = 1;
				W[i].displayA();
			}
		}
		if (po)
			break;
		else {
			cout << "Number not found try again: ";
			continue;
		}
	}
}
void Search::findD(Bank S[], int s1, Transaction W[], int size) {
	int* D;
	bool h = 0;
	cout << "Please enter the date of the transaction:\n";
	while (true) {
		D = Vdate();
		for (int i = 0; i < size; i++) {
			if (D[0] == W[i].getD(0) && D[1] == W[i].getD(1) && D[2] == W[i].getD(2))
			{
				h = 1;
				for (int j = 0; j < s1; j++)
					if (S[j].getAN() == W[i].getAN())
						S[j].displayA();
			}
		}
		if (h)
			break;
		else {
			cout << "Not found try again: ";
			continue;
		}
	}
}
void Search::findARange(Bank W[], int size) {
	double z;
	bool h = 0;
	cout << "Please enter the amount you think the account have: ";
	while (true) {
		z = stod(VnumericIn());
		for (int i = 0; i < size; i++) {
			if (z== W[i].getB())
			{
				h = 1;
				W[i].displayA();
			}
		}
		if (h)
			break;
		else
		{
			cout << "Account not found.\n";
			cout << "Try again: ";
			continue;
		}
	}
}
void Search::findAType(Bank W[], int size) {
	string z;
	bool h = 0;
	cout << "Please enter the account type: ";
	while (true) {
		z = Vname();
		for (int i = 0; i < size; i++) {
			if (z == W[i].getAT())
			{
				h = 1;
				W[i].displayA();
			}
		}
		if (h)
			break;
		else
		{
			cout << "Account not found.\n";
			cout << "Try again: ";
			continue;
		}
	}
}