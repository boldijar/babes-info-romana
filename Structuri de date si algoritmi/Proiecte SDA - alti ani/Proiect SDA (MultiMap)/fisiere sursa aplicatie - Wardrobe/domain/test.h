/*
 * test.h
 *
 *  Created on: 28.06.2012
 *      Author: Cristian Mihok
 */

#ifndef TEST_H_
#define TEST_H_

#include <string>
#include "MultiMap.h"
#include <assert.h>
using namespace std;

void test(){
	MultiMap* map = new MultiMap();
	int *keys;
	keys = new int[M];
	string *values;
	values = new string[M];

	assert (map->keysNr(keys) == 0);
	assert (map->empty() == true);
	assert (map->length() == 0);
	assert (map->valuesNr(2,values) == 0);


	assert (map->add(3,"filip")  == true );
	assert (map->add(6,"george") == true );
	assert (map->add(29,"mihai") == true );
	assert (map->add(32,"tibi") == true);
	assert (map->add(13,"mircea") == true);
	assert (map->add(3,"paul") == true);


	MultiMapIterator* it = map->iterator();



	assert (map->keysNr(keys) == 5);
	assert (map->length() == 6);
	assert (map->empty() == false);

	assert (map->valuesNr(3,values) == 2);
	assert (map->valuesNr(13,values) == 1);

	assert (it->getKey(3) == 3);
	assert (it->getValue(3) == "filip");
	assert (it->getNext(3) == 0);

	assert (it->getKey(6) == 6);
	assert (it->getValue(6) == "george");
	assert (it->getNext(6) == 1);



	assert (map->del(3,"mircea") == false);
	assert (map->del(3,"filip") == true);
	assert (map->del(3,"filip") == false);

	assert (it->getKey(3) == 29);
	assert (it->getValue(3) == "mihai");
	assert (it->getNext(3) == 0);

	cout << endl;



	assert ( map->search(3,"paul") == 4 );
	assert ( map->search(3,"filip") == -1);

	delete (it);
	delete (map);
	delete(keys);
	delete (values);
}


#endif /* TEST_H_ */
