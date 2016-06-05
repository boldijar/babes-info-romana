/*
 * ConsoleUI.cpp
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#include "ConsoleUI.h"
#include <iostream>

ConsoleUI::ConsoleUI(Warehouse *wha) {
	wh = wha;
}

void ConsoleUI::showMenu() {
	cout << "1 - show menu" << endl;
	cout << "2 - add product" << endl;
	cout << "3 - search product" << endl;
	cout << "10 - exit app" << endl;
}

void ConsoleUI::addProduct() {
	int code = 0;
	cout << "Give product code:";
	cin >> code;
	cout << "Give product description:";
	string desc;
	cin >> desc;
	cout << "Give product price:";
	double price;
	cin >> price;
	try {
		Product p = wh->addProduct(code, desc, price);
		cout << "product " << p.getDescription() << " added." << endl;
	} catch (MyException ex) {
		cout << "Error on store:" << ex.getMsg() << endl;
	}
}

//void ConsoleUI::searchProduct() {
//	cout << "TODO! immplemented this";
//}

void ConsoleUI::showUI() {
	int cmd = 1;
	while (cmd != 10) {
		if (cmd == 1) {
			showMenu();
		}
		if (cmd == 2) {
			addProduct();
		}
		cout << "Give command (1 for menu):" << endl;
		cin >> cmd;
	}

}

