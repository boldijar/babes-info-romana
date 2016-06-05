#include "StdAfx.h"
#include "Iterator.h"

Iterator::Iterator(void)
{
	this->curent = 0;
}

Iterator::Iterator(MatriceRara* mrr){
	this->m = mrr;
	this->curent = m->lista.prim;
}

void Iterator::urmator(){
	if ( this->curent < m->lista.dimensiune )
		this->curent = m->lista.ListaD[this->curent].urmator;
}

bool Iterator::valid(){
	if(m->lista.ListaD[this->curent].urmator != 0)
		return true;
	return false;
}

Iterator::~Iterator(void)
{
}
