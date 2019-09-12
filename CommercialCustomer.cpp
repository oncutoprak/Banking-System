#include "CommercialCustomer.h"
#include <iostream>
#include <string>
using namespace std;

CommercialCustomer::CommercialCustomer() {
}

CommercialCustomer::CommercialCustomer(string nm, string ad, string em, string bs) :Customer(nm, ad, em), bussinesName(bs) {
}

//Firma ad�n� yazd�r�r, Customer Printi de �a��r�r.
void CommercialCustomer::print()  const {
	cout << "Bussines Name : " << bussinesName << "\n";
	Customer::print();
}

CommercialCustomer::~CommercialCustomer() {
}