/*
 * MultiMap.h
 *
 *  Created on: 28.06.2012
 *      Author: Cristian Mihok
 */


#ifndef MULTIMAP_H_
#define MULTIMAP_H_
#define MAX 15
#define MAXK 20

#include <iostream>
#include <string>

using namespace std;

class MultiMapIterator;

class MultiMap {
	friend class MultiMapIterator;

private:
	int m;
	int *keys;
	string *values;
	int *next;
	int firstFree;

public:

	MultiMap();


	~MultiMap();

	int dispersie(int c) {
		return c % m;
	}

	void refreshFirstFree();


	bool add(int key, string value);


	bool del(int key, string value);


	int search(int key, string value);


	bool empty();


	int keysNr(int keyList[]);


	int length();


	int valuesNr(int key, string valueList[]);


	MultiMapIterator* iterator();


	int getFirstFree(){
		return firstFree;
	}
};


class MultiMapIterator{
	friend class MultiMap;

private:
	int curent;
	MultiMap* _multimap;

public:

	MultiMapIterator(MultiMap* multimap){
		this->curent = 0;
		_multimap = multimap;
	}

	void first(){
		curent = 0;
		while(_multimap->keys[curent] == -1){
			curent++;
		}
	}


	void next(){
		do{
			curent++;
		}while(_multimap->keys[curent] == -1 && curent <= MAX);
	}


	bool valid(){
		if(curent < MAX && _multimap->keys[curent] != -1)
			return true;
		return false;
	}

	int getCurent(){
		return curent;
	}


	int getKey(int i){
		return _multimap->keys[i];
	}


	string getValue(int i){
		return _multimap->values[i];
	}


	int getNext(int i){
		return _multimap->next[i];
	}


} typedef MultiMapIterator;

#endif /* MULTIMAP_H_ */
