/*
 * MultiMap.cpp
 *
 *  Created on: 28.06.2012
 *      Author: Cristian Mihok
 */


#include "multimap.h"


MultiMap::MultiMap() {
	values = new string[MAX];
	keys = new int[MAX];
	next = new int[MAX];
	m = MAX;
	firstFree = 0;
	for (int i = 0; i < m; i++) {
		keys[i] = -1;
		next[i] = -1;
		values[i] = "";
	}
}


MultiMap::~MultiMap(){
	delete[] values;
	delete[] keys;
	delete[] next;
}



void MultiMap::refreshFirstFree() {
	while (firstFree <= m && keys[firstFree] != -1)
		firstFree++;
}


bool MultiMap::add(int key, string value) {
	int rez;
	rez = this->dispersie(key);
	if (this->keys[rez] == -1) {
		this->keys[rez] = key;
		this->values[rez] = value;
		if (this->firstFree == rez) {
			refreshFirstFree();
		}
		return true;
	} else {
		int prec;
		while (rez != -1
				&& (this->keys[rez] != key || this->values[rez] != value)) {
			prec = rez;
			rez = this->next[rez];
		}
		if (rez != -1) {
			return false; //perechea key value exista
		} else {
			if (this->firstFree == this->m) {
				return false; //depasire
			} else {
				this->keys[this->firstFree] = key;
				this->values[this->firstFree] = value;
				this->next[prec] = this->firstFree;
				this->refreshFirstFree();
				return true;
			}
		}
	}
}


bool MultiMap::del(int key, string value) {
	int i = this->dispersie(key);
	int j = -1;
	while (i != -1 && (this->keys[i] != key || this->values[i] != value)) {
		j = i;
		i = this->next[i];
	}
	if (i == -1) {
		return false;
	} else {
		bool gata = false;
		int prec;
		int p;
		do {
			prec = i;
			p = this->next[i];
			while (p != -1 && this->dispersie(this->keys[p]) != i) {
				prec = p;
				p = this->next[p];
			}
			if (p == -1)
				gata = true;
			else {
				this->keys[i] = this->keys[p];
				this->values[i] = this->values[p];
				j = prec;
				i = p;
			}
		} while (gata != true);
		if (j != -1) {
			this->next[j] = this->next[i];
		}
		this->keys[i] = -1;
		this->next[i] = -1;
		this->values[i] = "";
		if (i < this->firstFree)
			this->firstFree = i;
		return true;
	}
}

MultiMapIterator* MultiMap::iterator(){
	return new MultiMapIterator(this);
}


int MultiMap::search(int key, string value){
	int aux;
	aux = this->dispersie(key);
	while ( aux != -1 && (this->keys[aux] != key || this->values[aux] != value)){
		aux = this->next[aux];
	}
	return aux;
}


bool MultiMap::empty(){
	for (int i = 0; i < MAX; i++)
		if (this->keys[i] != -1)
			return false;
	return true;
}


int MultiMap::length(){
	int nr = 0;
	for (int i = 0; i < MAX ; i++ ){
		if (this->keys[i] != -1)
			nr ++;
	}
	return nr;
}


int MultiMap::keysNr(int keyList[]){
	int nr=0;
	int ok;
	int j;
	int i;
	for(i = 0; i < MAX; i++){
		if( this->keys[i] != -1){
			ok = 1;
			j = 0;
			while ( j < nr && ok){
				if(keys[j] == keys[i])
					ok = 0;
				j++;
			}
			if ( ok ){
				keyList[nr] = keys[i];
				nr++;
			}
		}
	}
	return nr;
}


int MultiMap::valuesNr(int key, string valueList[]){
	int nr = 0;
	for ( int i = 0; i < MAX; i++){
		if ( this->keys[i] == key ){
			valueList[nr] = this->values[i];
			nr++;
		}
	}
	return nr;
}





