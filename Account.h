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
	double balance;//bakiye miktar�
	long accountNumber;//hesap numaras�
	Customer *owner;//hesap sahibi
public:
	Account();
	Account(double balance, long accountNumber, Customer *owner);
	virtual void credit(double amount);//vadeyi bakiyeye ekler
	virtual bool debit(double amount);//borcu bakiyeden ��kar�r, positifse geriye true d�nd�r�r
	virtual string getAccountType() const = 0;//pure virtual fonksiyon;miras al�nan classda vadesiz hesap ya da vadeli hesap oldu�unu d�nd�r�r
	virtual void print() const;//account �yelerini yazd�r�r
	virtual void endOfDay() = 0;//pure virtual fonksiyon;balance'dan faizi ekler ya da ��kar�r
	virtual bool setAccountOwner(Customer *_owner);//verilen m��teriyi ilgili hesab�n sahibi olarak atar
	virtual long getAccountNumber() const;
	virtual double getBalance() const;
	~Account();
};
#endif