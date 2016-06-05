/*
 * app.cpp
 *
 *  Created on: 28.06.2012
 *      Author: Cristian Mihok
 */

#include <iostream>
#include <string>
#include "domain/MultiMap.h"
//#include "domain/test.h"
#include "repository/WardrobeRepository.h"
#include "ui/WardrobeUI.h"

using namespace std;

int main(){

	//testMultiMap();

	Wardrobe *wardrobeRepo = new Wardrobe;
	WardrobeUI *wardrobeUI = new WardrobeUI(wardrobeRepo);


	wardrobeUI->showMenu();


	delete (wardrobeUI);

	return 0;

}
