/*
 * multimap.h
 *
 *  Created on: 29.05.2012
 *      Author: Emi Mateut
 */
#ifndef MULTIMAP_H_
#define MULTIMAP_H_
#define M 13
#define K 4

#include <iostream>
#include <string>

using namespace std;

class MultiMapIterator;

class MultiMap {
	friend class MultiMapIterator;
private:
	int m;
	int *chei;
	string *valori;
	int *urm;
	int primliber;

public:
	/*pre: true
	 post: MultiMape este dicþionarul cu chei multiple vid (fãrã elemente)*/
	MultiMap();

	/* post: spatiul de memorie alocat a fost eliberat*/
	~MultiMap();

	int dispersie(int c) {
		return c % m;
	}

	/*actualizeaza primliber*/
	void actualizarePrimLiber();

	/*pre:  cheie Cheie, valoare Valoare,
	post: (se adaugã în dicþionar perechea (cheie, valoare))
	returneaza true daca adaugarea s-a efectuat, false daca nu
	*/
	bool adauga(int cheie, string valoare);

	/*pre: cheie TCheie, valoare TValoare
	 post: perechea (cheie, valoare) este ºtearsã din dicþionar,
	 returneaza true daca s-a efectual stergerea, false daca nu
	 */
	bool sterge(int cheie, string valoare);

	/* pre: cheie Cheie, valoare Valoare din dictionar
	 * returneaza pozitia daca a gasit, -1 daca nu
	 */
	int cauta(int cheie, string valoare);

	/* returneaza true daca dictionarul e vid, false daca nu */
	bool vid();

	/* post: cheile e lista cheilor din dictionar
	 * returneaza numarul cheilor */
	int cheile(int cheile[]);

	/* returneaza dimensiunea dictionarului(numarul de perechi)*/
	int dim();

	/* pre: cheia exista in dictionar
	 * post: valorile contine valorile cheii cheie
	 * returneaza numarul valorilor
	 */
	int valorile(int cheie, string valorile[]);


	MultiMapIterator* iterator();

	/*returneaza primLiber*/
	int getPrimLiber(){
		return primliber;
	}
};


class MultiMapIterator{
	friend class MultiMap;
private:
	int curent;
	MultiMap* dict;

public:
	/*pre : map este un container
	  post : s-a creat iteratorul i pe containerul map, (elementul
	  curent din iterator refera `primul' element din container)
	  */
	MultiMapIterator(MultiMap* map){
		this->curent = 0;
		dict = map;
	}

	/*post: curent e pozitionat pe primul element din container */
	void prim(){
		curent = 0;
		while(dict->chei[curent] == -1){
			curent++;
		}
	}

	/*post: curent refera `urmatorul' element din container
	fata de cel referit de curent
	*/
	void urmator(){
		do{
			curent++;
		}while(dict->chei[curent] == -1 && curent <= M);
	}

	/*pre: iterator
	 *post: returneaza true daca curent refera o pozitie valida
	 * 		sau false daca nu
	 */
	bool valid(){
		if(curent < M && dict->chei[curent] != -1)
			return true;
		return false;
	}

	/* returneaza pozitia elementului curent */
	int getCurent(){
		return curent;
	}

	/*pre : curent este valid (refera un element din container)
	post : returneaza cheia din elementul curent din iteratie'*/
	int getCheie(int i){
		return dict->chei[i];
	}

	/*pre : curent este valid (refera un element din container)
		post : returneaza valoarea din elementul curent din iteratie'*/
	string getValoare(int i){
		return dict->valori[i];
	}

	/*returneaza valoarea din vectorul urm de pe pozitia curenta*/
	int getUrm(int i){
		return dict->urm[i];
	}


} typedef MultiMapIterator;
#endif /* MULTIMAP_H_ */
