/*
 * alist.h
 *
 *  Created on: 24.03.2012
 *      Author: Florin Mihalache
 */

#ifndef ALIST_H_
#define ALIST_H_

#include <string>
using namespace std;

struct Apartment {
	struct Expense {
		float amount;
		string type;
	};

	int number; // apartment number
	Expense* eList; // expenses list
	int eSize;
	int eCapacity;

	/* Initializes the apartment
	 * Post: eSize == 0
	 * 		 number == -1
	 */
	Apartment();

	/* Destroys the apartment */
	~Apartment();

	/* Returns the size of expenses list */
	int size();

	/* Adds expense to the list */
	void add(string type, float amount);

	/* Removes expense by index */
	void removeByID(int id);

	/* Removes all expenses by type */
	void removeByType(string type);

	/* Sorts expenses in an ascending order */
	void sort();
};

struct aptList {
	Apartment* aList; // apartments list
	int aSize;
	int aCapacity;
	Apartment* cpList; // apartments list, for undo
	int cpSize;
	int cpCapacity;

	/* Initializes the apartments list
	 * Post: aSize == 0
	 */
	aptList();

	/* Destroys the apartments list */
	~aptList();

	/* Returns the size of apartments list */
	int size();

	/* Adds apartment to the list */
	void add(int number);

	/* Inserts expense at given apartment */
	void insert(int aptNumber, string type, float amount);

	/* Removes all the expenses at given apartment */
	void remove(int aptNumber);

	/* Removes all the expenses from a range of apartments */
	void remove(int fromAptNumber, int toAptNumber);

	/* Returns a pointer to apartment, by number */
	Apartment* getAptByNumber(int aptNumber);

	/* Removes all expenses of a given type */
	void removeAllByType(string type);

	/* Retains only the expenses having the specified type */
	void filterByType(string type);

	/* Retains only the overall expenses greater than given amount */
	void filterGreaterThan(float amount);

	/* Saves a copy of the list, for undo */
	void saveCopy();

	/* The last operation that has modified the list of expenses is cancelled. */
	void undo();
};

#endif /* ALIST_H_ */
