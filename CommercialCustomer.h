#pragma once
#ifndef COMMERCIALCUSTOMER_H
#define COMMERCIALCUSTOMER_H
#include "Customer.h"

//kurumsal müþteri
class CommercialCustomer : public Customer
{
private:
	string bussinesName;
public:
	CommercialCustomer();
	CommercialCustomer(string name, string address, string email, string bussinesName);
	void print() const;//Firma adýný yazdýrýr, Customer Printi de çaðýrýr.
	~CommercialCustomer();
};
#endif