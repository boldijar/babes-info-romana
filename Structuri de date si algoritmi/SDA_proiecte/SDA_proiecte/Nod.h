#pragma once
#include "IElem.h"
class Nod
{

public:
	IElem* info;
	Nod* next;

	Nod() : info(0), next(0) {}
	Nod(IElem* e, Nod* n) : info(e), next(n) {} 
	Nod(IElem* e) : info(e), next(0) {}
	Nod(const Nod& n) : info(n.info), next(n.next) {}
	~Nod() {}


	friend class Lista;
}; 

