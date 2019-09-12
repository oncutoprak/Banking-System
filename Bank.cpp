#include "Bank.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include <time.h>    
#include <conio.h>
#include <iostream>
using namespace std;

Bank::Bank() {
}

//verilen müþteriye yeni hesap ekler
bool Bank::createAccount(string customerName, string accountType) {

	for (int i = 0; i < customers.size(); i++)
	{
		if (customerName == customers[i]->getCustomerName())
		{
			Account *act;
			if (accountType == "SavingAccount")
			{
				act = new SavingAccount(Bank::generateFirstMoney(), Bank::generateAccountNumber(), customers[i], Bank::generateFaizOrani());
				customers[i]->addNewAccount(act);
				accounts.push_back(act);
			}
			else
			{
				act = new CheckingAccount(Bank::generateFirstMoney(), Bank::generateAccountNumber(), customers[i], Bank::generateIslemUcreti(), Bank::generateFaizOrani());
				customers[i]->addNewAccount(act);
				accounts.push_back(act);
			}
		}

	}
	return true;
}

//yeni müþteri ekler
bool Bank::addCustomer(Customer *customer) {
	customers.push_back(customer);
	return true;
}

//bankadaki hesaplarý listeler
void Bank::listAccounts() {
	cout << "**************Accounts:*****************\n";
	list<Account *>::iterator acts;
	for (acts = accounts.begin(); acts != accounts.end(); ++acts)
	{
		(*acts)->print();
	}
}

//bankadaki müþterileri listeler
void Bank::listCustomers() {
	cout << "**************Customers:*****************\n";
	for (int i = 0; i < customers.size(); i++)
	{
		customers[i]->print();
	}
}

//verilen hesabý çýkarýr
bool Bank::removeAccount(double accountNumber) {
	list<Account *>::iterator acts;
	for (acts = accounts.begin(); acts != accounts.end(); acts++)
	{
		if (accountNumber == (*acts)->getAccountNumber())
		{
			accounts.remove(*acts);
			return true;
		}
	}
	return false;
}

list<Account *> Bank::getAllAccounts() {
	return accounts;
}

//rastgele hesap numarasý üretiyor
long Bank::generateAccountNumber() {
	return	rand() % 9000000000 + 1000000000;
}

//balance deðeri için baþlangýçta rastgele para üretiyor
double Bank::generateFirstMoney() {
	return	rand() % 1000 + 100000;
}

//transactionFee için rastgele deðer üretiyor
double Bank::generateIslemUcreti() {

	return	rand() % 10 + 100;
}

//creditInterestRate ve interestRate için rastgele deðer üretiyor
double Bank::generateFaizOrani() {

	return	rand() % 5 + 1;
}

//composition gereði destractorda sahip olduðu nesneler yok ediliyor.
Bank::~Bank() {

	for (int i = 0; i < customers.size(); i++)
	{
		delete customers[i];
	}
	list<Account*>::iterator iter;
	for (iter = accounts.begin(); iter != accounts.end(); iter++)
	{
		delete *iter;

	}
}