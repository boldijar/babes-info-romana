#include "StdAfx.h"
#include "Lista.h"
#include<iostream>

using namespace std;

Lista::Lista()
{
	int i;
	this->dimensiune = dim;

	for(i=0; i<this->dimensiune; i++){
		this->ListaD[i].data = TElement();
		this->ListaD[i].urmator = NULL;
		this->ListaD[i].precedent = NULL;
	}
	this->prim = 0;
	this->primLiber = 0;
	this->ultim = 0;
}


/*	functia cauta primLiber in lista
	pre: -
	post: primLiber
*/
void Lista::cautaPrimLiber(){
	int i;
	for(i=this->prim; i<=this->dimensiune; i++){
		if(ListaD[i].data == TElement(0,0,0) ){
			this->primLiber = i;
			break;
		}
	}
}

/* functia adauga un element la FINALUL listei sau daca lista e vida, adauga un element pe prima pozitie din lista
	preconditii: elem - TElement
				 ListaD[] - TNod
				 ultim - pozitia ultimului element din lista
	postconditii: ListaD[] cu un nou element de tip TElement
*/
void Lista::adauga(TElement elem){
		struct TNod temp;
		temp.data = elem;
		temp.urmator = NULL;
		if(this->prim == NULL){	//daca nu avem elemente in lista(lista vida) adaugam pe prima pozitie
			temp.precedent = NULL;
			this->prim = 1;
			this->primLiber = 2;
			ListaD[1] = temp;
		}
		else
		{
			ListaD[this->primLiber-1].urmator = primLiber;
			temp.precedent=this->primLiber-1;
			ListaD[this->primLiber] = temp;
			primLiber++;
		}
}


/*	functia adauga un element(elNou) dupa un alt element din lista
	preconditii: element - TElement
				 elNou - TElement
	postconditii: ListaD[] - TNod, cu elementul elNou adaugat dupa element
*/
void Lista::adaugaDupa(TElement element, TElement elNou){
	//cautam pozitia elementului dupa care vrem sa inseram
	int pozitie=prim;
	while(ListaD[pozitie].data != element)
		pozitie = ListaD[pozitie].urmator;
		
	//inseram noul element
	Lista::cautaPrimLiber();
	struct TNod temp;
	temp.data = elNou;
	temp.precedent = pozitie;
	temp.urmator = ListaD[pozitie].urmator;
	ListaD[ListaD[pozitie].urmator].precedent = this->primLiber;
	ListaD[this->primLiber] = temp;
	ListaD[pozitie].urmator = this->primLiber;
	this->ultim = primLiber-1;
}


/*	functia sterge un element de tip TElement din lista
	preconditii: element - TElement
	postconditii: ListaD = ListaD - element
*/
void Lista::sterge(TElement element){
	//cautam pozitia elementului pe care vrem sa-l stergem
	int pozitie = this->prim;
	while(ListaD[pozitie].data != element)
		pozitie = ListaD[pozitie].urmator;

	if (pozitie == this->prim){ //daca elementul pe care vrem sa-l stergem se afla pe prima pozitie(este primul in lista)
		this->prim = this->prim + 1;
		ListaD[ListaD[pozitie].urmator].precedent=0;
		ListaD[pozitie].data = TElement(0,0,0);
	}
	else if(pozitie == ultim){	//daca elementul pe care vrem sa-l stergem se afla pe ultima pozitie(este ultimul din lista)
		ListaD[ListaD[pozitie].precedent].urmator=0;
		ListaD[pozitie].data = TElement(0,0,0);
	}
	else{	//daca elementul pe care vrem sa-l stergem se afla in interiorul listei
		ListaD[ListaD[pozitie].precedent].urmator=ListaD[pozitie].urmator;
		ListaD[ListaD[pozitie].urmator].precedent=ListaD[pozitie].precedent;
		ListaD[pozitie].data = TElement(0,0,0);

	}
	Lista::cautaPrimLiber();
}

/* functie returneaza true daca lista este vida, si false in caz contrar
*/
bool Lista::listaVida(){
	bool vida = true;
	for(int i=prim; i<this->dimensiune; i++){
		if (ListaD[i].data != TElement(0,0,0))
			vida=false;
	}
	return vida;
}
Lista::~Lista(void)
{
}
