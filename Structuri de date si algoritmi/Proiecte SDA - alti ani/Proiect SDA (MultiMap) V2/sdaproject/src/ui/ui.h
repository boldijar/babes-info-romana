/*
 * ui.h
 *
 *  Created on: 07.06.2012
 *      Author: Emilian
 */

#ifndef UI_H_
#define UI_H_

#include <iostream>
#include <string>
#include"../repository/repository.h"

class Ui{
private:
	Hotel *repo;

public:
	Ui(Hotel *hotel);

	/*destructor, elibereaza memoria folosita*/
	~Ui();

	/*afiseaza meniul si preia comanda*/
	void showMenu();

	/*executa comanda primita de la meniu*/
	void execMenu(char cmd);


};


#endif /* UI_H_ */
