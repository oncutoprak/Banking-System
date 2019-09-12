#include "CheckingAccount.h"

CheckingAccount::CheckingAccount() {
}

CheckingAccount::CheckingAccount(double b, long a, Customer *o, double tf, double ci) :Account(b, a, o), transactionFee(tf), creditInterestRate(ci) {
}

//iþlem ücretini bakiyeden düþer
void CheckingAccount::chargeFee() {
	Account::debit(transactionFee);
}

//vadeyi bakiyeye ekler ve iþlem ücretini düþer
void CheckingAccount::credit(double amount) {
	Account::credit(amount);
	chargeFee();
}

//miktarý bakiyeden düþer, bakiye eksiye düþerse, iþlem ücretini de bakiyeden düþer
bool CheckingAccount::debit(double amount) {
	bool isPositif = Account::debit(amount);
	if (!isPositif)
		chargeFee();
	return true;
}

//hesap tipini döndürür
string CheckingAccount::getAccountType() const {
	return "CheckingAccount";
}

//hesap bilgilerini yazdýrýr
void CheckingAccount::print()  const {
	cout << "Hesap Turu: " << getAccountType() << " Islem Ucreti:" << transactionFee << " Gunluk Faiz Orani: " << creditInterestRate << "\n";
	Account::print();
}

//faizi bakiyeden çýkarýr
void CheckingAccount::endOfDay() {
	Account::debit(getBalance()*creditInterestRate / 100);
	cout << "enf of day finished" << "\n";
}

CheckingAccount::~CheckingAccount() {
}