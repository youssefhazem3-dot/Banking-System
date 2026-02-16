#include<string>
#include<iostream>
using namespace std;
#ifndef Bank_h
#define Bank_h
class Validation {
	int date[3];
public:
	string Vname();
	string VMnumber();
	string VnumericIn();
	int Vchoice(int);
	int* Vdate();
};
class Transaction : public Validation {
	int AN;
	int IDT;
	int date[3];
	string Ttype;
	double Tamount;
public:
	Transaction();
	void displayT();
	void setTA() { Tamount = stod(VnumericIn()); }
	void setTA2(double Ta) { Tamount = Ta; }
	void setD();
	void searchT(Transaction b[], int);
	int getD(int a) const { return date[a]; }
	void setTt(string type) { Ttype = type; }
	int getIDT() const { return IDT; }
	double getTA() const { return Tamount; }
	string getTt() const { return Ttype; }
	void setAN(int a) { AN = a; }
	int getAN()const { return AN; }
	void setD2(int a, int b) { date[a] = b; }
};
class Account : public Transaction {
	double balance;
	string mobile;
	string name;
	int accountN;
	string AccountT;
public:
	Account();
	void deposit(Transaction[], int);
	void withdraw(Transaction[], int);
	void setN();
	void setM();
	void setAN(int a) { accountN = a; }
	void setN(string a) { name = a; }
	void setM(string a) { mobile = a; }
	void displayA();
	double getB() const { return balance; }
	string getM() const { return mobile; }
	string getN() const { return name; }
	int getAN() const { return accountN; }
	void addToB(double a) { balance += a; }
	void redFB(double a) { balance -= a; }
	void setAT() { AccountT = Vname(); }
	void setAT(string a) { AccountT = a; }
	string getAT()const { return AccountT; }
	void close();
};
class Loan :public Account {
	int IDL;
	double Lamount;
	double installment;
	string Ltype;
	double interestRate;
	double TBP;
	int Lmons;
public:
	Loan();
	void Apply();
	void setLA() { Lamount = stod(VnumericIn()); }
	void setLM() { Lmons = stod(VnumericIn()); }
	int getIDL()const { return IDL; }
	double getLA() const { return Lamount; }
	double getIns()const { return installment; }
	string getLT()const { return Ltype; }
	double getINTR()const { return interestRate; }
	double getTBP()const { return TBP; }
	int getLM()const { return Lmons; }
	void setIDL(int a) { IDL = a; }
	void setLA(double a)  {  Lamount = a; }
	void setIns(double a) {  installment = a; }
	void setLT(string a) {  Ltype = a; }
	void setINTR(double a) {  interestRate = a; }
	void setTBP(double a) { TBP = a; }
	void setLM(int a) {  Lmons = a; }
	void calcInst();
	void payInst();
	void displayL();
};
class Bank :public Loan {
public:
	void trans(Bank[], int, int, Transaction[], int&);
	Bank* addAcc(Bank[], int);
};
class Transfer : public Bank {
public:
	void trans(Bank[], int, int, Transaction[], int&);
};
class Search : public Transfer {
public:
	void findANum(Bank[], int);
	void findD(Bank[], int, Transaction[], int);
	void findARange(Bank[], int);
	void findAType(Bank[], int);
};
class Menu : public Search {
public:
	void displayWelcome();
	void displayMainMenu(int, Bank[], Transaction[], int&, int);
	void displaySubMenu(int, int, Bank[], int, Transaction[], int&, int);
};
#endif
