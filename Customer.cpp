#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer() {
}

Customer::Customer(string nm, string ad, string em) :name(nm), address(ad), email(em) {
}

//müþteri parametrelerini yazdýrýr
void Customer::print()  const {
	cout << "Name:" << name << " Address: " << address << " Email: " << email << "\n_______________________\n";
}

//hesap numarasýný müþteri hesaplarý ile karþýlaþtýrýr ve varsa o hesabý döndürür
Account *Customer::getAccount(long accountNumber) const {

	for (int i = 0; i < accounts.size(); i++)
	{
		if (accountNumber == accounts[i]->getAccountNumber())
			return accounts[i];
	}
}

//bireysel ya da kurumsal müþteri tipini döndürür
string Customer::getCustomerType()  const {
	return "";
}

//yeni hesap numarasý ekler
bool Customer::addNewAccount(Account *account) {
	accounts.push_back(account);
	return true;
}

//müþteri adýný döndürür
string Customer::getCustomerName() const {
	return name;
}

Customer::~Customer() {
}