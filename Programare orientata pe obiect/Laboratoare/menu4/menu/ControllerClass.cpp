#include "StdAfx.h"
#include<iostream>
#include "ControllerClass.h"
#include "DomainClass.h"
#include "RepositoryClass.h"
#include "string.h"
using namespace std;


ControllerClass::ControllerClass(void)
{
}

void ControllerClass::Add(int id,int number,float amount,char* type) {

	DomainClass element(id,number,amount,type);// =DomainClass::DomainClass();// = new DomainClass();
	//element.DomainClass::DomainClass();
	
	int iter;
	DomainClass lista[100];
	//RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista,iter);
	
	int cautare = FindById(element.GetId());
	if (cautare == 0 ) {
			iter++;
			lista[iter] = element;

			rep.SaveInFile(lista,iter);
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
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	int iter;
	DomainClass lista[100];
	rep.LoadFromFlie(lista,iter);
	int cautare = FindById(id);
	if (cautare != 0 ) {

		lista[cautare].setBlock(element.GetId(),element.GetAmount(),element.GetType());
		rep.SaveInFile(lista,iter);
	
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

	RepositoryClass rep = RepositoryClass::RepositoryClass();
	int iter;
	DomainClass lista[100];
	rep.LoadFromFlie(lista,iter);
	int cautare = FindById(id);
	if (cautare != 0 ) {

		for (int i = cautare; i < iter; ++i)
			lista[i] = lista[i+1];
			iter--;
		rep.SaveInFile(lista,iter);

	
		cout << "Stergerea s-a efectuat cu succes" << endl;

	}

	else
		cout << "Cheltuiala respectiva nu se afla in lista" << endl;

	

}

/*
	Functie de tipul DomainClass care va returna o lista care contine cheltuielile cu suma mai mare de
	cat suma primita ca parametru

	*/
void ControllerClass::FilterAmountController(float suma) {

	RepositoryClass rep = RepositoryClass::RepositoryClass();
	
	DomainClass filtrate[100];
	int contor = 0;
	int iter;
	DomainClass lista[100];
	rep.LoadFromFlie(lista,iter);

	for( int i = 1; i <= iter; ++i)
		if (lista[i].GetAmount() >= suma) {
			contor ++;
			filtrate [contor]  = lista[i];

		}
	for( int i = 1; i <= contor; ++i)
		filtrate[i].Print();
		cout << endl;
}
void ControllerClass::FilterTypeController(char* tip) {

	RepositoryClass rep = RepositoryClass::RepositoryClass();
	
	DomainClass filtrate[100];
	int contor = 0;
	int iter;
	DomainClass lista[100];
	rep.LoadFromFlie(lista,iter);

	for( int i = 1; i <= iter; ++i)
		if (strcmp(lista[i].GetType(),tip) == 0) {
			contor ++;
			filtrate [contor]  = lista[i];

		}
	for( int i = 1; i <= contor; ++i)
		filtrate[i].Print();
		cout << endl;
}


void ControllerClass::SortAmountController(DomainClass lista[100],int &iter){
	
	DomainClass aux;
	
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista,iter);
	for (int i = 1;i <= iter; ++i)
		for(int j = i;j <= iter; ++j)
			if (lista[i].GetAmount() > lista[j].GetAmount())
			{
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}

}
void ControllerClass::SortAmountControllerDesc(DomainClass lista[100],int &iter){
	
	DomainClass aux;
	
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista,iter);
	for (int i = 1;i <= iter; ++i)
		for(int j = i;j <= iter; ++j)
			if (lista[i].GetAmount() < lista[j].GetAmount())
			{
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}

}
void ControllerClass::SortTypeController(DomainClass lista[100],int &iter){

	DomainClass aux;
	
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista,iter);
	for (int i = 1;i <= iter; ++i)
		for(int j = i;j <= iter; ++j)
			if (strcmp(lista[i].GetType(),lista[j].GetType()) > 0)
			{
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}

}
void ControllerClass::SortTypeControllerDesc(DomainClass lista[100],int &iter){

	DomainClass aux;
	
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista,iter);
	for (int i = 1;i < iter; ++i)
		for(int j = i+1;j <= iter; ++j)
			if (strcmp(lista[i].GetType(),lista[j].GetType()) < 0)
			{
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}

}

int ControllerClass::FindById(int id) {
	/*
	Functia cauta o cheltuiala dupa numar,daca ea apare ii va return pozitia 
	cheltielii in lista si in caz contrar va returna 0
	*/
	int iter;
	DomainClass lista[100];
	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista,iter);
	for (int pozitia = 1;pozitia <= iter  ;++pozitia)
		if(lista[pozitia].GetId() == id)
			return pozitia;

	return 0;


	
}

int ControllerClass::FindByType(char* tip) {
	int iter;
	DomainClass lista[100];

	RepositoryClass rep = RepositoryClass::RepositoryClass();
	rep.LoadFromFlie(lista,iter);
	for (int pozitia = 1;pozitia <= iter  ;++pozitia)
		if(strcmp(lista[pozitia].GetType(),tip) == 0)
			return pozitia;

	return 0;

}

ControllerClass::~ControllerClass(void)
{
}
