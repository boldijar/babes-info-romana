/*
 * testmultimap.h
 *
 *  Created on: 04.06.2012
 *      Author: Emilian
 */

#ifndef TESTMULTIMAP_H_
#define TESTMULTIMAP_H_

#include <string>
#include <assert.h>
#include "multidict.h"
using namespace std;

void testMultiMap(){
	MultiDictionar* m = new MultiDictionar();
	assert (m->adauga(3,"filip")  == true ); // adaugat pe pozitia 3
	assert (m->adauga(6,"george") == true ); // daugat pe pozitia 6
	assert (m->adauga(29,"mihai") == true ); // adaugat pe 0
	assert (m->adauga(32,"tibi") == true); // adaugat pe pozitia 1
	assert (m->adauga(13,"mircea") == true); // adaugat pe pozitia 2
	assert (m->adauga(3,"paul") == true); // adaugat pe pozitia 4
	MultiDictionarIt* it = new MultiDictionarIt(m);
//	MultiMapIterator* it = m->iterator();

	assert (it->getKey(3) == 3);
	assert (it->getValue(3) == "filip");
	assert (it->getNext(3) == 0); // urm e 0 din cauza ca am adaugat 29

	assert (it->getCheie(6) == 6);
	assert (it->getValoare(6) == "george");
	assert (it->getUrm(6) == 1);

	int i;
	it->first();
	while (it->valid()){
		i = it->getCurent();
		cout << "pozitia " << i << " : ";
		cout << "  " << it->getCheie(i) << "  " << it->getValoare(i) << "  " << it->getUrm(i) << endl;
		it->urmator();
	}

	assert (m->sterge(3,"mircea") == false);
	assert (m->sterge(3,"filip") == true);
	assert (m->sterge(3,"filip") == false);

	cout << endl;

	it->first();
	while (it->valid()){
		i = it->getCurent();
		cout << "pozitia " << i << " : ";
		cout << "  " << it->getCheie(i) << "  " << it->getValoare(i) << "  " << it->getUrm(i) << endl;
		it->urmator();
	}

	delete (m);
}


#endif /* TESTMULTIMAP_H_ */
