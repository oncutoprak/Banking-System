#include "CheckingAccount.h"

CheckingAccount::CheckingAccount() {
}

CheckingAccount::CheckingAccount(double b, long a, Customer *o, double tf, double ci) :Account(b, a, o), transactionFee(tf), creditInterestRate(ci) {
}

//i�lem �cretini bakiyeden d��er
void CheckingAccount::chargeFee() {
	Account::debit(transactionFee);
}

//vadeyi bakiyeye ekler ve i�lem �cretini d��er
void CheckingAccount::credit(double amount) {
	Account::credit(amount);
	chargeFee();
}

//miktar� bakiyeden d��er, bakiye eksiye d��erse, i�lem �cretini de bakiyeden d��er
bool CheckingAccount::debit(double amount) {
	bool isPositif = Account::debit(amount);
	if (!isPositif)
		chargeFee();
	return true;
}

//hesap tipini d�nd�r�r
string CheckingAccount::getAccountType() const {
	return "CheckingAccount";
}

//hesap bilgilerini yazd�r�r
void CheckingAccount::print()  const {
	cout << "Hesap Turu: " << getAccountType() << " Islem Ucreti:" << transactionFee << " Gunluk Faiz Orani: " << creditInterestRate << "\n";
	Account::print();
}

//faizi bakiyeden ��kar�r
void CheckingAccount::endOfDay() {
	Account::debit(getBalance()*creditInterestRate / 100);
	cout << "enf of day finished" << "\n";
}

CheckingAccount::~CheckingAccount() {
}