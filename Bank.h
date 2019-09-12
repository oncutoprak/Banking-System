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
	string bankName;//banka adý
	string bankID;//banka Idsi
	list<Account *> accounts;//bankadaki hesap listesi
	vector<Customer *> customers;//bankadaki müþterilerin listesi
public:
	Bank();
	bool createAccount(string customerName, string accountType);//verilen müþteriye yeni hesap ekler
	bool addCustomer(Customer *customer);//yeni müþteri ekler
	void listAccounts();//bankadaki hesaplarý listeler
	void listCustomers();//bankadaki müþterileri listeler
	bool removeAccount(double accountNumber);
	list<Account *> getAllAccounts();//tüm hesaplari döndürür
	static long generateAccountNumber();//rastgele hesap numarasý üretiyor
	static double generateFirstMoney();//balance deðeri için baþlangýçta rastgele para üretiyor
	static double generateIslemUcreti();//transactionFee için rastgele deðer üretiyor
	static double generateFaizOrani();//creditInterestRate ve interestRate için rastgele deðer üretiyor
	~Bank();
};
#endif