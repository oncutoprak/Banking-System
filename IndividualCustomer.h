#pragma once
#ifndef INDIVIDUALCUSTOMER_H
#define INDIVIDUALCUSTOMER_H
#include "Customer.h"
#include <iostream>
using namespace std;

//bireysel m��teri
class IndividualCustomer : public Customer
{
private:
	int age;
	string title;
public:
	IndividualCustomer();
	IndividualCustomer(string name, string address, string email, int age, string title);
	void print() const;//M��teri unvan�n� ve ya��n� yazd�r�r, Customer Printi de �a��r�r.
	~IndividualCustomer();
};
#endif