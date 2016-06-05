/*
 * wardrobeRepository.h
 *
 *  Created on: 27.05.2012
 *      Author: Cristian Mihok
 */



#ifndef WARDROBEREPOSITORY_H_
#define WARDROBEREPOSITORY_H_
#include <string>
using namespace std;

class WardrobeRepository{
public:
	void salveaza(int key, string haina);



	void sterge(int key);

 };


#endif /* WARDROBEREPOSITORY_H_ */
