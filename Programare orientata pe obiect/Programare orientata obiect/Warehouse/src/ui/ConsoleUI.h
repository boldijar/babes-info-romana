/*
 * ConsoleUI.h
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#ifndef CONSOLEUI_H_
#define CONSOLEUI_H_
#include "../controller/Warehouse.h"
class ConsoleUI {

public:
	ConsoleUI(Warehouse *wha);
	void showUI();
private:
	Warehouse* wh;
	void addProduct();
	void showMenu();
};

#endif /* CONSOLEUI_H_ */
