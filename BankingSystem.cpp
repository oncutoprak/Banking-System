// BankingSystem.cpp : Defines the entry point for the console application.
#include "Bank.h"
#include "IndividualCustomer.h"
#include "CommercialCustomer.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"  

int main()
{
	Bank b;
	Customer *cst1;
	cst1 = new IndividualCustomer("Oncu TOPRAK", "Eskisehir/Buyukdere", "oncutoprak05@gmail.com", 23, "Bilgisayar Muhendisi");//yeni müþteri oluþturuluyor
	b.addCustomer(cst1);//bankaya müþteri ekleniyor
	b.createAccount("Oncu TOPRAK", "CheckingAccount");//müþteri için hesap oluþturuluyor

	cst1 = new IndividualCustomer("Tony Stark", "IronMan/Marvel", "tony@starkindustries.com", 51, "Genius, Billionaire, Playboy, Philanthropist");
	b.addCustomer(cst1);
	b.createAccount("Tony Stark", "SavingAccount");

	cst1 = new IndividualCustomer("Bruce Wayne", "Batman/DC", "bruce@wayneenterprice.com", 41, "The Dark Knight");
	b.addCustomer(cst1);
	b.createAccount("Bruce Wayne", "CheckingAccount");

	cst1 = new CommercialCustomer("Clark Kent", "Superman/DC", "clark@kent.com", "The Last Son of The Kripton");//kurumsal müþteri oluþturuluyor
	b.addCustomer(cst1);
	b.createAccount("Clark Kent", "SavingAccount");

	cst1 = new CommercialCustomer("Stark", "IronMan/Marvel", "info@starkindustries.com", "Stark Industries Inc.");
	b.addCustomer(cst1);
	b.createAccount("Stark", "CheckingAccount");

	cst1 = new CommercialCustomer("Wayne", "Batman/DC", "info@wayneenterprice.com", "Wayne Enterprice Inc.");
	b.addCustomer(cst1);
	b.createAccount("Wayne", "SavingAccount");

	b.listCustomers();//müþterileri listeliyoruz
	b.listAccounts();//hesaplarý listeliyoruz

	list<Account*>allAccounts = b.getAllAccounts();//üzerinde iþlem yapmak için tüm hesaplarý getiriyoruz.
	list<Account*>::iterator act;
	act = allAccounts.begin();

	act++;//bir sonraki hesaba gidiyoruz

	(*act)->credit(100);//100 tl ekliyoruz
	(*act)->print();

	act++;//bir sonraki hesaba gidiyoruz

	(*act)->debit(100);//100 tl çýkarýyoruz
	(*act)->print();

	act++;//bir sonraki hesaba gidiyoruz

	(*act)->endOfDay();//gün sonu hesabý
	(*act)->print();

	act++;//bir sonraki hesaba gidiyoruz
	(*act)->setAccountOwner(cst1);//owner ý deðiþtiriyoruz
	act++;//bir sonraki hesaba gidiyoruz

	if ((*act)->getAccountType() == "SavingAccount")
	{
		SavingAccount *sv = (SavingAccount *)(*act);
		sv->calculateInterest();//bu faiz oranýný ekler gün sonunda
		(*act)->endOfDay();//gün sonu hesabý
		(*act)->print();

		b.removeAccount((*act)->getAccountNumber());//bu hesabý çýkart
	}

	system("pause");
}