#pragma once
#ifndef BANK_H
#define BANK_H
#include <iostream>
#include "Customer.h"
#include "Account.h"
#include <list>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

class Account;
class Customer;

class Bank
{
private:
	string bankName;//banka ad�
	string bankID;//banka Idsi
	list<Account *> accounts;//bankadaki hesap listesi
	vector<Customer *> customers;//bankadaki m��terilerin listesi
public:
	Bank();
	bool createAccount(string customerName, string accountType);//verilen m��teriye yeni hesap ekler
	bool addCustomer(Customer *customer);//yeni m��teri ekler
	void listAccounts();//bankadaki hesaplar� listeler
	void listCustomers();//bankadaki m��terileri listeler
	bool removeAccount(double accountNumber);
	list<Account *> getAllAccounts();//t�m hesaplari d�nd�r�r
	static long generateAccountNumber();//rastgele hesap numaras� �retiyor
	static double generateFirstMoney();//balance de�eri i�in ba�lang��ta rastgele para �retiyor
	static double generateIslemUcreti();//transactionFee i�in rastgele de�er �retiyor
	static double generateFaizOrani();//creditInterestRate ve interestRate i�in rastgele de�er �retiyor
	~Bank();
};
#endif