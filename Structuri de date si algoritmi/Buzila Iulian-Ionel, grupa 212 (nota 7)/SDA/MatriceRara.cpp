#include "StdAfx.h"
#include "MatriceRara.h"
#include <iostream>


MatriceRara::MatriceRara()
{
	//adaug automat cateva case la pornirea aplicatiei
	this->adaugaMatrice(TElement(1,1,10));
	this->adaugaMatrice(TElement(1,3,15));
	this->adaugaMatrice(TElement(2,1,20));
	this->adaugaMatrice(TElement(2,4,25));
}


/*	adaug in matrice un element, daca matricea e vida fac o adaugare folosind functia ,,adaugare" din clasa Lista,
	daca nu e vida, folosesc functia ,,adaugareDupa" din clasa Lista, adaugand ,,element" dupa elementul dat de 
	functia ,,cauta" astfel incat matricea sa fie ordonata dupa linie, respectiv coloana
*/
void MatriceRara::adaugaMatrice(TElement element){
	if(lista.listaVida() == true)
		lista.adauga(element);
	else{
		TElement elementAnterior = cauta(element);
		lista.adaugaDupa(elementAnterior, element);
	}
}


/*	functia returneaza valoarea de la linia linie si coloana coloana
	preconditii: linie - int
				 coloana - int
	postconditii: valoare - int
*/
int MatriceRara::getValoare(int linie, int coloana){
	for(int i=lista.prim; i<lista.dimensiune; i++)
		if(lista.ListaD[i].data.getLinie() == linie && lista.ListaD[i].data.getColoana() == coloana)
			return lista.ListaD[i].data.getValoare();
	return 0;
}


/*	functia cauta elementul anterior elementului ,,element" ( :D ) si returneaza acel element anterior
	linie, coloana, valoare - reprezinta atributele lui ,,element"
	linieV, coloanaV - variabilele folosite pentru deplasarea in matrice
	linieNoua, coloanaNoua, valoareNoua - reprezinta atributele elementului anterior lui ,,element"
	preconditii: element - TEelement
	postconditii: element' - TElement ce reprezinta elementul anterior elementului ,,element"
*/
TElement MatriceRara::cauta(TElement element){
	int linie = element.getLinie();
	int coloana = element.getColoana();
	int valoare = this->getValoare(linie, coloana);
	
	int linieNoua = 0;
	int coloanaNoua = 0;
	int valoareNoua = 0;

	int linieV, coloanaV;
	for(linieV=0; linieV < lista.dimensiune; linieV++){
		for(coloanaV=0; coloanaV<lista.dimensiune; coloanaV++){
			if(coloanaV == coloana && linieV == linie) return TElement(linieNoua, coloanaNoua, valoareNoua);
			else{
				if(this->getValoare(linieV,coloanaV) != 0){
					linieNoua = linieV;
					coloanaNoua = coloanaV;
					valoareNoua = this->getValoare(linieV,coloanaV);
				}
			}
		}
	}
}

/* functie pentru afiseara tripletelor de forma <linie, coloana, valoare>
	pre: -
	post: lista de triplete
*/
void MatriceRara::afisareMatrice(){
	Iterator *i;
	i = this->Itr();

	lista.ListaD[i->curent].data.print();
	while(i->valid())
	{
		i->urmator();
		lista.ListaD[i->curent].data.print();
	}
}


/*	functia modifca valoarea de la linia si coloana data de element. sterge elementul cu valoarea veche, si apoi il adauga cu valoarea noua
	preconditii: element-TElement, 
				 valoareNoua - int
	postconditii: Matricea modificata
*/
void MatriceRara::modificareMatrice(TElement element, int valoareNoua){
	int linie = element.getLinie();
	int coloana = element.getColoana();
	int valoare = element.getValoare();
	TElement vechi(linie, coloana, valoare);
	TElement nou(linie, coloana, valoareNoua);
	lista.sterge(vechi);
	this->adaugaMatrice(nou);
}

void MatriceRara::stergeMatrice(TElement element){
	lista.sterge(element);
}


/*	pre:- 
	post:functia returneaza un iterator pentru matrice rara
*/
Iterator* MatriceRara::Itr() {
	return new Iterator(this);
}

MatriceRara::~MatriceRara(void)
{
}
