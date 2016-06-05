/*
 * Statistics.cpp
 *
 *  Created on: 07.05.2012
 *      Author: Florin Mihalache
 */

#include "Statistics.h"

float averageGrade(Student* stud, HomeworkController* hwCtrl) {
	vector<AssignedHw>* hwList = stud->getHwList();
	if (hwList->size() == 0)
		return -1; // the list of homeworks is empty

	vector<AssignedHw>::iterator it = hwList->begin();
	vector<AssignedHw>::iterator end = hwList->end();
	AssignedHw* ahw;
	float sum, k;
	sum = 0;
	k = 0;

	while (it != end) {
		ahw = &(*it);
		sum += ahw->grade;
		k += 1;
		++it;
	}

	return sum/k;
}

DynamicArray<StudAndGrade>* averageGradeLowerThan(StudentController* studCtrl, HomeworkController* hwCtrl) {
	DynamicArray<StudAndGrade>* resultList = new DynamicArray<StudAndGrade>;
	DynamicArray<Student>* studList = studCtrl->getStudList();
	DynamicArrayIterator<Student> it = studList->begin();
	DynamicArrayIterator<Student> end = studList->end();
	Student* studX;
	float aGrade;
	StudAndGrade sad;

	while (it <= end) {
		studX = it.getElement();
		aGrade = averageGrade(studX, hwCtrl);
		if (aGrade < 5 && aGrade != -1) {
			sad.grade = aGrade;
			sad.student = studX;
			resultList->addElem(sad);
		}
		++it;
	}
	return resultList;
}

DynamicArray<StudAndGrade>* listAtSingleAssignment(StudentController* studCtrl,
		int assignmentId, int sortType) {
	DynamicArray<StudAndGrade>* resultList = new DynamicArray<StudAndGrade>;
	DynamicArray<Student>* studList = studCtrl->getStudList();
	DynamicArrayIterator<Student> it = studList->begin();
	DynamicArrayIterator<Student> end = studList->end();

	Student* studX;
	vector<AssignedHw>* hwList;
	StudAndGrade sad;
	AssignedHw* ahw;

	while (it <= end) {
		studX = it.getElement();
		hwList = studX->getHwList();
		vector<AssignedHw>::iterator itH = hwList->begin();
		vector<AssignedHw>::iterator endH = hwList->end();
		while (itH != endH) {
			ahw = &(*itH);
			if (ahw->getHwId() == assignmentId) { // if the student has given lab, add it to resultList
				sad.student = studX;
				sad.grade = ahw->getGrade();
				resultList->addElem(sad);
			}
			++itH;
		}
		++it;
	}

	sortStudAndGrade(resultList, sortType);
	return resultList;
}

void sortStudAndGrade(DynamicArray<StudAndGrade>* list, int sortType) {

	if (sortType == 1) { // alphabetical sorting by name
		if (list->getSize() > 1) {
			bool ok = false;
			StudAndGrade tmp;
			while (!ok) {
				ok = true;
				for (int i = 0; i < list->getSize() - 1; i++) {
					if (list->getElem(i)->student->name > list->getElem(i + 1)->student->name ) {
						ok = false;
						tmp = *list->getElem(i);
						*list->getElem(i) = *list->getElem(i+1);
						*list->getElem(i+1) = tmp;
					}
				}
			}
		}
	}
	if (sortType == 2) { // descending sorting by grades
		if (list->getSize() > 1) {
			bool ok = false;
			StudAndGrade tmp;
			while (!ok) {
				ok = true;
				for (int i = 0; i < list->getSize() - 1; i++) {
					if (list->getElem(i)->grade < list->getElem(i + 1)->grade ) {
						ok = false;
						tmp = *list->getElem(i);
						*list->getElem(i) = *list->getElem(i+1);
						*list->getElem(i+1) = tmp;
					}
				}
			}
		}
	}
}



