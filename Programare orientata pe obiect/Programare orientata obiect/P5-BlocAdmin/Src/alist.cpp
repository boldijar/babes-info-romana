/*
 * alist.cpp
 *
 *  Created on: 24.03.2012
 *      Author: Florin Mihalache
 */

#include "alist.h"
#include <iostream>
#define DEFAULT_MAX_SIZE 30
using namespace std;

Apartment::Apartment() {
	this->number = -1;
	this->eSize = 0;
	this->eCapacity = DEFAULT_MAX_SIZE;
	this->eList = new Expense[DEFAULT_MAX_SIZE];
}

Apartment::~Apartment() {
	delete this->eList;
}

int Apartment::size() {
	return this->eSize;
}

void Apartment::add(string type, float amount) {
	if (this->eSize == this->eCapacity) {
		int new_eCapacity = this->eCapacity + this->eCapacity / 2;
		Expense* new_eList = new Expense[new_eCapacity];
		for (int i = 0; i < this->eCapacity; i++) {
			new_eList[i] = this->eList[i];
		}
		delete this->eList;
		this->eList = new_eList;
		this->eCapacity = new_eCapacity;
	}
	this->eList[this->eSize].amount = amount;
	this->eList[this->eSize].type = type;
	this->eSize++;
}

void Apartment::removeByID(int id) {
	for (int i = id; i < this->eSize - 1; i++) {
		this->eList[i] = this->eList[i+1];
	}
	this->eSize--;
}

void Apartment::removeByType(string type) {
	for (int i = 0; i < this->eSize; i++) {
		if (this->eList[i].type == type) {
			this->removeByID(i);
			i--;
		}
	}
}

void Apartment::sort() {
	if (this->eSize > 1) {
		bool ok = false;
		int i, j = 0;
		Expense tmp;
		while (!ok) {
			ok = true;
			j++;
			for (i = 0; i < this->eSize - j; i++) {
				if (this->eList[i].amount > this->eList[i+1].amount) {
					ok = false;
					tmp = this->eList[i];
					this->eList[i] = this->eList[i+1];
					this->eList[i+1] = tmp;
				}
			}
		}
	}
}



/************************
 * Apartments list
 ***********************/

aptList::aptList() {
	this->aSize = 0;
	this->aCapacity = DEFAULT_MAX_SIZE;
	this->aList = new Apartment[DEFAULT_MAX_SIZE];
	this->cpList = new Apartment[DEFAULT_MAX_SIZE];
}

aptList::~aptList() {
	delete this->aList;
}

int aptList::size() {
	return this->aSize;
}

void aptList::add(int number) {
	if (this->aSize == this->aCapacity) {
		int new_aCapacity = this->aCapacity + this->aCapacity / 2;
		Apartment* new_aList = new Apartment[new_aCapacity];
		for (int i = 0; i < this->aCapacity; i++) {
			new_aList[i] = this->aList[i];
		}
		delete this->aList;
		this->aList = new_aList;
		this->aCapacity = new_aCapacity;
	}
	this->aList[this->aSize].number = number;
	this->aSize++;
}

void aptList::insert(int aptNumber, string type, float amount) {
	this->saveCopy();
	Apartment* apt = this->getAptByNumber(aptNumber);

	if (apt != 0) // the apartment has been found
		apt->add(type, amount);
	else { // no apartment found => add it
		this->add(aptNumber);
		this->aList[this->aSize - 1].add(type, amount);
	}

}

Apartment* aptList::getAptByNumber(int aptNumber) {
	for (int i = 0; i < this ->aSize; i++) {
		if (this->aList[i].number == aptNumber) {
			return &aList[i];
		}
	}
	return 0;
}

void aptList::remove(int aptNumber) {
	Apartment* apt = this->getAptByNumber(aptNumber);
	apt->eSize = 0;
}

void aptList::remove(int fromAptNumber, int toAptNumber) {
	for (int i = 0; i < this->aSize; i++) {
		if ((this->aList[i].number >= fromAptNumber) && (this->aList[i].number <= toAptNumber)) {
			this->aList[i].eSize = 0;
		}

	}
}

void aptList::removeAllByType(string type) {
	for (int i = 0; i < this->aSize; i++) {
		this->aList[i].removeByType(type);
	}
}

void aptList::filterByType(string type) {
	for (int i = 0; i < this->aSize; i++) {
		if (this->aList[i].eSize > 0) {
			for (int j = 0; j < this->aList[i].eSize; j++) {
				if (this->aList[i].eList[j].type != type) {
					this->aList[i].removeByID(j);
					j--; // check again
				}
			}
		}
	}
}

void aptList::filterGreaterThan(float amount) {
	for (int i = 0; i < this->aSize; i++) {
		if (this->aList[i].eSize > 0) {
			for (int j = 0; j < this->aList[i].eSize; j++) {
				if (this->aList[i].eList[j].amount < amount) {
					this->aList[i].removeByID(j);
					j--; // check again
				}
			}
		}
	}
}

void aptList::saveCopy() {
	this->cpSize = this->aSize;

	this->cpCapacity = this->aCapacity;
	this->cpList = new Apartment[this->cpCapacity];
	for (int i = 0; i < this->aSize; i++) {
		this->cpList[i] = this->aList[i];
	}
}

void aptList::undo() {
	this->aSize = this->cpSize;
	this->aCapacity = this->cpCapacity;
	this->aList = new Apartment[this->aCapacity];
	for (int i = 0; i < this->cpSize; i++) {
		this->aList[i] = this->cpList[i];
	}
}
