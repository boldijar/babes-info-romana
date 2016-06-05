#pragma once
//#include "Iterator.h"

//const int DIM = 20;
const int DIM2 = 30;

class Iterator;
class Multime
{
	


public:
	
	TElement *mult;
	int numarDispersie;
	Multime(void);
	int dispersie(TElement,int);
	void adauga(TElement);
	int cauta(string);
	void sterge(string);
	int dimensiune();
	bool vida();
	Iterator Itr();

	~Multime(void);
};
