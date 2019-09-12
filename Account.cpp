#include "Account.h"

Account::Account() {
}

Account::Account(double b, long a, Customer *o) :balance(b), accountNumber(a) {
	owner = o;
}

//vadeyi bakiyeye ekler
void Account::credit(double amount) {
	balance += amount;
}

//borcu bakiyeden ��kar�r, positif ise geriye true d�nd�r�r
bool Account::debit(double amount) {
	balance -= amount;
	if (balance < 0)
		return false;
	else return true;
}

//pure virtual fonksiyon;miras al�nan classda vadesiz hesap ya da vadeli hesap oldu�unu d�nd�r�r
string Account::getAccountType() const {
	return "";
}

//account �yelerini yazd�r�r
void Account::print() const {
	cout << "Account Number: " << accountNumber << " Balance : " << balance << " Owner:" << owner->getCustomerName() << "\n___________________________\n";
}

//pure virtual fonksiyon;balance'dan faizi ekler ya da ��kar�r
void Account::endOfDay() {

}

//verilen m��teriyi ilgili hesab�n sahibi olarak atar
bool Account::setAccountOwner(Customer *_owner) {
	owner = _owner;
	return true;
}

long Account::getAccountNumber() const {
	return accountNumber;
}

double Account::getBalance() const {
	return balance;
}

Account::~Account() {
}