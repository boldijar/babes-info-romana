/*
 * StudentAndHomework.h
 *
 *  Created on: 19.04.2012
 *      Author: Florin Mihalache
 */

#ifndef STUDENTANDHOMEWORK_H_
#define STUDENTANDHOMEWORK_H_
#include "../../Src/Domain/Homework.h"
#include "../../Src/Domain/Student.h"
#include <assert.h>
#include <iostream>

void testStudentAndHomework() {
	//testing Homework
	Homework hw1("lab1");
	assert(hw1.getId() == 0);
	assert(hw1.description == "lab1");
	hw1.setId(2);
	assert(hw1.getId() == 2);

	//tesing Student
	Student stud("Andrei", "214");
	assert(stud.getId() == 0);
	assert(stud.name == "Andrei");
	assert(stud.group == "214");

	//testing AssignedHw and hwList from Student class
	Homework hw2("lab2");
	AssignedHw ahw1;
	AssignedHw ahw2;
	ahw1.setHwId(2);
	ahw1.setGrade(8.6);
	ahw1.setHwId(0);
	ahw2.setGrade(7);
	stud.addHwToList(ahw1);
	stud.addHwToList(ahw2);
	assert(stud.hwList.size() == 2);
}

#endif /* STUDENTANDHOMEWORK_H_ */
