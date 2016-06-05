/*
 * WardrobeRepository.h
 *
 *  Created on: 28.06.2012
 *      Author: Cristian Mihok
 */

#ifndef WARDROBEREPOSITORY_H_
#define WARDROBEREPOSITORY_H_

#include "../domain/MultiMap.h"

class Wardrobe{

public:
	MultiMap *wardrobe;
	MultiMapIterator *it;


	Wardrobe();


	~Wardrobe();


	bool adauga( int cheie, string obiect);


	int pline(int c[]);


	bool exista(int cheie, string obiect);


	void returneaza(int cheie, string obiect);


	bool cheieOcup(int cheie);


	int nrObiectePeCheie(int cheie, string obiecte[]);

};


#endif /* WARDROBEREPOSITORY_H_ */
