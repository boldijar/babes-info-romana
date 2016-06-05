/*
 * DynamicArray.h
 *
 *  Created on: 16.04.2012
 *      Author: Florin Mihalache
 */

#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_
#define DEFAULT_MAX_SIZE 10
#include <iostream>

template<typename Element>
class DynamicArray;
template<typename Element>
class DynamicArrayIterator {
public:
	friend class DynamicArray<Element> ;
	/**
	 * Copy constructor
	 */
	DynamicArrayIterator(const DynamicArrayIterator &other) {
		_pointee = other._pointee;
	}

	/**
	 * Go to the next element
	 */
	DynamicArrayIterator& operator++() {
		_pointee++;
		return *this;
	}

	/**
	 * Get the value for the current element in iteration
	 */
	const Element operator *() {
		Element e  = *_dArray->getElem(_pointee);
		return e;
	}

	/**
	 * Get a pointer to the current element in iteration
	 */
	Element* getElement() {
		return _dArray->getElem(_pointee);
	}

	/**
	 * Check if two positions in iteration are not equal
	 */
	bool operator !=(DynamicArrayIterator& other) {
		return (_pointee != other._pointee);
	}

	/**
	 * Operator for less or equal
	 */
	bool operator <=(DynamicArrayIterator& other) {
		return (_pointee <= other._pointee);
	}


	int getPointee() {
		return _pointee;
	}

private:
	int _pointee;
	DynamicArray<Element> *_dArray;
	DynamicArrayIterator(int pointee) :
			_pointee(pointee) {
	}
};

template<typename Element>
class DynamicArray {
public:
	/**
	 * Default constructor
	 */
	DynamicArray();

	/**
	 * Copy constructor
	 */
	DynamicArray(const DynamicArray &other);

	/**
	 * Destructor
	 */
	~DynamicArray();

	/**
	 * Add an element to the dynamic array to the end of the array
	 * e - is a generic element
	 */
	void addElem(Element e);

	/**
	 * Delete the element from the given position
	 * pos - the position of the elem to be deleted, pos>=0; pos<size
	 * returns the deleted element
	 */
	Element deleteElem(int pos);

	/**
	 * Access the element from a given position
	 * pos - the position (pos>=0; pos<size)
	 */
	Element* getElem(int pos);

	/**
	 * Return the number of stored elements
	 */
	int getSize();

	/**
	 * Return the first position in the iteration
	 */
	DynamicArrayIterator<Element> begin() {
		DynamicArrayIterator<Element> it(0);
		it._dArray = this;
		return it;
	}

	/**
	 * Return the last position in the iteration
	 */
	DynamicArrayIterator<Element> end() {
		DynamicArrayIterator<Element> it(_size-1);
		it._dArray = this;
		return it;
	}

private:
	Element *_elements;
	int _capacity;
	int _size;
	/**
	 * Create enough space to hold nrElem elements
	 * nrElems - the number of _elements that we need to store
	 */
	void _ensureCapacity(int nrElems);
};

//////////////////////////////////////////////////
//////// Definition
//////////////////////////////////////////////////

template<typename Element>
DynamicArray<Element>::DynamicArray() {
	_capacity = DEFAULT_MAX_SIZE;
	_elements = new Element[_capacity];
	_size = 0;
}

template<typename Element>
DynamicArray<Element>::DynamicArray(const DynamicArray &other) {
	_capacity = other._capacity;
	_elements = new Element[_capacity];
	_size = other._size;
	for (int i = 0; i < _size; i++) {
		_elements[i] = other._elements[i];
	}
}

template<typename Element>
DynamicArray<Element>::~DynamicArray() {
	delete[] _elements;
}

template<typename Element>
void DynamicArray<Element>::_ensureCapacity(int nrElems) {
	if (_capacity >= nrElems) {
		return; //we have space to store the values
	}
//we need to allocate more space for the values
	Element *aux = _elements;
//create space to hold more numbers
	_capacity = _capacity * 2;
	_elements = new Element[_capacity];
//copy the values
	for (int i = 0; i < _size; i++) {
		_elements[i] = aux[i];
	}
//release the memory
	delete[] aux;
}

template<typename Element>
void DynamicArray<Element>::addElem(Element e) {
	_ensureCapacity(_size + 1);
	_elements[_size] = e;
	_size++;
}

template<typename Element>
Element DynamicArray<Element>::deleteElem(int pos) {
	Element rez = _elements[pos];
	for (int i = pos; i < _size - 1; i++) {
		_elements[i] = _elements[i + 1];
	}
	_size--;
	return rez;
}

template<typename Element>
int DynamicArray<Element>::getSize() {
	return _size;
}
template<typename Element>
Element* DynamicArray<Element>::getElem(int pos) {
	return &_elements[pos];
}

#endif /* DYNAMICARRAY_H_ */
