#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Customer.h"
#include <iostream>
using namespace std;

class Customer;

class Account
{
private:
	double balance;//bakiye miktarý
	long accountNumber;//hesap numarasý
	Customer *owner;//hesap sahibi
public:
	Account();
	Account(double balance, long accountNumber, Customer *owner);
	virtual void credit(double amount);//vadeyi bakiyeye ekler
	virtual bool debit(double amount);//borcu bakiyeden çýkarýr, positifse geriye true döndürür
	virtual string getAccountType() const = 0;//pure virtual fonksiyon;miras alýnan classda vadesiz hesap ya da vadeli hesap olduðunu döndürür
	virtual void print() const;//account üyelerini yazdýrýr
	virtual void endOfDay() = 0;//pure virtual fonksiyon;balance'dan faizi ekler ya da çýkarýr
	virtual bool setAccountOwner(Customer *_owner);//verilen müþteriyi ilgili hesabýn sahibi olarak atar
	virtual long getAccountNumber() const;
	virtual double getBalance() const;
	~Account();
};
#endif