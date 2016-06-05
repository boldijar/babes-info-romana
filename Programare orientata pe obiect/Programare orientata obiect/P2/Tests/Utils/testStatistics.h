/*
 * testStatistics.h
 *
 *  Created on: 09.05.2012
 *      Author: Florin Mihalache
 */

#ifndef TESTSTATISTICS_H_
#define TESTSTATISTICS_H_
#include "../../Src/Controller/HomeworkController.h"
#include "../../Src/Controller/StudentController.h"
#include "../../Src/Utils/Statistics.h"
#include <iostream>
#include <assert.h>

void testStatistics() {
	DynamicArray<StudAndGrade>* list = new DynamicArray<StudAndGrade>;
	StudAndGrade sgX;
	// create some students
	Student* s1 = new Student("Mircea", "221");
	Student* s2 = new Student("Mihai", "223");
	Student* s3 = new Student("Andrei", "22");

	// add them to the list
	sgX.student = s1;
	sgX.grade = 7;
	list->addElem(sgX);
	sgX.student = s2;
	sgX.grade = 5;
	list->addElem(sgX);
	sgX.student = s3;
	sgX.grade = 9.4;
	list->addElem(sgX);

	// check the list of StudAndGrade
	assert(list->getElem(0)->student->name == "Mircea");
	assert(list->getElem(0)->grade == 7);
	assert(list->getElem(1)->student->name == "Mihai");
	assert(list->getElem(1)->grade == 5);
	assert(list->getElem(2)->student->name == "Andrei");
	assert(list->getElem(2)->grade == (float)9.4);

	// sorting by name, alphabetical
	sortStudAndGrade(list, 1);
	assert(list->getElem(0)->student->name == "Andrei");
	assert(list->getElem(0)->grade == (float)9.4);
	assert(list->getElem(1)->student->name == "Mihai");
	assert(list->getElem(1)->grade == 5);
	assert(list->getElem(2)->student->name == "Mircea");
	assert(list->getElem(2)->grade == 7);

	// sorting by grades, descending order
	sortStudAndGrade(list, 2);
	assert(list->getElem(0)->student->name == "Andrei");
	assert(list->getElem(0)->grade == (float)9.4);
	assert(list->getElem(1)->student->name == "Mircea");
	assert(list->getElem(1)->grade == 7);
	assert(list->getElem(2)->student->name == "Mihai");
	assert(list->getElem(2)->grade == 5);
}


#endif /* TESTSTATISTICS_H_ */
