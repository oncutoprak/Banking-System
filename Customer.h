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
	string name;//m��teri ad�
	string address;//m��teri adresi
	string email;//m��teri emaili
	vector<Account *> accounts;//m��terinin hesaplar�n�n listesi
public:
	Customer();
	Customer(string name, string address, string email);
	virtual void print() const;//m��teri parametrelerini yazd�r�r
	virtual Account *getAccount(long accountNumber) const;//hesap numaras�n� m��teri hesaplar� ile kar��la�t�r�r ve varsa o hesab� d�nd�r�r
	virtual string getCustomerType() const;//bireysel ya da kurumsal m��teri tipini d�nd�r�r
	virtual bool addNewAccount(Account *account);//yeni hesap numaras� ekler
	virtual string getCustomerName() const;//m��teri ad�n� d�nd�r�r
	~Customer();
};
#endif