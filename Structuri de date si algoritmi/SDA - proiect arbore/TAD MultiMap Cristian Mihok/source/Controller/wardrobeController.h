/*
 * .cpp
 *
 *  Created on: 27.05.2012
 *      Author: Cristian Mihok
 */

#ifndef WARDROBECONTROLLER_H_
#define WARDROBECONTROLLER_H_

#include "../Repository/wardrobeRepository.h"
#include <string>
using namespace std;

class WardrobeController {
public:
	void adauga(int key, string haine);
	void sterge(int key);

	WardrobeRepository* wardrobeRepository;
};


#endif /* WARDROBECONTROLLER_H_ */
