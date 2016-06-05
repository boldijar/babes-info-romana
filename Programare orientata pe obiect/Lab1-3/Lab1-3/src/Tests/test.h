/*
 * test.h
 *
 *  Created on: Mar 9, 2015
 *      Author: Nexflame
 */

#ifndef TESTS_TEST_H_
#define TESTS_TEST_H_

#include "../Utils/vector/vector.h"

typedef struct struct_Test
{
	Vector tests;
}Test;

// Privat
void test__addAll(Test* test);

// init vector
void test_init(Test* this);
// destroy vector
void test_destroy(Test* this);
// Add a new function to verify
void test_Add(Test* this, Function fn);
// Add all tests to verify and verify them
void test_Run(Test* this);

#endif /* TESTS_TEST_H_ */
