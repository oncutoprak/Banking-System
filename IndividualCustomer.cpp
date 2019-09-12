#include "IndividualCustomer.h"
#include <iostream>
#include <string>
using namespace std;

IndividualCustomer::IndividualCustomer() {
}

IndividualCustomer::IndividualCustomer(string nm, string ad, string em, int ag, string tl) :Customer(nm, ad, em), age(ag), title(tl) {
}

//M��teri unvan�n� ve ya��n� yazd�r�r, Customer Printi de �a��r�r.
void IndividualCustomer::print() const {
	cout << "Title : " << title << " Age : " << age << "\n";
	Customer::print();
}

IndividualCustomer::~IndividualCustomer()
{
}