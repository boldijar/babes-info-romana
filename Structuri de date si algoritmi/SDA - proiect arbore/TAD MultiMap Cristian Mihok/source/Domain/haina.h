/*
 * haine.h
 *
 *  Created on: 27.05.2012
 *      Author: Cristian Mihok
 */

#ifndef HAINA_H_
#define HAINA_H_

#include <string>
using namespace std;

struct haine{
	string descriere[20];
};

class Haina {
public:
	Haina();
	int getDimHaine(){
		return this->dimHaine;
	}

	//haine* getLista(){
		//return &listaHaine;
	//}

private:
	haine listaHaine[5];
	int dimHaine;
};



#endif /* HAINA_H_ */
