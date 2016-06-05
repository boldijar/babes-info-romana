/*
 * ui.cpp
 *
 *  Created on: 24.03.2012
 *      Author: Florin Mihalache
 */
#include <iostream>
#include <string>
#include <map>
#include "alist.h"
#define CURRENCY "RON"
using namespace std;

void writeGreaterThan(aptList* apts, float amount) {
	int k = 0, sum;
	for (int i = 0; i < apts->aSize; i++) {
		sum = 0;
		if (apts->aList[i].eSize > 0) {
			for (int j = 0; j < apts->aList[i].eSize; j++) {
				sum += apts->aList[i].eList[j].amount;
			}

			if (sum > amount) {
				if (k == 0) {
					cout << "Apartments with overall expenses greater than " << amount << ":" << endl << "\t";
				}
				cout << apts->aList[i].number << " ";
				k++;
			}
		}
	}
	if (k == 0)
		cout << "No apartments with overall expenses greater than " << amount << " found." << endl;
	else
		cout << endl;
}

void writeLessThan(aptList* apts, float amount, int aptNumber) {
	int k = 0, sum;
	for (int i = 0; i < apts->aSize; i++) {
		sum = 0;
		if ((apts->aList[i].eSize > 0) && (apts->aList[i].number <= aptNumber)) {
			for (int j = 0; j < apts->aList[i].eSize; j++) {
				sum += apts->aList[i].eList[j].amount;
			}

			if (sum < amount) {
				if (k == 0) {
					cout << "Apartments with overall expenses less than " << amount << ":" << endl << "\t";
				}
				cout << apts->aList[i].number << " ";
				k++;
			}
		}
	}
	if (k == 0)
		cout << "No apartments with overall expenses less than " << amount
			<< " and before apartment " << aptNumber << " found." << endl;
	else
		cout << endl;
}

void writeAllType(aptList* apts, string type) {
	int k = 0, kk;
	for (int i = 0; i < apts->aSize; i++) {
		kk = 0;
		if (apts->aList[i].eSize > 0) {
			for (int j = 0; j < apts->aList[i].eSize; j++) {
				if (apts->aList[i].eList[j].type == type) {
					if (kk == 0)
						cout << "Apartment " << apts->aList[i].number << ":" << endl;
					cout << "\t" << apts->aList[i].eList[j].amount << " " << CURRENCY << endl;
					kk++;
					k++;
				}
			}
		}
	}
	if (k == 0)
		cout << "No apartments with the specified type of expense (" << type << ") found." << endl;
}

void writeSold(aptList* apts, int aptNumber) {
	float sold = 0;
	Apartment* apt = apts->getAptByNumber(aptNumber);
	if (apt->eSize > 0){
		for (int i = 0; i < apt->eSize; i++) {
			sold += apt->eList[i].amount;
		}
		cout << "Sold for apartment " << apt->number << ": " << sold << " " << CURRENCY << endl;
	}
	else
		cout << "Sold for apartment " << apt->number << ": 0" << " " << CURRENCY << endl;
}

void writeSumType(aptList* apts, string type) {
	float sum = 0;
	for (int i = 0; i < apts->aSize; i++) {
		if (apts->aList[i].eSize > 0)
			for (int j = 0; j < apts->aList[i].eSize; j++) {
				if (apts->aList[i].eList[j].type == type)
					sum += apts->aList[i].eList[j].amount;
			}
	}
	cout << "Total amount for \"" << type << "\": " << sum << " " << CURRENCY << endl;
}

void writeMaxType(aptList* apts, int aptNumber) {
	map <string, float> expMax;
	map <string, float>::iterator it;
	Apartment* apt = apts->getAptByNumber(aptNumber);
	if (apt->eSize == 0)
		cout << "No expenses found at apartment " << aptNumber << "." << endl;
	else {
		for (int i = 0; i < apt->eSize; i++) {
			if (expMax.count(apt->eList[i].type)) {
				if (expMax[apt->eList[i].type] < apt->eList[i].amount)
					expMax[apt->eList[i].type] = apt->eList[i].amount;
			}
			else
				expMax[apt->eList[i].type] = apt->eList[i].amount;
		}
		cout << "Maximum expense per type for apartment " << aptNumber << ":" << endl;
		for (it = expMax.begin(); it != expMax.end(); it++) {
			cout << "\t" << it->first << ": " << it->second << " " << CURRENCY << endl;
		}
	}
}

void printMenu() {
	cout << endl;
	cout << "*** Main menu" << endl;
	cout << "   1. Show all expenses" << endl;
	cout << "   2. Add new expense" << endl;
	cout << "   3. Modify expenses" << endl;
	cout << "   4. Write the expenses having different properties" << endl;
	cout << "   5. Obtain different characteristics of expenses" << endl;
	cout << "   6. Filter the list of expenses" << endl;
	cout << "   7. Undo" << endl;
	cout << "   0. Exit" << endl;
}

void showAll(aptList* apts) {
	if (apts->aSize == 0)
		cout << "No expenses in the list." << endl;
	else {
		for (int i = 0; i < apts->aSize; i++) {
			if (apts->aList[i].eSize > 0) {
				cout << "Apartment " << apts->aList[i].number << ": " << endl;
				for (int j = 0; j < apts->aList[i].eSize; j++) {
					cout << "\t" << apts->aList[i].eList[j].type << ": " << apts->aList[i].eList[j].amount
							<< " " << CURRENCY << endl;
				}
				cout << endl;
			}
		}
	}
}

void addExpense(aptList* apts) {
	int aptNumber;
	string type;
	float amount;
	cout << "Apartment number: ";
	cin >> aptNumber;
	if (aptNumber <= 0) {
		cout << "The apartment number must be a positive integer!" << endl;
		return;
	}
	cout << "Type: ";
	cin >> type;
	cout << "Amount: ";
	cin >> amount;
	if (amount <= 0) {
		cout << "The amount can't pe negative!" << endl;
		return;
	}
	apts->insert(aptNumber, type, amount);
	cout << "Expense added." << endl;
}

void removeExpAptUi(aptList* apts) {
	int aptNumber;
	cout << "Apartment number: ";
	cin >> aptNumber;
	if (aptNumber <= 0) {
		cout << "The apartment number must be a positive integer!" << endl;
		return;
	}
	if (apts->getAptByNumber(aptNumber) == 0) {
		cout << "Apartment not found!" << endl;
		return;
	}
	apts->remove(aptNumber);
	cout << "Expenses removed." << endl;
}

void removeExpRangeUi(aptList* apts) {
	int fromAptNumber, toAptNumber;
	cout << "From apartment number: ";
	cin >> fromAptNumber;
	if (fromAptNumber <= 0) {
		cout << "The apartment number must be a positive integer!" << endl;
		return;
	}
	cout << "To apartment number: ";
	cin >> toAptNumber;
	if (toAptNumber <= 0) {
		cout << "The apartment number must be a positive integer!" << endl;
		return;
	}
	apts->remove(fromAptNumber, toAptNumber);
	cout << "Expenses removed." << endl;
}

void removeAllByTypeUi(aptList* apts) {
	string type;
	cout << "Type: ";
	cin >> type;
	apts->removeAllByType(type);
	cout << "Expenses removed." << endl;
}

void writePropertiesUi(aptList* apts) {
	int cmd, aptNumber;
	float amount;
	string type;
		while (true) {
			cout << endl;
			cout << "*** Write the expenses having different properties" << endl;
			cout << "   1. Writes all the apartments with an overall expense greater than a given amount" << endl;
			cout << "   2. Writes apartments from 1 to a given apartment number with an overall expense less than a given amount" << endl;
			cout << "   3. Writes all the expenses having the specified type" << endl;
			cout << "   4. Writes the sold (total amount of expenses) for given apartment" << endl;
			cout << "   0. Return to main menu" << endl;
			cout << ">> ";
			cin >> cmd;

			if (cmd == 0)
				return;
			else
			if (cmd == 1) {
				cout << "Amount: ";
				cin >> amount;
				if (amount <= 0) {
					cout << "The amount can't pe negative!" << endl;
					return;
				}
				writeGreaterThan(apts, amount);
			}
			else
			if (cmd == 2) {
				cout << "Amount: ";
				cin >> amount;
				if (amount <= 0) {
					cout << "The amount can't pe negative!" << endl;
					return;
				}
				cout << "Apartment number: ";
					cin >> aptNumber;
					if (aptNumber <= 0) {
						cout << "The apartment number must be a positive integer!" << endl;
						return;
					}
				writeLessThan(apts, amount, aptNumber);
			}
			else
			if (cmd == 3) {
				cout << "Type: ";
				cin >> type;
				writeAllType(apts, type);
			}
			else
			if (cmd == 4) {
				cout << "Apartment number: ";
				cin >> aptNumber;
				if (aptNumber <= 0) {
					cout << "The apartment number must be a positive integer!" << endl;
					return;
				}
				if (apts->getAptByNumber(aptNumber) == 0)
					cout << "Apartment not found." << endl;
				else
					writeSold(apts, aptNumber);
			}
			else
				cout << "Unknown command" << endl;
		}
}


void modifyExpenses(aptList* apts) {
	int cmd;
		while (true) {
			cout << endl;
			cout << "*** Modify expenses" << endl;
			cout << "   1. Remove all the expenses at given apartment" << endl;
			cout << "   2. Remove all the expenses from a range of apartments" << endl;
			cout << "   3. Remove all expenses of a given type" << endl;
			cout << "   0. Return to main menu" << endl;
			cout << ">> ";
			cin >> cmd;

			if (cmd == 0)
				return;
			else
			if (cmd == 1)
				removeExpAptUi(apts);
			else
			if (cmd == 2)
				removeExpRangeUi(apts);
			else
			if (cmd == 3)
				removeAllByTypeUi(apts);
			else
				cout << "Unknown command" << endl;
		}
}

void obtainChUi(aptList* apts) {
	int cmd, aptNumber;
	string type;
		while (true) {
			cout << endl;
			cout << "*** Obtain different characteristics of expenses" << endl;
			cout << "   1. Writes the total amount for the expenses having the specified type" << endl;
			cout << "   2. Writes the maximum expense per type for given apartment" << endl;
			cout << "   3. Sort total expenses per apartment in an ascending order" << endl;
			cout << "   0. Return to main menu" << endl;
			cout << ">> ";
			cin >> cmd;

			if (cmd == 0)
				return;
			else
			if (cmd == 1) {
				cout << "Type: ";
				cin >> type;
				writeSumType(apts, type);
				}
			else
			if (cmd == 2) {
				cout << "Apartment number: ";
				cin >> aptNumber;
				if (aptNumber <= 0) {
					cout << "The apartment number must be a positive integer!" << endl;
					return;
				}
				if (apts->getAptByNumber(aptNumber) == 0)
					cout << "Apartment not found." << endl;
				else
					writeMaxType(apts, aptNumber);
			}
			else
			if (cmd == 3) {
				for (int i = 0; i < apts->aSize; i++) {
					apts->aList[i].sort();
				}
				cout << "The list has been sorted." << endl;
			}
			else
				cout << "Unknown command" << endl;
		}
}

void filterListUi(aptList* apts) {
	int cmd;
	float amount;
	string type;
		while (true) {
			cout << endl;
			cout << "*** Filter the list of expenses" << endl;
			cout << "   1. Retains only the expenses having the specified type" << endl;
			cout << "   2. Retains only the overall expenses greater than given amount" << endl;
			cout << "   0. Return to main menu" << endl;
			cout << ">> ";
			cin >> cmd;

			if (cmd == 0)
				return;
			else
			if (cmd == 1) {
				cout << "Type: ";
				cin >> type;
				apts->filterByType(type);
				cout << "The list has been filtered." << endl;
				}
			else
			if (cmd == 2) {
				cout << "Amount: ";
				cin >> amount;
				if (amount <= 0) {
					cout << "The amount can't pe negative!" << endl;
					return;
				}
				apts->filterGreaterThan(amount);
				cout << "The list has been filtered." << endl;
			}
			else
				cout << "Unknown command" << endl;
		}
}

void undoUi(aptList* apts) {
	apts->undo();
	cout << "Last operation cancelled" << endl;
}

void menu(aptList* apts) {
	int cmd;
	while (true) {
		printMenu();
		cout << ">> ";
		cin >> cmd;

		if (cmd == 0)
			return;
		else
		if (cmd == 1)
			showAll(apts);
		else
		if (cmd == 2)
			addExpense(apts);
		else
		if (cmd == 3)
			modifyExpenses(apts);
		else
		if (cmd == 4)
			writePropertiesUi(apts);
		else
		if (cmd == 5)
			obtainChUi(apts);
		else
		if (cmd == 6)
			filterListUi(apts);
		else
		if (cmd == 7)
			undoUi(apts);
		else
			cout << "Unknown command" << endl;
	}
}
