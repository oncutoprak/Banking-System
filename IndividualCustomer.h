#pragma once
#ifndef INDIVIDUALCUSTOMER_H
#define INDIVIDUALCUSTOMER_H
#include "Customer.h"
#include <iostream>
using namespace std;

//bireysel müþteri
class IndividualCustomer : public Customer
{
private:
	int age;
	string title;
public:
	IndividualCustomer();
	IndividualCustomer(string name, string address, string email, int age, string title);
	void print() const;//Müþteri unvanýný ve yaþýný yazdýrýr, Customer Printi de çaðýrýr.
	~IndividualCustomer();
};
#endif