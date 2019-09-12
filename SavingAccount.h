#pragma once
#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include <iostream>
#include "Account.h"
using namespace std;

//vadeli hesap
class SavingAccount : public Account
{
private:
	double interestRate;//bakiye için günlük faiz oraný
public:
	SavingAccount();
	SavingAccount(double balance, long accountNumber, Customer *owner, double interestRate);
	double calculateInterest();//faiz hesaplar
	string getAccountType() const;//hesap tipini döndürür
	bool debit(double amount);//miktar bakiyeden büyükse çýkarýr
	void print() const;//class üyelerini yazdýrýr
	void endOfDay();//faizi bakiyeye ekler
	~SavingAccount();
};
#endif