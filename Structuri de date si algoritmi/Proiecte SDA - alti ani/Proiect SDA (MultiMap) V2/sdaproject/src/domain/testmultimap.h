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
#include "multimap.h"
using namespace std;

void testMultiMap(){
	MultiMap* m = new MultiMap();
	int *c;
	c = new int[M];
	string *v;
	v = new string[M];

	assert (m->cheile(c) == 0);
	assert (m->vid() == true);
	assert (m->dim() == 0);
	assert (m->valorile(2,v) == 0);


	assert (m->adauga(3,"filip")  == true ); // adaugat pe pozitia 3
	assert (m->adauga(6,"george") == true ); // daugat pe pozitia 6
	assert (m->adauga(29,"mihai") == true ); // adaugat pe 0
	assert (m->adauga(32,"tibi") == true); // adaugat pe pozitia 1
	assert (m->adauga(13,"mircea") == true); // adaugat pe pozitia 2
	assert (m->adauga(3,"paul") == true); // adaugat pe pozitia 4

//	MultiMapIterator* it = new MultiMapIterator(m);
	MultiMapIterator* it = m->iterator();

/*
	int p = m->cheile(c);
	cout << p << endl;
	for (int i = 0; i < p; i++ ){
		cout << c[i] << "  " << m->valorile(c[i],v) << endl;
	}
*/

	assert (m->cheile(c) == 5);
	assert (m->dim() == 6);
	assert (m->vid() == false);

	assert (m->valorile(3,v) == 2);
	assert (m->valorile(13,v) == 1);

	assert (it->getCheie(3) == 3);
	assert (it->getValoare(3) == "filip");
	assert (it->getUrm(3) == 0); // urm e 0 din cauza ca am adaugat 29

	assert (it->getCheie(6) == 6);
	assert (it->getValoare(6) == "george");
	assert (it->getUrm(6) == 1);

/*
	int i;
	it->prim();
	while (it->valid()){
		i = it->getCurent();
		cout << "pozitia " << i << " : ";
		cout << "  " << it->getCheie(i) << "  " << it->getValoare(i) << "  " << it->getUrm(i) << endl;
		it->urmator();
	}
*/

	assert (m->sterge(3,"mircea") == false);
	assert (m->sterge(3,"filip") == true);
	assert (m->sterge(3,"filip") == false);

	assert (it->getCheie(3) == 29);
	assert (it->getValoare(3) == "mihai");
	assert (it->getUrm(3) == 0);

	cout << endl;

/*
	it->prim();
	while (it->valid()){
		i = it->getCurent();
		cout << "pozitia " << i << " : ";
		cout << "  " << it->getCheie(i) << "  " << it->getValoare(i) << "  " << it->getUrm(i) << endl;
		it->urmator();
	}
*/

	assert ( m->cauta(3,"paul") == 4 );
	assert ( m->cauta(3,"filip") == -1);

	delete (it);
	delete (m);
	delete(c);
	delete (v);
}


#endif /* TESTMULTIMAP_H_ */
