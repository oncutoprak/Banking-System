#include "IndividualCustomer.h"
#include <iostream>
#include <string>
using namespace std;

IndividualCustomer::IndividualCustomer() {
}

IndividualCustomer::IndividualCustomer(string nm, string ad, string em, int ag, string tl) :Customer(nm, ad, em), age(ag), title(tl) {
}

//Müþteri unvanýný ve yaþýný yazdýrýr, Customer Printi de çaðýrýr.
void IndividualCustomer::print() const {
	cout << "Title : " << title << " Age : " << age << "\n";
	Customer::print();
}

IndividualCustomer::~IndividualCustomer()
{
}