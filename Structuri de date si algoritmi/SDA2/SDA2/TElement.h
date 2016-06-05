#pragma once
#include <iostream>
using namespace std;
class TElement
{
public:
	private:
	string cnp;
	string nume;
	string prenume;
public:
	TElement(void);
	TElement(string,string,string);
	string getCNP();
	string getNume();
	string getPrenume();
	void setCNP(string);
	void setNume(string);
	void setPrenume(string);
	int hashCode();
	void print();
	~TElement(void);
};

