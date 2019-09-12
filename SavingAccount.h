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
	double interestRate;//bakiye i�in g�nl�k faiz oran�
public:
	SavingAccount();
	SavingAccount(double balance, long accountNumber, Customer *owner, double interestRate);
	double calculateInterest();//faiz hesaplar
	string getAccountType() const;//hesap tipini d�nd�r�r
	bool debit(double amount);//miktar bakiyeden b�y�kse ��kar�r
	void print() const;//class �yelerini yazd�r�r
	void endOfDay();//faizi bakiyeye ekler
	~SavingAccount();
};
#endif