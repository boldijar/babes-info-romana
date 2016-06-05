/*
 * vector.h
 *
 *  Created on: 6 Mar 2012
 *      Author: ilazar
 */

#ifndef VECTOR_H_
#define VECTOR_H_

typedef void* Element;

typedef struct {
	int size;
	Element* elements;
	int capacity;
} Vector;

/* Initializes the vector.
 * Post: size == 0
 */
void init(Vector* vector);

/* Destroys the vector. */
void destroy(Vector* vector);

/*
 * Returns the size of a vector.
 */
int size(Vector* vector);

/*
 * Inserts a new element at the end.
 */
void push_back(Vector* vector, Element element);

/*
 * Returns the element at a given index.
 * Pre: 0 <= index < size
 */
Element get_elem(Vector* vector, int index);

#endif /* VECTOR_H_ */
