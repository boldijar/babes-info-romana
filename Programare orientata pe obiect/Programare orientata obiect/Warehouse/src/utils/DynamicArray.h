/*
 * DynamicArray.h
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

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
	DynamicArray(DynamicArray &ot);

	/**
	 * destructor
	 */
	~DynamicArray();
	/**
	 * Add an element to the dynamic array to the end of the array
	 * e - is a generic element
	 */
	void addE(Element r);
	/**
	 * Delete the element from the given position
	 * poz - the position of the elem to be deleted, poz>=0;poz<size
	 * returns the deleted element
	 */
	Element deleteElem(int poz);

	/**
	 * Access the element from a given position
	 * poz - the position (poz>=0;poz<size)
	 */
	Element get(int poz);
	/**
	 * Give the size of the array
	 * return the number of elements in the array
	 */
	int getSize();
	/**
	 * Clear the array
	 * Post: the array will contain 0 elements
	 */
	void clear();
private:
	Element *elems;
	int capacity;
	int size;
	/**
	 * Create enough space to hold nrElem elements
	 * nrElems - the number of elements that we need to store
	 */
	void ensureCapacity(int nrElems);
};

template<typename Element>
DynamicArray<Element>::DynamicArray() {
	capacity = 10;
	elems = new Element[capacity];
	size = 0;
}

template<typename Element>
DynamicArray<Element>::~DynamicArray() {
	delete[] elems;
}
/**
 * Create enough space to hold nrElem elements
 * nrElems - the number of elements that we need to store
 */
template<typename Element>
void DynamicArray<Element>::ensureCapacity(int nrElems) {
	if (capacity >= nrElems) {
		return; //we have space to store the values
	}
	//we need to allocate more space for the values
	Element *aux = elems;
	//create space to hold more numbers
	capacity = capacity * 2;
	elems = new Element[capacity];
	//copy the values
	for (int i = 0; i < size; i++) {
		elems[i] = aux[i];
	}
	//release the memory
	delete[] aux;
}
/**
 * Add an element to the dynamic array
 * r - is a rational number
 */
template<typename Element>
void DynamicArray<Element>::addE(Element r) {
	ensureCapacity(size + 1);
	elems[size] = r;
	size++;
}

/**
 * Access the element from a given position
 * poz - the position (poz>=0;poz<size)
 */
template<typename Element>
Element DynamicArray<Element>::get(int poz) {
	return elems[poz];
}
/**
 * Give the size of the array
 * return the number of elements in the array
 */
template<typename Element>
int DynamicArray<Element>::getSize() {
	return size;
}

/**
 * Clear the element of the arrays
 * Post: the array will contain 0 elements
 */
template<typename Element>
void DynamicArray<Element>::clear() {
	size = 0;
}

/**
 * Delete the element from the given position
 * poz - the position of the elem to be deleted, poz>=0;poz<size
 * return the deleted element
 */
template<typename Element>
Element DynamicArray<Element>::deleteElem(int poz) {
	Element rez = elems[poz];
	for (int i = poz; i < size - 1; i++) {
		elems[i] = elems[i + 1];
	}
	size--;
	return rez;
}

#endif /* DYNAMICARRAY_H_ */
