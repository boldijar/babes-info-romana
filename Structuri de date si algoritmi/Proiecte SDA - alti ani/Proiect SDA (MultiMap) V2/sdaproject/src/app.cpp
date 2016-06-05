/*
 * app.cpp
 *
 *  Created on: 29.05.2012
 *      Author: Emilian
 */

#include <iostream>
#include <string>
#include "domain/multimap.h"
#include "domain/testmultimap.h"
#include "repository/repository.h"
#include "ui/ui.h"

using namespace std;

int main(){

	testMultiMap();

	Hotel *hotelrepo = new Hotel;
	Ui *ui = new Ui(hotelrepo);


	ui->showMenu();


	delete (ui);
//	delete (hotelrepo);
	return 0;

}
