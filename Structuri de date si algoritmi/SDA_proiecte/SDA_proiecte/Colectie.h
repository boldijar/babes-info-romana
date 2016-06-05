#pragma once
#include "IColectie.h"
#include "IElem.h"
#include "Nod.h"
#include "Integer.h"

class Colectie : public IColectie
{
public:
	int cap;
	int nr_elem;
	Nod* buckets[15];

public:
	void add(IElem*);
	void print();
	int hash(IElem*);
	int remove(IElem*);
	int getNr_elem();
	int search(IElem*);

	Colectie();
	~Colectie();
};

