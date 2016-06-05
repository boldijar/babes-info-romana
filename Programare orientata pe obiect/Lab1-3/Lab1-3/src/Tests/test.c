/*
 * test.c
 *
 *  Created on: Mar 9, 2015
 *      Author: Nexflame
 */

#include "test.h"
#include "Product/test_product.h"
#include "Repository/test_Repository.h"
#include "Vector/test_vector.h"
#include "StoreObject/test_storeObject.h"

// Private
void test__addAll(Test* this)
{
	// All functions that should be tested should be added here
	test_Add(this, &test_Products);
	test_Add(this, &test_Vectors);
	test_Add(this, &test_SotreObjects);
	test_Add(this, &test_Repositories);
}


// Public
void test_init(Test* this)
{
	vector_init(&this->tests);
}

void test_destroy(Test* this)
{
	vector_destroy(&this->tests);
}

void test_Add(Test* this, Function fn)
{
	vector_pushBack(&this->tests, fn);
}

void test_Run(Test* this)
{
	// Add all tests
	test__addAll(this);

	int i;
	int len = vector_getLen(&this->tests);

	for (i = 0; i < len; ++i)
		((Function)vector_getAt(&this->tests, i))();
}
