#include "StdAfx.h"
#include "string.h"
#include <iostream>
#include <algorithm>
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
	element=DomainClass(id,number,amount,type);
	
	vector<DomainClass>  lista;
	RepositoryClass rep;
	rep.loadFromFlie(lista);
	
	int cautare = findById(element.getId());
	if (cautare == -1 ) {		
			lista.push_back(element);
			rep.saveInFile(lista);
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
	vector<DomainClass>  lista; 
	RepositoryClass rep;
	rep.loadFromFlie(lista);
	int cautare = findById(id);
	if (cautare != -1 ) {
		lista[cautare].setNumber(number);
		lista[cautare].setAmount(amount);
		lista[cautare].setType(type);
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
	std::vector<DomainClass> lista;
	RepositoryClass rep;

	rep.loadFromFlie(lista);
	int cautare = findById(id);
	if (cautare != -1 ) {

		lista.erase(lista.begin()+cautare);
		rep.saveInFile(lista);	
		cout << "Stergerea s-a efectuat cu succes" << endl;
	}
	else
		cout << "Cheltuiala respectiva nu se afla in lista" << endl;
}


/*
	Functia va tiparii cheltuielile cu o suma mai mare de cat un data

	*/
void ControllerClass::filterAmountController(float suma) {
	std::vector<DomainClass> lista;
	RepositoryClass rep;
	rep.loadFromFlie(lista);

	for (std::vector<DomainClass>::iterator i = lista.begin() ; i != lista.end(); ++i)
		if ((*i).getAmount() >= suma) {
			(*i).print();
			cout << endl;
		}
}
void ControllerClass::filterTypeController(char* tip) {
	std::vector<DomainClass> lista;
	RepositoryClass rep ;
	rep.loadFromFlie(lista);

	for (std::vector<DomainClass>::iterator i = lista.begin() ; i != lista.end(); ++i)
		if (strcmp((*i).getType(),tip) == 0) {
			(*i).print();
			cout<<endl;
		}
}

struct byAmount {
	bool operator() (DomainClass i,DomainClass j) { return (i.getAmount()<j.getAmount());}
} sortAmount;

void ControllerClass::sortAmountController(std::vector<DomainClass> & lista){
	RepositoryClass rep ;
	rep.loadFromFlie(lista);
	std::sort (lista.begin(), lista.end(),sortAmount); 
}

void ControllerClass::sortAmountControllerDesc(std::vector<DomainClass> & lista){
	RepositoryClass rep ;
	rep.loadFromFlie(lista);
	std::sort (lista.begin(), lista.end(),sortAmount); 
	std::reverse ( lista.begin(), lista.end());
}

struct byType {
	bool operator() (DomainClass i,DomainClass j) { return (strcmp(i.getType(), j.getType())<0);}
} sortType;

void ControllerClass::sortTypeController(std::vector<DomainClass> & lista){	
	RepositoryClass rep ;
	rep.loadFromFlie(lista);
	std::sort (lista.begin(), lista.end(),sortType); 
}

void ControllerClass::sortTypeControllerDesc(std::vector<DomainClass>  & lista){
	RepositoryClass rep ;
	rep.loadFromFlie(lista);
	std::sort (lista.begin(), lista.end(),sortType); 
	std:reverse ( lista.begin(), lista.end());
}

int ControllerClass::findById(int id) {
	/*
	Functia cauta o cheltuiala dupa numar,daca ea apare ii va return pozitia 
	cheltielii in lista si in caz contrar va returna 0
	*/
	std::vector<DomainClass> lista;
	RepositoryClass rep ;
	rep.loadFromFlie(lista);

	for (int pozitia = 0;pozitia < lista.size()  ;++pozitia)
		if(lista[pozitia].getId() == id)
			return pozitia;
	return -1;
}

int ControllerClass::findByType(char* tip) {
	std::vector<DomainClass> lista;
	RepositoryClass rep ;
	rep.loadFromFlie(lista);
	for (int pozitia = 0;pozitia < lista.size()  ;++pozitia)
		if(strcmp(lista[pozitia].getType(),tip) == 0)
			return pozitia;
	return -1;
}

ControllerClass::~ControllerClass(void)
{
}
