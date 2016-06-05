#include "StdAfx.h"
#include "string.h"

#include <iostream>

using namespace std;
#include "MenuClass.h"
#include "ControllerClass.h"
#include "RepositoryClass.h"
#include "DomainClass.h"

ControllerClass::ControllerClass(void)
{
}

void ControllerClass::Add(int id,int number,float amount,char* type) {
	
	DomainClass element;// =DomainClass::DomainClass();// = new DomainClass();
	element.DomainClass::DomainClass(id,number,amount,type);
	
	
	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista);
	
	int cautare = FindById(element.GetId());
	if (cautare == -1 ) {
			
			lista.append(element);
			rep.SaveInFile(lista);
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

void ControllerClass::UpdateController(int id,int number,float amount,char* type) {


	DomainClass element;
	element = DomainClass::DomainClass(id,number,amount,type);
	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista);
	int cautare = FindById(id);
	if (cautare != -1 ) {

		lista.updatePosition(cautare,element);
		rep.SaveInFile(lista);
		
	
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
void ControllerClass::DeleteController(int id) {

	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista);
	int cautare = FindById(id);
	if (cautare != -1 ) {

		lista.deletePosition(cautare);
		rep.SaveInFile(lista);

	
		cout << "Stergerea s-a efectuat cu succes" << endl;

	}

	else
		cout << "Cheltuiala respectiva nu se afla in lista" << endl;

	//lista.~DynamicList();
	

}

/*
	Functie de tipul DomainClass care va returna o lista care contine cheltuielile cu suma mai mare de
	cat suma primita ca parametru

	*/
void ControllerClass::FilterAmountController(float suma) {

	
	
	DomainClass* filtrate = new DomainClass[100];
	int contor = 0;
	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista);

	for( int i = 0; i < lista.getLenght(); ++i)
		if (lista[i].GetAmount() >= suma) {
			contor ++;
			filtrate [contor]  = lista[i];

		}
	for( int i = 1; i <= contor; ++i)
		filtrate[i].Print();
		
	delete[] filtrate;
	//lista.~DynamicList();
		cout << endl;
	
		
}
void ControllerClass::FilterTypeController(char* tip) {

	
	DomainClass* filtrate = new DomainClass[100];
	int contor = 0;
	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista);

	for( int i = 0; i < lista.getLenght(); ++i)
		if (strcmp(lista[i].GetType(),tip) == 0) {
			contor ++;
			filtrate [contor]  = lista[i];

		}
	for( int i = 1; i <= contor; ++i)
		filtrate[i].Print();
		cout << endl;
	delete[] filtrate;
}


void ControllerClass::SortAmountController(DynamicList & lista){
	
	DomainClass aux,aux1;
	
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista);
	for (int i = 0;i < lista.getLenght()-1; ++i)
		for(int j = i+1; j < lista.getLenght(); ++j)
			if (lista[i].GetAmount() > lista[j].GetAmount())
			{
				aux = lista[i];
				aux1 = lista[j];
				lista.updatePosition(i,aux1);
				lista.updatePosition(j,aux);
				
			}
			

}
void ControllerClass::SortAmountControllerDesc(DynamicList & lista){
	
	DomainClass aux,aux1;
	
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista);
	for (int i = 0;i < lista.getLenght()-1; ++i)
		for(int j = i+1; j < lista.getLenght(); ++j)
			if (lista[i].GetAmount() < lista[j].GetAmount())
			{
				aux = lista[i];
				aux1 = lista[j];
				lista.updatePosition(i,aux1);
				lista.updatePosition(j,aux);
				
			}
			

}

void ControllerClass::SortTypeController(DynamicList & lista){
	
	DomainClass aux,aux1;
	
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista);
	for (int i = 0;i <= lista.getLenght()-1; ++i)
		for(int j = i;j < lista.getLenght(); ++j)
			if (strcmp(lista[i].GetType(),lista[j].GetType()) > 0)
			{
				aux = lista[i];
				aux1 = lista[j];
				lista.updatePosition(i,aux1);
				lista.updatePosition(j,aux);
			}
			
}
void ControllerClass::SortTypeControllerDesc(DynamicList & lista){
	
	DomainClass aux,aux1;
	
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista);
	for (int i = 0;i <= lista.getLenght()-1; ++i)
		for(int j = i;j < lista.getLenght(); ++j)
			if (strcmp(lista[i].GetType(),lista[j].GetType()) < 0)
			{
				aux = lista[i];
				aux1 = lista[j];
				lista.updatePosition(i,aux1);
				lista.updatePosition(j,aux);
			}
}

int ControllerClass::FindById(int id) {
	/*
	Functia cauta o cheltuiala dupa numar,daca ea apare ii va return pozitia 
	cheltielii in lista si in caz contrar va returna 0
	*/
	
	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista);

	for (int pozitia = 0;pozitia < lista.getLenght()  ;++pozitia)
		if(lista[pozitia].GetId() == id)
			return pozitia;

	return -1;
	lista.~DynamicList();
	

	
}

int ControllerClass::FindByType(char* tip) {

	DynamicList lista;
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista);
	for (int pozitia = 0;pozitia < lista.getLenght()  ;++pozitia)
		if(strcmp(lista[pozitia].GetType(),tip) == 0)
			return pozitia;

	return -1;

}

ControllerClass::~ControllerClass(void)
{
}
