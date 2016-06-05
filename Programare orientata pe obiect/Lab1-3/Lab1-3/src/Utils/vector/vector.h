/*
 * vector.h
 *
 *  Created on: Mar 5, 2015
 *      Author: Nexflame
 */

#ifndef ENTITY_VECTOR_VECTOR_H_
#define ENTITY_VECTOR_VECTOR_H_

#include <stdio.h>
#include "../utils.h"

#define VECTOR_INITIAL_CAPACITY 10

typedef struct struct_Vector
{
	Element* entities;
	int size;
	int capacity;
}Vector;

// Private:
int vector__getCapacity(Vector* this);
void vector__setCapacity(Vector* this, int newCapacity);
void vector__incLen(Vector* this);
void vector__setLen(Vector* this, int newLen);

// Public:
void vector_init(Vector* this);
void vector_destroy(Vector* this);
// !!!At pushBack you should use intptr_t to add ints!!!
void vector_pushBack(Vector* this, Element entity);
void vector_removeAt(Vector* this, int pos);
int vector_getLen(Vector* this);
Element vector_getAt(Vector* this, int pos);


#endif /* ENTITY_VECTOR_VECTOR_H_ */
