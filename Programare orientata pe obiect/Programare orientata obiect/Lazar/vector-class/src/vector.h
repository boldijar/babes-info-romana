/*
 * vector.h
 *
 *  Created on: 11 Mar 2012
 *      Author: ilazar
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include <assert.h>

typedef void* Element;

class Vector {
private:
	int _size;
	Element* _elements;
	int _capacity;
public:
	/* Initializes the vector.
	 * Post: size == 0
	 */
	Vector();

	/* Destroys the vector. */
	~Vector();

	/*
	 * Returns the size of a vector.
	 */
	int size();

	/*
	 * Inserts a new element at the end.
	 */
	void push_back(Element element);

	/*
	 * Returns the element at a given index.
	 * Pre: 0 <= index < size
	 */
	Element get_elem(int index);
};

#endif /* VECTOR_H_ */
