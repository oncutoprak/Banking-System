#pragma once
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"

class CheckingAccount : public Account
{//vadesiz hesap
private:
	double transactionFee;//i�lem �creti
	double creditInterestRate;//g�nl�k faiz oran�
	void chargeFee();//i�lem �cretini bakiyeden d��er
public:
	CheckingAccount();
	CheckingAccount(double balance, long accountNumber, Customer *owner, double transactionFee, double creditInterestRate);
	void credit(double amount);//vadeyi bakiyeye ekler ve i�lem �cretini d��er
	bool debit(double amount);//miktar� bakiyeden d��er, bakiye eksiye d��erse, i�lem �cretini de bakiyeden d��er
	string getAccountType() const;//hesap tipini d�nd�r�r
	void print() const;//hesap bilgilerini yazd�r�r
	void endOfDay();//faizi bakiyeden ��kar�r
	~CheckingAccount();
};
#endif