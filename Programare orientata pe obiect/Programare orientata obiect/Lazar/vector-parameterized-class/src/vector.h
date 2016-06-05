/*
 * vector.h
 *
 *  Created on: 11 Mar 2012
 *      Author: ilazar
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include <assert.h>

template <typename Element>
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

#define DEFAULT_MAX_SIZE 3

/* Initializes the vector.
 * Post: size == 0
 */
template <typename Element>
Vector<Element>::Vector() {
	this->_size = 0;
	this->_elements = new Element[DEFAULT_MAX_SIZE];
	this->_capacity = DEFAULT_MAX_SIZE;
}

/* Destroys the vector. */
template <typename Element>
Vector<Element>::~Vector() {
	delete this->_elements;
}

/*
 * Returns the size of a vector.
 */
template <typename Element>
int Vector<Element>::size() {
	return this->_size;
}

/*
 * Inserts a new element at the end.
 */
template <typename Element>
void Vector<Element>::push_back(Element element) {
	if (this->_size == this->_capacity) {
		int new_capacity = this->_capacity + this->_capacity / 2;
		Element* new_elements = new Element[new_capacity];
		for (int i = 0; i < this->_capacity; i++) {
			new_elements[i] = this->_elements[i];
		}
		delete this->_elements;
		this->_elements = new_elements;
		this->_capacity = new_capacity;
	}
	this->_elements[this->_size] = element;
	this->_size++;
}

/*
 * Returns the element at a given index.
 * Pre: 0 <= index < size
 */
template <typename Element>
Element Vector<Element>::get_elem(int index) {
	assert(0 <= index && index < _capacity);
	return this->_elements[index];
}

#endif /* VECTOR_H_ */
