#include "Bank.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include <time.h>    
#include <conio.h>
#include <iostream>
using namespace std;

Bank::Bank() {
}

//verilen m��teriye yeni hesap ekler
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

//yeni m��teri ekler
bool Bank::addCustomer(Customer *customer) {
	customers.push_back(customer);
	return true;
}

//bankadaki hesaplar� listeler
void Bank::listAccounts() {
	cout << "**************Accounts:*****************\n";
	list<Account *>::iterator acts;
	for (acts = accounts.begin(); acts != accounts.end(); ++acts)
	{
		(*acts)->print();
	}
}

//bankadaki m��terileri listeler
void Bank::listCustomers() {
	cout << "**************Customers:*****************\n";
	for (int i = 0; i < customers.size(); i++)
	{
		customers[i]->print();
	}
}

//verilen hesab� ��kar�r
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

//rastgele hesap numaras� �retiyor
long Bank::generateAccountNumber() {
	return	rand() % 9000000000 + 1000000000;
}

//balance de�eri i�in ba�lang��ta rastgele para �retiyor
double Bank::generateFirstMoney() {
	return	rand() % 1000 + 100000;
}

//transactionFee i�in rastgele de�er �retiyor
double Bank::generateIslemUcreti() {

	return	rand() % 10 + 100;
}

//creditInterestRate ve interestRate i�in rastgele de�er �retiyor
double Bank::generateFaizOrani() {

	return	rand() % 5 + 1;
}

//composition gere�i destractorda sahip oldu�u nesneler yok ediliyor.
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