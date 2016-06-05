#pragma once
#include "StdAfx.h"
class Controller
{
private:
	
	Iterator it;
	Multime mu;
public:
	

	Controller(void);

	void adaugaController(string,string,string);
	int cautaController(string);
	void stergeController(string);
	void afisareDupaSex(int);
	void afisareDupaJudet(char * );
	void afisareDupaSex(char * );
	void afisareTot();

	
	~Controller(void);
};

