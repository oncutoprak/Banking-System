#pragma once
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"

class CheckingAccount : public Account
{//vadesiz hesap
private:
	double transactionFee;//iþlem ücreti
	double creditInterestRate;//günlük faiz oraný
	void chargeFee();//iþlem ücretini bakiyeden düþer
public:
	CheckingAccount();
	CheckingAccount(double balance, long accountNumber, Customer *owner, double transactionFee, double creditInterestRate);
	void credit(double amount);//vadeyi bakiyeye ekler ve iþlem ücretini düþer
	bool debit(double amount);//miktarý bakiyeden düþer, bakiye eksiye düþerse, iþlem ücretini de bakiyeden düþer
	string getAccountType() const;//hesap tipini döndürür
	void print() const;//hesap bilgilerini yazdýrýr
	void endOfDay();//faizi bakiyeden çýkarýr
	~CheckingAccount();
};
#endif