#include "StdAfx.h"
#include "TElement.h"
#include <string>

TElement::TElement(void)
{ //constructorul incarca fiecare camp al lui TElement cu None
	
	this->cnp = "None";
	this->nume = "None";
	this->prenume = "None";
	
}
TElement::TElement(string cnp,string nume,string prenume)
{ //pre: constructorul primeste 3 valori de tip string
  //post: atribuie fiecarui camp a lui TElement o valoare(o persoana primeste cnp,nume si prenume)
	
	this->cnp = cnp;
	this->nume = nume;
	this->prenume = prenume;
	
}

string TElement::getCNP() {
	//pre: --
	//post: se returneaza cnp-ul clientului
		return this->cnp;
}

string TElement::getNume() {
	//pre: --
	//post: se returneaza numele clientului
	return this->nume;
}

string TElement::getPrenume() {
	//pre: --
	//post: se returneaza prenumele clientului
	return this->prenume;
}

void TElement::setCNP(string cnp) {
	//pre: functia primeste un string cnp
	//post: functia seteaza cnp_ul clientului cu stringul primit
	this->cnp = cnp;
}

void TElement::setNume(string nume) {
	//pre: functia primeste un string nume
	//post: functia seteaza numele clientului cu stringul primit
	this->nume = nume;
}

void TElement::setPrenume(string prenume) {
	//pre: functia primeste un string prenume
	//post: functia seteaza prenumele clientului cu stringul primit
	this->prenume = prenume;
}

int TElement::hashCode() {
	//hash code va fi optinut din suma tuturor cifrelor din CNP 
	int code = 0;
	for(size_t i = 0; i < this->cnp.length(); ++i)
		code += this->cnp[i] - 48; //scad din codul ascii al unei cifre 48 si optin chiar cifa

	return code;
}
void TElement::print() {
	//pre: --
	//post: functia print permite afisarea unui element de tip client cu toate campurile sale
	cout << "CNP:" << " " << this->cnp << endl;
	cout << "Nume:" << " " << this->nume << endl;
	cout << "Prenume:" << " " << this->prenume << endl << endl;
	
}
TElement::~TElement(void)
{
	this->cnp = "None";
	this->nume = "None";
	this->prenume = "None";
}
