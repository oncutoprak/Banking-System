#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include <algorithm>
#include "Account.h"
using namespace std;

class Account;

class Customer
{
private:
	string name;//müþteri adý
	string address;//müþteri adresi
	string email;//müþteri emaili
	vector<Account *> accounts;//müþterinin hesaplarýnýn listesi
public:
	Customer();
	Customer(string name, string address, string email);
	virtual void print() const;//müþteri parametrelerini yazdýrýr
	virtual Account *getAccount(long accountNumber) const;//hesap numarasýný müþteri hesaplarý ile karþýlaþtýrýr ve varsa o hesabý döndürür
	virtual string getCustomerType() const;//bireysel ya da kurumsal müþteri tipini döndürür
	virtual bool addNewAccount(Account *account);//yeni hesap numarasý ekler
	virtual string getCustomerName() const;//müþteri adýný döndürür
	~Customer();
};
#endif