/*
* vector.c
 *
 *  Created on: Mar 9, 2015
 *      Author: Nexflame
 */

#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "test_vector.h"

void test_vectorCreateDestroy()
{
	// Normal case
	Vector vect;
	vector_init(&vect);

	assert(vect.size == 0);
	assert(vect.capacity == VECTOR_INITIAL_CAPACITY);
	assert(_msize(vect.entities) == VECTOR_INITIAL_CAPACITY * sizeof(Element));

	vector_destroy(&vect);

	assert(vect.size == 0);
	assert(vect.capacity == 0);
	assert(_msize(vect.entities) == -1);
}

void test_vectorPtrCreateDestroy()
{
	// Pointer Case
	Vector* vectPtr =  malloc(sizeof(Vector));
	assert(_msize(vectPtr) == sizeof(Vector));

	vector_init(vectPtr);

	assert(vectPtr->size == 0);
	assert(vectPtr->capacity == VECTOR_INITIAL_CAPACITY);
	assert(_msize(vectPtr->entities) == VECTOR_INITIAL_CAPACITY * sizeof(Element));

	vector_destroy(vectPtr);

	assert(vectPtr->size == 0);
	assert(vectPtr->capacity == 0);
	assert(_msize(vectPtr->entities) == -1);

	free(vectPtr);
	//assert(_msize(vectPtr) == -1);
}

void test_vectorGetersSeters()
{
	Vector vect;
	vector_init(&vect);

	assert(vector_getLen(&vect) == 0);
	assert(vector__getCapacity(&vect) == VECTOR_INITIAL_CAPACITY);

	vector__incLen(&vect);
	assert(vector_getLen(&vect) == 1);

	vector__setLen(&vect, 0);
	assert(vector_getLen(&vect) == 0);

	vector__setCapacity(&vect, 100);
	assert(vector__getCapacity(&vect) == 100);

	vector__setCapacity(&vect, VECTOR_INITIAL_CAPACITY);
	assert(vector__getCapacity(&vect) == VECTOR_INITIAL_CAPACITY);

	vector_destroy(&vect);

	assert(vect.size == 0);
	assert(vect.capacity == 0);
	assert(_msize(vect.entities) == -1);
}

void test_vectorPushBack()
{
	Vector vect;
	vector_init(&vect);

	vector_pushBack(&vect, (Element)10);
	assert(vector_getLen(&vect) == 1);
	assert((intptr_t)vect.entities[0] == 10);

	vector_pushBack(&vect, (Element)40);
	assert(vector_getLen(&vect) == 2);
	assert((intptr_t)vect.entities[1] == 40);

	vector_pushBack(&vect, (Element)30);
	assert(vector_getLen(&vect) == 3);
	assert((intptr_t)vect.entities[2] == 30);

	vector_pushBack(&vect, (Element)70);
	assert(vector_getLen(&vect) == 4);
	assert((intptr_t)vect.entities[3] == 70);

	// test 3000 random elements
	int i;
	int nr;
	srand (time(NULL));
	for(i = 4; i < 3000; ++i)
	{
		nr = rand();
		vector_pushBack(&vect, (Element)nr);
		assert(vector_getLen(&vect) == i + 1);
		assert((intptr_t)vect.entities[i] == nr);
	}

	// Capacity should be 512 * VECTOR_INITIAL_CAPACITY after 3000 iterations
	assert(vector__getCapacity(&vect) == 512 * VECTOR_INITIAL_CAPACITY);

	vector_destroy(&vect);

	assert(vect.size == 0);
	assert(vect.capacity == 0);
	assert(_msize(vect.entities) == -1);
}

void test_vectorGetAt()
{
	Vector vect;
	vector_init(&vect);

	vector_pushBack(&vect, (Element)10);
	assert(vector_getLen(&vect) == 1);
	assert((intptr_t)vector_getAt(&vect, 0) == 10);

	vector_pushBack(&vect, (Element)40);
	assert(vector_getLen(&vect) == 2);
	assert((intptr_t)vector_getAt(&vect, 1) == 40);

	vector_pushBack(&vect, (Element)30);
	assert(vector_getLen(&vect) == 3);
	assert((intptr_t)vector_getAt(&vect, 2) == 30);

	vector_pushBack(&vect, (Element)70);
	assert(vector_getLen(&vect) == 4);
	assert((intptr_t)vector_getAt(&vect, 3) == 70);

	// test 3000 random elements
	int i;
	int nr;
	srand (time(NULL));
	for(i = 4; i < 3000; ++i)
	{
		nr = rand();
		vector_pushBack(&vect, (Element)nr);
		assert(vector_getLen(&vect) == i + 1);
		assert((intptr_t)vector_getAt(&vect, i) == nr);
	}

	// Capacity should be 512 * VECTOR_INITIAL_CAPACITY after 3000 iterations
	assert(vector__getCapacity(&vect) == 512 * VECTOR_INITIAL_CAPACITY);

	vector_destroy(&vect);

	assert(vect.size == 0);
	assert(vect.capacity == 0);
	assert(_msize(vect.entities) == -1);
}

void test_vectorRemoveAt()
{
	Vector vect;
	vector_init(&vect);

	// test 3000 random elements
	int i;
	int nr;
	srand (time(NULL));
	for(i = 0; i < 3000; ++i)
	{
		nr = rand();
		vector_pushBack(&vect, (Element)nr);
		assert(vector_getLen(&vect) == i + 1);
		assert((intptr_t)vector_getAt(&vect, i) == nr);
	}

	// Capacity should be 512 * VECTOR_INITIAL_CAPACITY after 3000 iterations
	assert(vector__getCapacity(&vect) == 512 * VECTOR_INITIAL_CAPACITY);

	// Start removing elements
	int nrAtNextPos = (intptr_t)vector_getAt(&vect, 11);
	int oldLen = vector_getLen(&vect);

	vector_removeAt(&vect, 10);

	assert(nrAtNextPos == (intptr_t)vector_getAt(&vect, 10));
	assert(oldLen - 1 == vector_getLen(&vect));


	vector_destroy(&vect);

	assert(vect.size == 0);
	assert(vect.capacity == 0);
	assert(_msize(vect.entities) == -1);
}

void test_Vectors()
{
	test_vectorCreateDestroy();
	test_vectorPtrCreateDestroy();
	test_vectorGetersSeters();
	test_vectorPushBack();
	test_vectorGetAt();
	test_vectorRemoveAt();
}
