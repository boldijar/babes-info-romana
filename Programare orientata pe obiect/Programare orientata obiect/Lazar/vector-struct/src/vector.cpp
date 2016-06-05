#include "vector.h"
#include <assert.h>

#define DEFAULT_MAX_SIZE 3

/* Initializes the vector.
 * Post: size == 0
 */
Vector::Vector() {
	this->_size = 0;
	this->_elements = new Element[DEFAULT_MAX_SIZE];
	this->_capacity = DEFAULT_MAX_SIZE;
}

/* Destroys the vector. */
Vector::~Vector() {
	delete this->_elements;
}

/*
 * Returns the size of a vector.
 */
int Vector::size() {
	return this->_size;
}

/*
 * Inserts a new element at the end.
 */
void Vector::push_back(Element element) {
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
Element Vector::get_elem(int index) {
	assert(0 <= index && index < _capacity);
	return this->_elements[index];
}

