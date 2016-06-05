/*
 * testDynamicArray.h
 *
 *  Created on: 16.04.2012
 *      Author: Florin Mihalache
 */

#ifndef TESTDYNAMICARRAY_H_
#define TESTDYNAMICARRAY_H_

#include "../../Src/Utils/DynamicArray.h"
#include <assert.h>
#include <iostream>
#include <vector>

void testDynamicArray() {
	DynamicArray<int> test;
	test.addElem(2);
	test.addElem(1);
	test.addElem(3);
	assert(test.getSize() == 3);
	test.deleteElem(1);
	assert(test.getSize() == 2);

	// testing copy constructor
	DynamicArray<int> copy = test;
	assert(copy.getSize() == test.getSize());

	// testing iterator
	DynamicArrayIterator<int> it = test.begin();
	DynamicArrayIterator<int> end = test.end();

	test.addElem(4);
	test.addElem(5);
	test.addElem(6);
	int k = 2;
	while (it != end) {
		assert (*it == k);
		++it;
		k++;
	}
}

#endif /* TESTDYNAMICARRAY_H_ */
