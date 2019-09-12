#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer() {
}

Customer::Customer(string nm, string ad, string em) :name(nm), address(ad), email(em) {
}

//m��teri parametrelerini yazd�r�r
void Customer::print()  const {
	cout << "Name:" << name << " Address: " << address << " Email: " << email << "\n_______________________\n";
}

//hesap numaras�n� m��teri hesaplar� ile kar��la�t�r�r ve varsa o hesab� d�nd�r�r
Account *Customer::getAccount(long accountNumber) const {

	for (int i = 0; i < accounts.size(); i++)
	{
		if (accountNumber == accounts[i]->getAccountNumber())
			return accounts[i];
	}
}

//bireysel ya da kurumsal m��teri tipini d�nd�r�r
string Customer::getCustomerType()  const {
	return "";
}

//yeni hesap numaras� ekler
bool Customer::addNewAccount(Account *account) {
	accounts.push_back(account);
	return true;
}

//m��teri ad�n� d�nd�r�r
string Customer::getCustomerName() const {
	return name;
}

Customer::~Customer() {
}