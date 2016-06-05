#include "StdAfx.h"
#include "Iterator.h"
class TElement;

Iterator::Iterator(Multime *mu )
{
	this->curent = 0;
	m = mu;
	

}

Iterator::Iterator(void)
{
	this->curent = 0;
	
}

bool Iterator::urmator(){
	/*functia urmator returneaza valoarea true si face incrementarea valorii curent daca se poate face
	  acest lucru
	  -daca nu se poate incrementa curent se va returna valoarea false
	*/
	if ( this->curent < m->numarDispersie - 1 ) {
		this->curent++;
		return true;
	}
	else
		return false;
}

TElement Iterator::element() {
	//functia element returneaza elementul de pe pozitia curenta
	if (this->curent < m->numarDispersie)
		return this->m->mult[curent];
}

bool Iterator::valid() {
	//functia valid verifica daca o pozitie este valida
	//functia va returna true daca pozitia este valida(elementul se afla in tabla si e diferit de None sau Sters)
	//si se returneaza false daca elementul este invalid
	if (this->curent < m->numarDispersie)	
		if (this->m->mult[this->curent].getCNP().compare("None")==0 || this->m->mult[this->curent].getCNP().compare("Sters")==0 )
			return false;

	return true;
}


Iterator::~Iterator(void)
{
	this->curent = 0;
	
}
