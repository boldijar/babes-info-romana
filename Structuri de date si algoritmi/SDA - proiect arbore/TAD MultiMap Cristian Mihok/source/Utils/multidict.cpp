/*
 * multidict.cpp
 *
 *  Created on: 27.05.2012
 *      Author: Cristian Mihok
 */
#include "multidict.h"

/*
 * Constructor multidictionar
 */
MultiDictionar::MultiDictionar() {
	dim = MAX;
	primLiber = 0;
	for (int i = 0; i < dim; i++) {
		keys[i] = -1;
		next[i] = -1;
		values[i] = "";
	}
}

/*
 * actualizeaza primliber
 */
void MultiDictionar::actualizeazaPrimLiber() {
	while (primLiber <= dim && keys[primLiber] != -1)
		primLiber++;
}

 /*
 * pre:  key intreg, value String
 * post: se adauga in dictionar perechea key-value
 * returneaza True daca s-a aduagat perechea
 * False in caz contrar
 */
bool MultiDictionar::adauga(int key, string value) {
	int dis;
	dis = this->fctDispersie(key);
	if (this->keys[dis] == -1) {
		this->keys[dis] = key;
		this->values[dis] = value;
		if (this->primLiber == dis) {
			actualizeazaPrimLiber();
		}
		return true; //s-a adaugat cheie valoare
	} else {
		int prev;
		while (dis != -1 && (this->keys[dis] != key || this->values[dis] != value)) {
			prev = dis;
			dis = this->next[dis];
		}
		if (dis != -1) {
			return false; //cheie existenta
		} else {
			if (this->primLiber == this->dim) {
				return false; //se depaseste dim dictionarului
			} else {
				this->keys[this->primLiber] = key;
				this->values[this->primLiber] = value;
				this->next[prev] = this->primLiber;
				this->actualizeazaPrimLiber();
				return true; //s-a adaugat perechea cheie valoare
			}
		}
	}
}

/*
 * pre: key intreg, value String
 * post: se adauga in dictionar perechea key-value
 * returneaza True daca s-a sters perechea
 * False in caz contrar
 */
bool MultiDictionar::sterge(int key, string value) {
	int prev = -1;//j
	int dis = this->fctDispersie(key);//i

	while (dis != -1 && (this->keys[dis] != key || this->values[dis] != value)) {
		prev = dis;
		dis = this->next[dis];
	}
	if (dis == -1) {
		return false; // cheie inexistenta
	} else {
		bool done = false;
		do {
			int pprev = dis;
			int p = this->next[dis];
			while (p != -1 && this->fctDispersie(this->keys[p]) != dis) {
				pprev = p;
				p = this->next[p];
			}
			if (p == -1)
				done = true;
			else {
				this->keys[dis] = this->keys[p];
				this->values[dis] = this->values[p];
				prev = pprev;
				dis = p;
			}
		} while (done != true);
		if (prev != -1) {
			this->next[prev] = this->next[dis];
		}
		this->keys[dis] = -1;
		this->next[dis] = -1;
		this->values[dis] = "";
		if (dis < this->primLiber)
			this->primLiber = dis;
		return true;
	}
}
