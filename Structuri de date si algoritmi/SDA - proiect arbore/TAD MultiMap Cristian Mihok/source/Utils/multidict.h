/*
 * multidict.h
 *
 *  Created on: 27.05.2012
 *      Author: Cristian Mihok
 */
#ifndef MULTIDICT_H_
#define MULTIDICT_H_

#define MAX 15

#include <iostream>
#include <string>

using namespace std;

class MultiDictionarIt;

class MultiDictionar {

	friend class MultiDictionarIt;

private:
	int dim;
	int keys[MAX];
	int next[MAX];
	string values[MAX];
	int primLiber;

public:
	/*
	 * constructior multidictionar
	 */
	MultiDictionar();

	/*
	 * functia de dispersie
	 */
	int fctDispersie(int k) {
		return k % dim;
	}


	void actualizeazaPrimLiber();

	/*
	 * pre: key intreg, value string
	 * post: se adauga pereche key-value in dictionar
	 * returneaza True daca s-a adauga, False in caz contrar
	 */

	bool adauga(int key, string value);

	/*
	 * pre: key intreg, value string
	 * post: se sterge perechea key-value din dictionar
	 * returneaza True daca s-a sters perechea, False in caz contrar
	 */
	bool sterge(int key, string value);

	/*
	MultiMapIterator iterator(){
		return *(new MultiMapIterator(this));
	}
	 */

	/*
	 * returneaza primLiber
	 */
	int getPrimLiber(){
		return primLiber;
	}
};


class MultiDictionarIt{
	friend class MultiDictionar;

private:
	MultiDictionar* md;
	int current;

public:
	/*
	 * pre : mdict pointer la MultiDictionar
	 * post : se creaza iteratorul pe TAD iar
	 * current refera primul elem din dictionar
	 */
	MultiDictionarIt(MultiDictionar* mdict){
		this->current = 0;
		md = mdict;
	}

	/*
	 * current refera primul elem din dictionar
	 */
	void prim(){
		current = 0;
		while (md->keys[current] == -1){
			current++;
		}
	}

	/*
	 * post: curent va referi urmatorul element din dictionar
	 */
	void urmator(){
		current++;
		while(md->keys[current] == -1 && current <= MAX){
			current++;
		}
	}

	/*
	 * post: returneaza True daca current refera o pozitie valida
	 * din dictionar, False in caz contrar
	 */
	bool valid(){
		if(current < MAX && md->keys[current] != -1)
			return true;
		else
			return false;
	}

	/*
	 * returneaza pozitia elementului curent
	 */
	int getCurrent(){
		return current;
	}

	/*
	 * post : returneaza cheia elemetului curent i
	 */
	int getKey(int i){
		return md->keys[i];
	}

	/*
	 * post : returneaza valoarea elemetului curent i
	 */
	string getValue(int i){
		return md->values[i];
	}

	/*
	 * returneaza valoarea din vectorul next de pe pozitia i
	 */
	int getNext(int i){
		return md->next[i];
	}


} typedef MultiDictionarIt;
#endif /* MULTIDICT_H_ */
