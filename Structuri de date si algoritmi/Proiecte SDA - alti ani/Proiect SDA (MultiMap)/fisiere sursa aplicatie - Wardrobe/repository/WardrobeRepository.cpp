/*
 * WardrobeRepository.cpp
 *
 *  Created on: 28.06.2012
 *      Author: Cristian Mihok
 */

#include "WardrobeRepository.h"

Wardrobe::Wardrobe(){
	wardrobe = new MultiMap;
	it = new MultiMapIterator(wardrobe);
}

Wardrobe::~Wardrobe(){
	delete(wardrobe);
	delete(it);
}


bool Wardrobe::adauga( int cheie, string obiect){
	string aux[MAX];
	if(wardrobe->valuesNr(cheie,aux) >= MAXK)
		return false;
	return(wardrobe->add(cheie,obiect));
}


int Wardrobe::pline(int c[]){
	string aux[MAXK];
	int auxk[MAX];
	int i;
	int nr = 0;
	int n = wardrobe->keysNr(auxk);
	for ( i = 0; i < n; i++){
		if ( wardrobe->valuesNr(auxk[i],aux) == 20 ){
			nr++;
			c[nr] = auxk[i];
		}
	}
	return nr;
}


bool Wardrobe::exista(int cheie, string obiect){
	if ( wardrobe->search(cheie, obiect) == -1 )
		return false;
	return true;
}


void Wardrobe::returneaza(int cheie, string obiect){
	wardrobe->del(cheie, obiect);
}


bool Wardrobe::cheieOcup(int cheie){
	int auxk[MAX];
	int n = wardrobe->keysNr(auxk);
	for (int i = 0; i < n; i++)
		if ( auxk[i] == cheie )
			return true;
	return false;
}


int Wardrobe::nrObiectePeCheie(int cheie, string obiecte[]){
	return(wardrobe->valuesNr(cheie, obiecte));
}




