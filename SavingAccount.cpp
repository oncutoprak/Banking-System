#include "SavingAccount.h"

SavingAccount::SavingAccount() {
}

SavingAccount::SavingAccount(double b, long a, Customer *o, double ir) :Account(b, a, o), interestRate(ir) {
}

//faiz hesaplar
double SavingAccount::calculateInterest() {
	return getBalance()*interestRate / 100;
}

//hesap tipini döndürür
string SavingAccount::getAccountType()  const {
	return "SavingAccount";
}

//miktar bakiyeden büyükse çýkarýr
bool SavingAccount::debit(double amt) {
	if (getBalance() >= amt)
	{
		Account::debit(amt);
		return true;
	}
	return false;
}

//class üyelerini yazdýrýr
void SavingAccount::print() const {
	cout << "Hesap Turu : " << getAccountType() << " Interest Rate :" << interestRate << "\n";
	Account::print();
}

//Gün sonunda faizi bakiyeye ekler
void SavingAccount::endOfDay() {
	credit(calculateInterest());
	cout << "enf of day finished" << "\n";
}

SavingAccount::~SavingAccount() {
}