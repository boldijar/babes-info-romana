#include "StdAfx.h"
#include "string.h"
#include <iostream>
#include "MenuClass.h"
#include "ControllerClass.h"
#include "RepositoryClass.h"
#include "DomainClass.h"

using namespace std;

ControllerClass::ControllerClass(void)
{
}

void ControllerClass::add(int id,int number,float amount,char* type) {
	DomainClass element;
	element.DomainClass::DomainClass(id,number,amount,type);
	
	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.loadFromFlie(lista);
	
	int cautare = findById(element.getId());
	if (cautare == -1 ) {
		lista.append(element);
		rep.saveInFile(lista);
		//lista.~DynamicList();
		cout << "Adaugarea s-a efectuat cu succes" << endl;
		}		
	else
		cout << "Cheltuiala respectiva se afla deja in lista" << endl;
}


/*
	functia incarca in lista elementele din fisier api cauta in lista cheltuiala dupa numar
	daca aceasta cheltuiala este gasita atunci se efectuiaza modificarea, se salveaza in fisier si se printeaza un mesaj
	corespunzator iar daca cheltuiala nu e in lista se printeaza de asemenea un mesaj corespunzator
	*/

void ControllerClass::updateController(int id,int number,float amount,char* type) {
	DomainClass element;
	element = DomainClass::DomainClass(id,number,amount,type);
	
	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.loadFromFlie(lista);
	int cautare = findById(id);
	if (cautare != -1 ) {
		lista.updatePosition(cautare,element);
		rep.saveInFile(lista);
		cout << "Modificarea s-a efectuat cu succes" << endl;
	}
	else
		cout << "Cheltuiala respectiva nu se afla in lista" << endl;
}


/*
	functia incarca in lista elementele din fisier api cauta in lista cheltuiala dupa numar
	daca aceasta cheltuiala este gasita atunci se efectuiaza stergerea, daca nu se afiseaza ca 
	elementul nu e in lista
	*/
void ControllerClass::deleteController(int id) {
	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.loadFromFlie(lista);
	int cautare = findById(id);
	if (cautare != -1 ) {
		lista.deletePosition(cautare);
		rep.saveInFile(lista);
		cout << "Stergerea s-a efectuat cu succes" << endl;
	}
	else
		cout << "Cheltuiala respectiva nu se afla in lista" << endl;
}

/*
	Functie de tipul DomainClass care va returna o lista care contine cheltuielile cu suma mai mare de
	cat suma primita ca parametru

	*/
void ControllerClass::filterAmountController(float suma) {
	DomainClass* filtrate = new DomainClass[100];
	int contor = 0;
	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.loadFromFlie(lista);

	for( int i = 0; i < lista.getLength(); ++i)
		if (lista[i].getAmount() >= suma) {
			contor ++;
			filtrate [contor]  = lista[i];
		}
	for( int i = 1; i <= contor; ++i)
		filtrate[i].print();
		
	delete[] filtrate;
	//lista.~DynamicList();
	cout << endl;		
}

void ControllerClass::filterTypeController(char* tip) {
	DomainClass* filtrate = new DomainClass[100];
	int contor = 0;
	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.loadFromFlie(lista);

	for( int i = 0; i < lista.getLength(); ++i)
		if (strcmp(lista[i].getType(),tip) == 0) {
			contor ++;
			filtrate [contor]  = lista[i];
		}
	for( int i = 1; i <= contor; ++i)
		filtrate[i].print();
	cout << endl;
	delete[] filtrate;
}


void ControllerClass::sortAmountController(DynamicList & lista){
	DomainClass aux,aux1;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.loadFromFlie(lista);
	for (int i = 0;i < lista.getLength()-1; ++i)
		for(int j = i+1; j < lista.getLength(); ++j)
			if (lista[i].getAmount() > lista[j].getAmount())
			{
				aux = lista[i];
				aux1 = lista[j];
				lista.updatePosition(i,aux1);
				lista.updatePosition(j,aux);	
			}
}


void ControllerClass::sortAmountControllerDesc(DynamicList & lista){
	DomainClass aux,aux1;
	
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.loadFromFlie(lista);
	for (int i = 0;i < lista.getLength()-1; ++i)
		for(int j = i+1; j < lista.getLength(); ++j)
			if (lista[i].getAmount() < lista[j].getAmount())
			{
				aux = lista[i];
				aux1 = lista[j];
				lista.updatePosition(i,aux1);
				lista.updatePosition(j,aux);
			}
}

void ControllerClass::sortTypeController(DynamicList & lista){
	
	DomainClass aux,aux1;
	
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.loadFromFlie(lista);
	for (int i = 0;i <= lista.getLength()-1; ++i)
		for(int j = i;j < lista.getLength(); ++j)
			if (strcmp(lista[i].getType(),lista[j].getType()) > 0)
			{
				aux = lista[i];
				aux1 = lista[j];
				lista.updatePosition(i,aux1);
				lista.updatePosition(j,aux);
			}
}


void ControllerClass::sortTypeControllerDesc(DynamicList & lista){
	DomainClass aux,aux1;
	
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.loadFromFlie(lista);
	for (int i = 0;i <= lista.getLength()-1; ++i)
		for(int j = i;j < lista.getLength(); ++j)
			if (strcmp(lista[i].getType(),lista[j].getType()) < 0)
			{
				aux = lista[i];
				aux1 = lista[j];
				lista.updatePosition(i,aux1);
				lista.updatePosition(j,aux);
			}
}


/*
	Functia cauta o cheltuiala dupa numar,daca ea apare ii va return pozitia 
	cheltielii in lista si in caz contrar va returna 0
*/
int ControllerClass::findById(int id) {	
	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.loadFromFlie(lista);

	for (int pozitia = 0;pozitia < lista.getLength(); ++pozitia)
		if(lista[pozitia].getId() == id)
			return pozitia;
	return -1;
	lista.~DynamicList();
}

int ControllerClass::findByType(char* tip) {
	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.loadFromFlie(lista);
	for (int pozitia = 0;pozitia < lista.getLength()  ;++pozitia)
		if(strcmp(lista[pozitia].getType(),tip) == 0)
			return pozitia;
	return -1;
}

ControllerClass::~ControllerClass(void)
{
}
