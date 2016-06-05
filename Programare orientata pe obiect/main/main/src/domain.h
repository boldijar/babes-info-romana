/*
 * domain.h
 *
 *  Created on: Mar 4, 2015
 *      Author: andrei
 */

#ifndef DOMAIN_H_
#define DOMAIN_H_

struct car{
	char* licenta;
	char* model;
	char* categorie;
	int* inchiriat;//0 inchiriat; 1 disponibil;
};

typedef struct car Car;

#endif /* DOMAIN_H_ */
