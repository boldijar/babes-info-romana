#include "StdAfx.h"
#include "TElement.h"
#include<iostream>

using namespace std;

TElement::TElement(void)
{
	this->linie=0;
	this->coloana=0;
	this->valoare=0;
}

TElement::TElement(int linie, int coloana, int valoare)
{
	this->linie=linie;
	this->coloana=coloana;
	this->valoare=valoare;
}


int TElement::getLinie(){
	return this->linie;
}

int TElement::getColoana(){
	return this->coloana;
}

int TElement::getValoare(){
	return this->valoare;
}


void TElement::setLinie(int val){
	this->linie = val;
}

void TElement::setColoana(int val){
	this->coloana = val;
}

void TElement::setValoare(int val){
	this->valoare = val;
}


void TElement::print(){
	cout << "<" << this->linie << "  " << this->coloana << "  " << this->valoare << ">" << "\n";
}



TElement::~TElement(void)
{
	this->linie=0;
	this->coloana=0;
	this->valoare=0;

}
