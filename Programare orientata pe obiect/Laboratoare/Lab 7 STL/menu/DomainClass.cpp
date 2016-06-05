#include "StdAfx.h"
#include <iostream>
#include "string.h"
#include "DomainClass.h"

using namespace std;

DomainClass::DomainClass(void){
	this->id = 0;
	this->number = 0;
	this->amount = 0;
	strcpy(this->type,"a");
}

DomainClass::DomainClass(int id,int number,float amount,char* type) {
	this -> id = id;
	this -> number = number;
	this -> amount = amount;
	strcpy(this -> type,type);
}

void DomainClass::setBlock(int number,float amount,char* type) {
	this -> number = number;
	this -> amount = amount;
	strcpy(this -> type,type);
}

void DomainClass::setNumber(int number){
	this->number = number;
}

void DomainClass::setAmount(float amount){
	this->amount = amount;
}

void DomainClass::setType(char* type){
	strcpy(this->type,type);
}

int DomainClass::getId() {
	return this->id;
}

int DomainClass::getNumber() {
	return this->number;
}

float DomainClass::getAmount() {
	return this->amount;
}

char* DomainClass::getType() {
	return this->type;
}

int DomainClass::equal(DomainClass a,DomainClass b) {
	if (DomainClass::getNumber() == DomainClass::getNumber() && DomainClass::getAmount() == DomainClass::getAmount() && DomainClass::getType() == DomainClass::getType())
		return 1;
	return 0;
}

void DomainClass::print() {
	cout << "Id:  " << id <<endl;
	cout << "Number:  " << number <<endl;
	cout << "Amount:  " << amount <<endl;
	cout << "Type:  "<< type << endl;
}


DomainClass::~DomainClass(void){
	this->id = 0;
	this->number = 0;
	this->amount = 0;
	strcpy(this->type,"a");
}
