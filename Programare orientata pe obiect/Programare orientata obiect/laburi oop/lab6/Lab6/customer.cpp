#include "customer.h"

#include <cstring>

Customer::~Customer(){
	delete[] address;
}

Customer::Customer(char* paddress,int pphone){
	address = new char[strlen(paddress)+1];
	strcpy(address,paddress);
	phone=pphone;
}

Customer::Customer(const Customer& from){
	address = new char[strlen(from.address)+1];
	strcpy(address,from.address);
	phone = from.phone;
}

void Customer::operator=(Customer& from){
	delete[] address;
	address = new char[strlen(from.address)+1];
	strcpy(address,from.address);
	phone = from.phone;
}

bool Customer::operator==(Customer& from){
	return phone==from.phone && strcmp(address,from.address)==0;
}

bool Customer::operator>(Customer& from){
	return phone>from.phone;
}

bool Customer::operator<(Customer& from){
	return phone<from.phone;
}

bool Customer::operator>=(Customer& from){
	return phone>=from.phone;
}

bool Customer::operator<=(Customer& from){
	return phone<=from.phone;
}

std::ostream& operator<<(std::ostream& os, Customer& r){
	os<<r.phone<<':'<<r.address;
}
std::istream& operator>>(std::istream& os, Customer& r){
	os>>r.phone;
	char line[1024];
	os.getline(line,1023);
	delete[] r.address;
	r.address = new char[strlen(line)+1];
	strcpy(r.address,line);
}
