/*
 * WardrobeUI.h
 *
 *  Created on: 28.06.2012
 *      Author: Cristian Mihok
 */

#ifndef WARDROBEUI_H_
#define WARDROBEUI_H_

#include <iostream>
#include <string>
#include"../repository/WardrobeRepository.h"

class WardrobeUI{
private:
	Wardrobe *wRepository;

public:
	WardrobeUI(Wardrobe *wardrobe);

	~WardrobeUI();

	void showMenu();

	void run(char enter);


};


#endif /* WARDROBEUI_H_ */
