/*
 * vector.c
 *
 *  Created on: Mar 5, 2015
 *      Author: Nexflame
 */

#include <malloc.h>
#include "vector.h"

void vector_init(Vector* this)
{
	vector__setLen(this, 0);
	vector__setCapacity(this, VECTOR_INITIAL_CAPACITY);

	// Since we use only shallow copies of elements in our vector, it's enough to keep only the pointer size
	// (any pointer has the same sizeof()) -> use sizeof(void*)
	this->entities = malloc(this->capacity * sizeof(Element));
}

void vector_destroy(Vector* this)
{
	vector__setLen(this, 0);
	vector__setCapacity(this, 0);

	// Free vector
	free(this->entities);
	this->entities = NULL;
}

void vector_pushBack(Vector* this, Element entity)
{
	// If there is no more space available, reallocate
	if (vector__getCapacity(this) == vector_getLen(this))
	{
		// Double the amount of capacity
		vector__setCapacity(this, vector__getCapacity(this) * 2);
		this->entities = realloc(this->entities, this->capacity * sizeof(Element));
	}

	// Add new element - shallow copy
	this->entities[vector_getLen(this)] = entity;
	vector__incLen(this);
}

void vector_removeAt(Vector* this, int pos)
{
	int i;
	int len = vector_getLen(this);

	if (pos > len - 1)
	{
		printf("Error: Attempt to remove from invalid position! Vector (size: %d) at position: %d", len, pos);
		return;
	}

	// Not very stylish but it's ok for now. TO DO: refact with c libraries!
	for (i = pos; i < len - 1; ++i)
		this->entities[i] = this->entities[i + 1];

	this->entities[i] = NULL;
	vector__setLen(this, len - 1);
}

int vector_getLen(Vector* this)
{
	return this->size;
}

void vector__incLen(Vector* this)
{
	this->size++;
}

void vector__setLen(Vector* this, int newSize)
{
	this->size = newSize;
}

int vector__getCapacity(Vector* this)
{
	return this->capacity;
}

void vector__setCapacity(Vector* this, int newCapacity)
{
	this->capacity = newCapacity;
}

Element vector_getAt(Vector* this, int pos)
{
	int len = vector_getLen(this);

	if (pos > len - 1)
	{
		printf("Error: Attempt to access invalid position! Vector (size: %d) at position: %d", len, pos);
		return 0;
	}

	return this->entities[pos];
}
