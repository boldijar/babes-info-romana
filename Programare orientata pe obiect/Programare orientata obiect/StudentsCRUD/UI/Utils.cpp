/*
 * Utils.cpp
 *
 *  Created on: 02.05.2012
 *      Author: Florin Mihalache
 */

#include "Utils.h"
#include <iostream>
using namespace std;

void printHomework(Homework* hw) {
	cout << "\tId \tDescription" << endl;
	cout << "\t" << hw->getId() << " \t" << hw->description << endl;
}

void printStudent(Student* stud) {
	cout << "\tId \tName \tGroup" << endl;
	cout << "\t" << stud->getId() << " \t" << stud->name << " \t" << stud->group << endl;
}

void printStudent(Student* stud, HomeworkController* hwCtrl) {
	cout << "\t" << stud->getId() << " \t" << stud->name << " \t" << stud->group << endl;

	vector<AssignedHw>* hwList = stud->getHwList();
	if (hwList->size() == 0) {
		return;
	}

	vector<AssignedHw>::iterator it = hwList->begin();
	vector<AssignedHw>::iterator end = hwList->end();
	AssignedHw* ahw;
	Homework* hw;

	while (it != end) {
		ahw = &(*it);
		hw = hwCtrl->getById(ahw->getHwId());
		cout << "\t\t<" << hw->description << " - " << ahw->grade << ">" << endl;
		++it;
	}
}



