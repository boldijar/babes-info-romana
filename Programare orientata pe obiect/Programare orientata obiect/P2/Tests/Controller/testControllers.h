/*
 * testControllers.h
 *
 *  Created on: 20.04.2012
 *      Author: Florin Mihalache
 */

#ifndef TESTCONTROLLERS_H_
#define TESTCONTROLLERS_H_
#include "../../Src/Controller/HomeworkController.h"
#include "../../Src/Controller/StudentController.h"
#include <iostream>
#include <assert.h>

void testControllers() {

	// Homework controller
	HomeworkRepositoryInMemory* hwR = new HomeworkRepositoryInMemory();
	HomeworkValidator* hwV = new HomeworkValidator();
	HomeworkController hwC(hwR, hwV);
	hwC.addHomework("Lab1");
	hwC.addHomework("lab2");
	assert(hwC.size() == 2);
	Homework* hwX = hwR->getById(2);
	assert(hwX->description == "lab2");
	hwC.updateHomework(2, "Lab2-3");
	assert(hwX->description == "Lab2-3");
	hwC.removeHomework(1);
	assert(hwC.size() == 1);
	hwC.addHomework("Labb");
	hwX = hwR->getById(3);
	assert(hwX->description == "Labb");

	// Student controller
	StudentRepositoryInMemory* sR = new StudentRepositoryInMemory();
	StudentValidator* sV = new StudentValidator();
	AssignedHwValidator* ahV = new AssignedHwValidator();
	StudentController sC(sR, sV, hwR, ahV);
	sC.addStudent("Florin", "214");
	sC.addStudent("Andrei", "221");
	assert(sC.size() == 2);
	Student* studX = sR->getById(2);
	assert(studX->name == "Andrei");
	sC.updateStudent(1, "Mihai", "214");
	studX = sR->getById(1);
	assert(studX->name == "Mihai");
	sC.assignHomework(0, 2, 1, 6);
	sC.assignHomework(0, 2, 2, 9);
	sC.assignHomework(0, 3, 1, 5.5);
	assert(sR->getById(1)->hwList.size() == 2); // student with id = 2 has two assigned homeworks
	assert(sR->getById(2)->hwList.size() == 1); // student with id = 1 has one assigned homework
	sC.removeStudent(1);
	assert(sC.size() == 1);
}

#endif /* TESTCONTROLLERS_H_ */
