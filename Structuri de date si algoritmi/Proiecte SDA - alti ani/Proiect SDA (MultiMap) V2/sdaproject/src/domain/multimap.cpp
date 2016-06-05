/*
 * multimap.cpp
 *
 *  Created on: 29.05.2012
 *      Author: Emilian
 */
#include "multimap.h"

/*pre: true
 post: MultiMape este dicþionarul cu chei multiple vid (fãrã elemente)*/
MultiMap::MultiMap() {
	valori = new string[M];
	chei = new int[M];
	urm = new int[M];
	m = M;
	primliber = 0;
	for (int i = 0; i < m; i++) {
		chei[i] = -1;
		urm[i] = -1;
		valori[i] = "";
	}
}

/* post: spatiul de memorie alocat a fost eliberat*/
MultiMap::~MultiMap(){
	delete[] valori;
	delete[] chei;
	delete[] urm;
}


/*actualizeaza primliber*/
void MultiMap::actualizarePrimLiber() {
	while (primliber <= m && chei[primliber] != -1)
		primliber++;
}

/*pre:  cheie Cheie, valoare Valoare,
 post: (se adaugã în dicþionar perechea (cheie, valoare))
 */
bool MultiMap::adauga(int cheie, string valoare) {
	int rez;
	rez = this->dispersie(cheie);
	if (this->chei[rez] == -1) {
		this->chei[rez] = cheie;
		this->valori[rez] = valoare;
		if (this->primliber == rez) {
			actualizarePrimLiber();
		}
		return true;
	} else {
		int prec;
		while (rez != -1
				&& (this->chei[rez] != cheie || this->valori[rez] != valoare)) {
			prec = rez;
			rez = this->urm[rez];
		}
		if (rez != -1) {
			return false; //perechea cheie valoare exista
		} else {
			if (this->primliber == this->m) {
				return false; //depasire
			} else {
				this->chei[this->primliber] = cheie;
				this->valori[this->primliber] = valoare;
				this->urm[prec] = this->primliber;
				this->actualizarePrimLiber();
				return true;
			}
		}
	}
}

/*pre: cheie TCheie, valoare TValoare
 post: perechea (cheie, valoare) este ºtearsã din dicþionar,
 returneaza true daca s-a efectual stergerea, false daca nu
 */
bool MultiMap::sterge(int cheie, string valoare) {
	int i = this->dispersie(cheie);
	int j = -1;
	while (i != -1 && (this->chei[i] != cheie || this->valori[i] != valoare)) {
		j = i;
		i = this->urm[i];
	}
	if (i == -1) {
		return false; // cheie inexistenta
	} else {
		bool gata = false;
		int prec;
		int p;
		do {
			prec = i;
			p = this->urm[i];
			while (p != -1 && this->dispersie(this->chei[p]) != i) {
				prec = p;
				p = this->urm[p];
			}
			if (p == -1)
				gata = true;
			else {
				this->chei[i] = this->chei[p];
				this->valori[i] = this->valori[p];
				j = prec;
				i = p;
			}
		} while (gata != true);
		if (j != -1) {
			this->urm[j] = this->urm[i];
		}
		this->chei[i] = -1;
		this->urm[i] = -1;
		this->valori[i] = "";
		if (i < this->primliber)
			this->primliber = i;
		return true;
	}
}

MultiMapIterator* MultiMap::iterator(){
	return new MultiMapIterator(this);
}

/* pre: cheie Cheie, valoare Valoare din dictionar
 * returneaza pozitia daca a gasit, -1 daca nu
 */
int MultiMap::cauta(int cheie, string valoare){
	int rez;
	rez = this->dispersie(cheie);
	while ( rez != -1 && (this->chei[rez] != cheie || this->valori[rez] != valoare)){
		rez = this->urm[rez];
	}
	return rez;
}

/* returneaza true daca dictionarul e vid, false daca nu */
bool MultiMap::vid(){
	for (int i = 0; i < M; i++)
		if (this->chei[i] != -1)
			return false;
	return true;
}

/* returneaza dimensiunea dictionarului(numarul de perechi)*/
int MultiMap::dim(){
	int nr = 0;
	for (int i = 0; i < M ; i++ ){
		if (this->chei[i] != -1)
			nr ++;
	}
	return nr;
}

/* post: cheile e lista cheilor din dictionar
 * returneaza numarul cheilor */
int MultiMap::cheile(int cheile[]){
	int nr=0;
	int ok;
	int j;
	int i;
	for(i = 0; i < M; i++){
		if( this->chei[i] != -1){
			ok = 1;
			j = 0;
			while ( j < nr && ok){
				if(chei[j] == chei[i])
					ok = 0;
				j++;
			}
			if ( ok ){
				cheile[nr] = chei[i];
				nr++;
			}
		}
	}
	return nr;
}

/* pre: cheia exista in dictionar
 * post: valorile contine valorile cheii cheie
 * returneaza numarul valorilor
 */
int MultiMap::valorile(int cheie, string valorile[]){
	int nr = 0;
	for ( int i = 0; i < M; i++){
		if ( this->chei[i] == cheie ){
			valorile[nr] = this->valori[i];
			nr++;
		}
	}
	return nr;
}





