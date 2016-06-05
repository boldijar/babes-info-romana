/*
 * test_Repository.h
 *
 *  Created on: Mar 9, 2015
 *      Author: Nexflame
 */

#ifndef TESTS_REPOSITORY_TEST_REPOSITORY_H_
#define TESTS_REPOSITORY_TEST_REPOSITORY_H_

#include "../../Repository/repository.h"

// Tests
void test_repositoryCreateDestroy();
void test_repositoryAddObject();
void test_repositoryFindByID();
void test_repositoryDeleteByID();
void test_repositorySave();

// Main FN - Calls all other test for repositories
void test_Repositories();

#endif /* TESTS_REPOSITORY_TEST_REPOSITORY_H_ */
