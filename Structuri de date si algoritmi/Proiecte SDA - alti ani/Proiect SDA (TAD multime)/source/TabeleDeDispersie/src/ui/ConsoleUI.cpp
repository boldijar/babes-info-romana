/*
 * ConsoleUI.cpp
 *
 *  Created on: Jun 7, 2012
 *      Author: Admin
 */

/*
 * ConsoleUI.cpp
 *
 *  Created on: 30.05.2012
 *      Author: Florin Mihalache
 */

#include "ConsoleUI.h"
#include <iostream>
using namespace std;

void ConsoleUI::showMenu() {
	cout << endl;
	cout << "*** Meniu" << endl;
	cout << "  1. Arata acest meniu" << endl;
	cout << "  2. Adauga CNP in baza de date" << endl;
	cout << "  3. Sterge CNP din baza de date" << endl;
	cout << "  4. Cauta CNP" << endl;
	cout << "  5. Afiseaza toate CNP-urile din baza de date" << endl;
	cout << "  0. Inchide aplicatia" << endl;
}

void ConsoleUI::showUI() {
	int cmd = 1;
	while (cmd != 0) {
		if (cmd == 1) {
			showMenu();
		}
		if (cmd == 2) {
			adaugaContainer();
		}
		if (cmd == 3) {
			stergeContainer();
		}
		if (cmd == 4) {
			cautaContainer();
		}
		if (cmd == 5) {
			afiseazaContainere();
		}

		cout << ">> ";
		cin >> cmd;
	}
}

void ConsoleUI::adaugaContainer() {
	string cnp;
	cout << "CNP: ";
	cin >> cnp;
	ctrl->add(cnp);
	cout << "CNP-ul " << cnp << " a fost adaugat." << endl;
}

void ConsoleUI::stergeContainer() {
	if (ctrl->size() == 0) {
		cout << "Baza de date este goala..." << endl;
	} else {
		string cnp;
		cout << "CNP: ";
		cin >> cnp;
		if (ctrl->search(cnp)) {
			ctrl->remove(cnp);
			cout << "CNP-ul " << cnp << " a fost sters." << endl;
		} else {
			cout << "CNP-ul nu a fost gasit in baza de date." << endl;
		}
	}
}

void ConsoleUI::cautaContainer() {
	string cnp;
	cout << "CNP: ";
	cin >> cnp;
	if (ctrl->search(cnp))
		cout << "CNP-ul a fost gasit in baza de date." << endl;
	else
		cout << "CNP-ul nu a fost gasit in baza de date." << endl;
}

void ConsoleUI::afiseazaContainere() {
	if (ctrl->size() == 0)
		cout << "Baza de date este goala." << endl;
	else {
		IteratorMultime<Container> it = ctrl->getMul()->iterator();
		cout << ctrl->size() << " CNP-uri:" << endl;
		while (it.valid()) {
			cout << "\t" << it.element().getCnp() << endl;
			it.next();
		}
	}
}


