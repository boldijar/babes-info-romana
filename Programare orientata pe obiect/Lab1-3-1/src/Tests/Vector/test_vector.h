/*
 * test_vector.h
 *
 *  Created on: Mar 9, 2015
 *      Author: Nexflame
 */

#ifndef TESTS_VECTOR_TEST_VECTOR_H_
#define TESTS_VECTOR_TEST_VECTOR_H_

#include "../../Utils/vector/vector.h"

// Tests
void test_vectorCreateDestroy();
void test_vectorPtrCreateDestroy();
void test_vectorGetersSeters();
void test_vectorPushBack();
void test_vectorGetAt();
void test_vectorRemoveAt();

// Main function - Calls other functions to be executed
void test_Vectors();

#endif /* TESTS_VECTOR_TEST_VECTOR_H_ */
