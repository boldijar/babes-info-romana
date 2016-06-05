/*
 * testHomeworkRepository.h
 *
 *  Created on: 19.04.2012
 *      Author: Florin Mihalache
 */

#ifndef TESTHOMEWORKREPOSITORY_H_
#define TESTHOMEWORKREPOSITORY_H_
#include "../../Src/Repository/HomeworkRepositoryInMemory.h"
#include "../../Src/Domain/Homework.h"
#include <assert.h>
#include <iostream>

void testHomeworkRepository() {
	HomeworkRepository* hwR = new HomeworkRepositoryInMemory();
	Homework hw1("lab1");
	hw1.setId(1);
	Homework hw2("lab2");
	hw2.setId(2);
	Homework hw3("lab3");
	hw3.setId(3);

	assert(hwR->size() == 0);
	hwR->store(hw1);
	hwR->store(hw2);
	hwR->store(hw3);
	assert(hwR->size() == 3);
	Homework* hwX = hwR->getById(2);
	assert(hwX->description == hw2.description);
	hwX = hwR->getById(3);
	assert(hwX->description == hw3.description);
	hwR->remove(2);
	assert(hwR->size() == 2);
	hwX = hwR->getById(1);
	assert(hwX->description == hw1.description);
	hwX = hwR->getById(3);
	assert(hwX->description == hw3.description);
}


#endif /* TESTHOMEWORKREPOSITORY_H_ */
