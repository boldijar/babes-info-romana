/*
 * ConsoleUI.h
 *
 *  Created on: Jun 7, 2012
 *      Author: Admin
 */

#ifndef CONSOLEUI_H_
#define CONSOLEUI_H_

#include "../Controller/ContainerController.h"

class ConsoleUI {
public:
	ConsoleUI(ContainerController* ctrl) : ctrl(ctrl) {}
	void showUI();

private:
	ContainerController* ctrl;
	void showMenu();
	void adaugaContainer();
	void stergeContainer();
	void cautaContainer();
	void afiseazaContainere();
};




#endif /* CONSOLEUI_H_ */
