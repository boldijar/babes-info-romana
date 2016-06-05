/*
 * menus.cpp
 *
 *  Created on: 18 Mar 2012
 *      Author: ilazar
 */

#include "ui.h"
#include "domain.h"

#include <iostream>

using namespace std;
using namespace Domain;

namespace Ui {

const char* MenuItem::COLON = ": ";
const char* MenuItem::ACTION_NOT_YET_IMPLEMENTED = "Action not yet implemented.";
const char* MenuItem::MENU = "Menu";
const char* MenuItem::RETURN = "Return";
const char* MenuItem::UNKNOWN_COMMAND = "Unknown command.";

void MenuItem::execute() const {
	if (_action != 0) {
		_action->execute();
	} else {
		cout << ACTION_NOT_YET_IMPLEMENTED << endl;
	}
}

ostream& operator<<(ostream& out, const MenuItem& menuItem) {
	out << menuItem._text;
	return out;
}

Menu& Menu::add(MenuItem* menuItem) {
	_menuItems.push_back(menuItem);
	return *this;
}

void Menu::execute() const {
	while (true) {
		try {
			cout << MENU << COLON << _text << endl;
			size_t menuItemsSize = _menuItems.size();
			for (size_t i = 0; i < menuItemsSize; i++) {
				cout << i << COLON << *_menuItems[i] << endl;
			}
			cout << _menuItems.size() << COLON << RETURN << endl;
			size_t commandIndex = 0;
			cin >> commandIndex;
			if (0 <= commandIndex && commandIndex < menuItemsSize) {
				try {
					_menuItems[commandIndex]->execute();
				} catch (NotYetImplementedError& e) {
					cout << e.getMessage();
				}
			} else if (commandIndex == menuItemsSize) {
				return;
			} else {
				cout << UNKNOWN_COMMAND << endl;
			}
		} catch (Error& e) {
			cout << e.getMessage() << endl;
		}
	}
}

Action::~Action() {
}

void NewSale::execute() {
	bool makingNewSales = true;
	while (makingNewSales) {
		cout << "0: Make new sale\n1: Return" << endl;
		int commandIndex;
		cin >> commandIndex;
		switch (commandIndex) {
		case 0:
			makeNewSale();
			break;
		case 1:
			makingNewSales = false;
			break;
		default:
			cout << "Unknown command" << endl;
			break;
		}
	}
}

void NewSale::makeNewSale() {
	bool endOfSale = false;
	pos->newSale();
	while (!endOfSale) {
		cout << "Enter product code: ";
		int productCode;
		cin >> productCode;
		Product* product = pos->getProductByCode(productCode);
		if (product == 0) {
			cout << "Unknown product." << endl;
			continue;
		}
		cout << "Product description: " << product->getDescription() << endl;
		cout << "Enter quantity: ";
		double quantity;
		cin >> quantity;
		try {
			pos->enterSaleItem(quantity, product);
			cout << "Sale total: " << pos->getSaleTotal() << endl;
		} catch (ValidationError& err) {
			cout << err.getMessage() << endl;
		}
		cout << "0: End sale\n1: Continue adding items";
		int command;
		cin >> command;
		if (command == 0) {
			pos->endSale();
			endOfSale = true;
		}
	}

}

NewSale::~NewSale() {
}

void SaleReport::execute() {
	throw NotYetImplementedError("Sale Report is not yet implemented.");
}

SaleReport::~SaleReport() {
}

void MonetaryReport::execute() {
	throw NotYetImplementedError("Monetary Report is not yet implemented.");
}

MonetaryReport::~MonetaryReport() {
}

}
