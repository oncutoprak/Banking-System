#pragma once
#ifndef COMMERCIALCUSTOMER_H
#define COMMERCIALCUSTOMER_H
#include "Customer.h"

//kurumsal m��teri
class CommercialCustomer : public Customer
{
private:
	string bussinesName;
public:
	CommercialCustomer();
	CommercialCustomer(string name, string address, string email, string bussinesName);
	void print() const;//Firma ad�n� yazd�r�r, Customer Printi de �a��r�r.
	~CommercialCustomer();
};
#endif