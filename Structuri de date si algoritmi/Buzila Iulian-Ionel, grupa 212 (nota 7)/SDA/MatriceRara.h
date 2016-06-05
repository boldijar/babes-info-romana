#pragma once
#include "Lista.h"
#include "TElement.h"
#include "Iterator.h"

class Iterator;
class MatriceRara
{
public:
	MatriceRara();
	friend class Iterator;
	Lista lista;
	TElement cauta(TElement);
	void adaugaMatrice(TElement);
	void afisareMatrice();
	int getValoare(int,int);
	void modificareMatrice(TElement, int);
	void stergeMatrice(TElement);
	Iterator* Itr();
	~MatriceRara(void);
};

