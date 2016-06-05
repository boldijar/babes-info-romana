#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "Ielem.h"
using namespace std;

class Integer : public IElem
{
	int value;

public:
	Integer();
	Integer(const Integer&);
	Integer(int);

	int getValue();
	void setValue(int);
	void print();

	char* toString();
	int comparesTo(IElem*);

	ostream& operator << (ostream& stream);
	istream& operator >> (istream& stream);

	~Integer();
};

