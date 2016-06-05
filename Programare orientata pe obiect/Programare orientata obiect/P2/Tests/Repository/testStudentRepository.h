/*
 * testStudentRepository.h
 *
 *  Created on: 20.04.2012
 *      Author: Florin Mihalache
 */

#ifndef TESTSTUDENTREPOSITORY_H_
#define TESTSTUDENTREPOSITORY_H_
#include <assert.h>
#include "../../Src/Repository/StudentRepositoryInMemory.h"
#include <iostream>

void testStudentRepository() {
	StudentRepository* studR = new StudentRepositoryInMemory();
	Student stud1("Andrei", "214");
	stud1.setId(1);
	Student stud2("Mircea", "212");
	stud2.setId(2);
	Student stud3("Ionica", "214");
	stud3.setId(3);

	assert(studR->size() == 0);
	studR->store(stud1);
	studR->store(stud2);
	studR->store(stud3);
	assert(studR->size() == 3);

	Student* studX = studR->getById(2);
	assert(studX->name == stud2.name);
	studX = studR->getById(3);
	assert(studX->name == stud3.name);
	studR->remove(2);
	assert(studR->size() == 2);
	studX = studR->getById(1);
	assert(studX->name == stud1.name);
	studX = studR->getById(3);
	assert(studX->name == stud3.name);
}


#endif /* TESTSTUDENTREPOSITORY_H_ */
