/*
 * MultiDictionar.h
 *
 *  Created on: 4 Jun 2014
 *      Author: Mihai
 */

#ifndef MULTIDICTIONAR_H_
#define MULTIDICTIONAR_H_



#include "TElement.h"

using namespace std;

#define DIM 30;
#define implicit "None"

class MultiDictionarIterator;
class MultiDictionar{
	friend class MultiDictionarIterator;
public:
	int numarDispersie;
	int dim;
	TElement *tabela;
	MultiDictionar(int disp){
		this->numarDispersie = disp;
		this->dim = DIM;
		this->tabela = new TElement[this->dim*sizeof(TElement)];
	}
	virtual ~MultiDictionar(){
		delete[]this->tabela;
		this->tabela = 0;
		this->dim = 0;
		this->numarDispersie = 0;
	}

	/*MultiDictionarIterator* iterator(int i)
	{
		return MultiDictionarIterator(i);
	}*/

	void adauga(string cheie, string valoare)
	{
		//pe j se returneaza pozitia pe care s-a adaugat
		TElement *e = new TElement(cheie,valoare);
		int j=this->dispersie(e);
		int gasit=0;
		do{
			if(this->tabela[j].chei.compare(implicit) == 0)
				{
				this->tabela[j].chei= e->chei;
				this->tabela[j].valori= e->valori;
				gasit=1;
				}
			else
				j++;
		}
		while(gasit == 0);
	}
	void sterge(string cheie){
		TElement *e = new TElement(cheie,"");
		int start = this->dispersie(e);
		for(int j=start;j < this->dim;j++)
			if(this->tabela[j].chei.compare(cheie)==0)
			{	cout<<"STERGEM "<<&tabela[j];
				this->tabela[j].chei = implicit;
				this->tabela[j].valori = implicit;
			}
	}

	int cauta(string cheie)
	{
		TElement *e = new TElement(cheie,"");
		int start = this->dispersie(e);
		int gasit=0;
		while(gasit == 0)
		{
			if(start > this->dim)
				break;
			if(this->tabela[start].chei.compare(cheie) == 0)
				{
					gasit = 1;
				}
			else
				start++;
		}
		return gasit;
	}
	int dispersie(TElement *el){
		//pre:el de tip TElement
		//returneaza pozitia din tabela de dispersie de dinaintea rezolvarii posibilei coliziuni
		return el->hashCode() % this->numarDispersie;
	}
	int dimensiune()
	{
		//returneaza cate perechi am in multidictionar
		int c=0;
		for(int j=0;j<this->dim;j++)
			if(this->tabela[j].chei.compare(implicit) != 0)
				c++;
		return c;
	}

	void chei(string m[30]){
		//pre: m - sir de siruri de caractere
		//post: va contine toate cheile
		int poz=0;
		for(int j=0;j<this->dim;j++)
			if(this->tabela[j].chei.compare(implicit) != 0)
				m[poz++]=this->tabela[j].chei;
	}

	void valori(string m[30]){
		//pre: m - sir de siruri de caractere
		//post: va contine toate valorile
		int poz=0;
		for(int j=0;j<this->dim;j++)
			if(this->tabela[j].chei.compare(implicit) != 0)
				m[poz++]=this->tabela[j].valori;
		}
	void valoriDupaCheie(string m[30],string cheie,int &lungime){
		//pre: m - sir de siruri de caractere, cheie - sir de caractere
		//post: va contine toate valorile asociate cheii dorite
		lungime = 0;
		int poz=0;
		for(int j=0;j<this->dim;j++)
			if(this->tabela[j].chei.compare(cheie) == 0){
				lungime++;
				m[poz++]=this->tabela[j].valori;
			}
	}
	void perechi(MultiDictionar *aux){
		//pre: aux multidictionar
		//post: aux->tabela va contine toate perechile din dictionarul initial
		string lista_chei[30],lista_valori[30];
		this->chei(lista_chei);
		this->valori(lista_valori);
		for(int j=0;j<this->dimensiune();j++)
		{
			aux->tabela[j].chei=lista_chei[j];
			aux->tabela[j].valori=lista_valori[j];
		}
	}

	bool vid(){
		//returneaza false daca dict e vid si true in caz contrar
		return this->dimensiune()!=0;
	}
};



class MultiDictionarIterator{
	friend class MultiDictionar;
public:
	int iterator;
	MultiDictionar * dict;
	MultiDictionarIterator(int iter){
		iter = this->iterator;
		this->dict = new MultiDictionar(10);
	}
	virtual ~MultiDictionarIterator(){
		delete[]this->dict;
		this->dict = 0;
		this->iterator = 0;
	}
	bool valid(){
		//returneaza TRUE daca mai am loc in lista si FALSE in caz contrar
		return this->iterator <= this->dict->dim;
	}

	TElement *element(TElement *el){
		//returneaza elementul de pe pozitia curenta
		el = new TElement(&this->dict->tabela->chei[this->iterator],&this->dict->tabela->valori[this->iterator]);
		return el;
	}

	void urmator(){
		//iteratorul devine urmatoarea pozitie goala de dupa locatia curenta
		while(strcmp(&this->dict->tabela->chei[this->iterator],"None") != 0)
			this->iterator++;
	}


};

#endif /* MULTIDICTIONAR_H_ */
