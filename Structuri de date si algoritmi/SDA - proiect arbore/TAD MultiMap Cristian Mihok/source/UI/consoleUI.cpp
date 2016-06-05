/*
 * consoleUI.cpp
 *
 *  Created on: 27.05.2012
 *      Author: Cristian Mihok
 */

#include "consoleUI.h"
#include <iostream>
using namespace std;

void ConsoleUI::showMenuOpp(){
	cout << endl;
	cout << "*** Meniu" << endl;
	cout << "  1. Afiseaza meniu" << endl;
	cout << "  2. Adauga haina in garderoba" << endl;
	cout << "  3. Sterge haina din garderoba" << endl;
	cout << "  4. Cauta haine dupa cheie" << endl;
	cout << "  5. Afiseaza hainele din garderoba" << endl;
	cout << "  0. Exit" << endl;
}

void ConsoleUI::adaugaHaina() {
	int key;
	int nr;
	string descr;
	cout << "Cheie: ";
	cin >> key;
	cout << "nr haine: ";
	cin >> nr;
	for (int i=0; i<nr; i++){
		cout << "descriere: ";
		cin >> descr;
	}
	//wController->adauga(key, descr);
	cout << "Hanele cu cheia " << key << " au fost adaugate." << endl;
}

void ConsoleUI::showMenu(){
	int enter = 1;
	while (enter != 0) {
		if (enter == 1) {
			showMenuOpp();
		}
		if (enter == 2) {
			adaugaHaina();
		}

		if (enter == 3) {
		}

		if (enter == 4) {
		}

		if (enter == 5) {
		}

		cout << "enter: ";
		cin >> enter;
	}
}

