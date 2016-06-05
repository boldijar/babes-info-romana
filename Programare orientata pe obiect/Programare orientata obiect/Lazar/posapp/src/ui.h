/*
 * menus.h
 *
 *  Created on: 18 Mar 2012
 *      Author: ilazar
 */

#ifndef MENUS_H_
#define MENUS_H_
#include <vector>
#include <string>
#include "domain.h"

using namespace std;
using namespace Domain;

namespace Ui {

class Action {
public:
	virtual void execute() = 0;
	virtual ~Action();
};

class MenuItem {
public:
	MenuItem(const string text, Action* action = 0) :
			_text(text), _action(action) {
	}
	virtual void execute() const;
	friend ostream& operator<<(ostream& out, const MenuItem& menuItem);
	virtual ~MenuItem() {
	}
protected:
	string _text;
	Action* _action;
	static const char* COLON;
	static const char* ACTION_NOT_YET_IMPLEMENTED;
	static const char* MENU;
	static const char* RETURN;
	static const char* UNKNOWN_COMMAND;
};

class Menu: public MenuItem {
public:
	Menu(string text) :
			MenuItem(text) {
	}
	virtual void execute() const;
	Menu& add(MenuItem* menuItem);
	virtual ~Menu() {
	}
private:
	vector<MenuItem*> _menuItems;
};

class NewSale: public Action {
public:
	NewSale(POS* pos) : pos(pos) {}
	virtual void execute();
	virtual ~NewSale();
private:
	POS* pos;
	void makeNewSale();
};

class SaleReport: public Action {
public:
	virtual void execute();
	virtual ~SaleReport();
};

class MonetaryReport: public Action {
public:
	virtual void execute();
	virtual ~MonetaryReport();
};
}

#endif /* MENUS_H_ */
