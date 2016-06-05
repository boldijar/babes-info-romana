/*
 * consoleUI.h
 *
 *  Created on: 27.05.2012
 *      Author: Cristian Mihok
 */

#ifndef CONSOLEUI_H_
#define CONSOLEUI_H_

class ConsoleUI{
public:
	//ConsoleUI(WardrobeController* wardrobeCtrl) : wardrobeCtrl(wardrobeCtrl) {}
	void showMenu();

private:
	void adaugaHaina();
	void stergeHaina();
	void cautaHaina();
	void listeazaHaine();
	void showMenuOpp();
};


#endif /* CONSOLEUI_H_ */
