#include "StdAfx.h"

#include <iostream>
#include "string.h"

using namespace std;
#include "DomainClass.h"


DomainClass::DomainClass(void)
{		this->id = 0;
		this->number = 0;
		this->amount = 0;
		strcpy(this->type,"a");
}

DomainClass::DomainClass(int id,int number,float amount,char* type) {

		//: number(number)
		//, amount(amount)
		//, type(type)
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

int DomainClass::GetId() {
	return this->id;

}

int DomainClass::GetNumber() {
	return this->number;

}
float DomainClass::GetAmount() {

		return this->amount;
	}

char* DomainClass::GetType() {

	return this->type;

}
int DomainClass::Equal(DomainClass a,DomainClass b) {
	if (DomainClass::GetNumber() == DomainClass::GetNumber() && DomainClass::GetAmount() == DomainClass::GetAmount() && DomainClass::GetType() == DomainClass::GetType())
		return 1;
	return 0;
}
void DomainClass::Print() {

	cout << "Id:  " << id <<endl;
	cout << "Number:  " << number <<endl;
	cout << "Amount:  " << amount <<endl;
	cout << "Type:  "<< type << endl;

}


DomainClass::~DomainClass(void)
{		
	    id = 0;
		number = 0;
		amount = 0;
		strcpy(type , " ");
}

