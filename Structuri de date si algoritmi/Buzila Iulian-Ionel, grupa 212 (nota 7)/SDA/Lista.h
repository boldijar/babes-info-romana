#pragma once
#include "TElement.h"
#define dim 50

struct TNod {
		TElement data;
		int urmator;
		int precedent;
	};

class Lista
{
public:
	struct TNod ListaD[dim];
	int ultim;
	int primLiber;
	int prim;
	int dimensiune;

	Lista();

	void afisare();
	void cautaPrimLiber();
	void adauga(TElement elem);
	void adaugaDupa(TElement,TElement);
	void sterge(TElement);
	bool listaVida();
	
	~Lista(void);
};

