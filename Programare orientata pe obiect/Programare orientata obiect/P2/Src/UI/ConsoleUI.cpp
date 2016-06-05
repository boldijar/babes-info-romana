/*
 * ConsoleUI.cpp
 *
 *  Created on: 26.04.2012
 *      Author: Florin Mihalache
 */

#include "ConsoleUI.h"
#include <iostream>
#include "../Domain/Errors.h"
#include "../Utils/Statistics.h"
using namespace std;

void ConsoleUI::showMenu() {
	cout << endl;
	cout << "*** Main menu" << endl;
	cout << "  1. Show this menu" << endl;
	cout << "  2. Manage students and homeworks lists" << endl;
	cout << "  3. Assign homework" << endl;
	cout << "  4. Show students and assigned homeworks" << endl;
	cout << "  5. Find student by id" << endl;
	cout << "  6. Statistics" << endl;
	cout << "  0. Exit" << endl;
}

void ConsoleUI::showManageListsMenu() {
	cout << endl;
	cout << "***** Manage Lists" << endl;
	cout << "    1. Show this menu" << endl;
	cout << "    2. Show homeworks" << endl;
	cout << "    3. Show students" << endl;
	cout << "    4. Add homework" << endl;
	cout << "    5. Add student" << endl;
	cout << "    6. Remove homework" << endl;
	cout << "    7. Remove student" << endl;
	cout << "    8. Update homework" << endl;
	cout << "    9. Update student" << endl;
	cout << "    0. Go back " << endl;
}

void ConsoleUI::showStatisticsMenu() {
	cout << endl;
	cout << "***** Statistics" << endl;
	cout << "    1. Show this menu" << endl;
	cout << "    2. Show all students with the average grade lower than 5" << endl;
	cout << "    3. Show students and grades at a single assignment" << endl;
}

void ConsoleUI::manageLists() {
	int cmd = 1;
	while (cmd != 0) {
		if (cmd == 1) {
			showManageListsMenu();
		}

		if (cmd == 2) {
			showHomeworks();
		}
		if (cmd == 3) {
			showStudents();
		}
		if (cmd == 4) {
			addHomework();
		}
		if (cmd == 5) {
			addStudent();
		}
		if (cmd == 6) {
			removeHomework();
		}
		if (cmd == 7) {
			removeStudent();
		}
		if (cmd == 8) {
			updateHomework();
		}
		if (cmd == 9) {
			updateStudent();
		}
		cout << ">>>> ";
		cin >> cmd;
	}
}

void ConsoleUI::statistics() {
	int cmd = 1;
	while (cmd != 0) {
		if (cmd == 1) {
			showStatisticsMenu();
		}
		if (cmd == 2) {
			studentsWithAverageGradeLowerThan();
		}
		if (cmd == 3) {
			studentsAtGivenAssignmentSorted();
		}

		cout << ">>>> ";
		cin >> cmd;
	}
}

void ConsoleUI::showUI() {
	int cmd = 1;
	while (cmd != 0) {
		if (cmd == 1) {
			showMenu();
		}
		if (cmd == 2) {
			manageLists();
		}
		if (cmd == 3) {
			assignHomework();
		}
		if (cmd == 4) {
			showStudentsAndHomeworks();
		}
		if (cmd == 5) {
			findStudentById();
		}
		if (cmd == 6) {
			statistics();
		}

		cout << ">> ";
		cin >> cmd;
	}
}

void ConsoleUI::showHomeworks() {
	if (hwCtrl->size() == 0) {
		cout << "The list is empty." << endl;
		return;
	}

	DynamicArray<Homework>* hwList = hwCtrl->getHwList();
	DynamicArrayIterator<Homework> it = hwList->begin();
	DynamicArrayIterator<Homework> end = hwList->end();
	Homework* hwX;

	cout << "\tId \tDescription" << endl;
	while (it <= end) {
		hwX = it.getElement();
		cout << "\t" << hwX->getId() << " \t" << hwX->description << endl;
		++it;
	}
}

void ConsoleUI::showStudents() {
	if (studCtrl->size() == 0) {
		cout << "The list is empty." << endl;
		return;
	}

	DynamicArray<Student>* studList = studCtrl->getStudList();
	DynamicArrayIterator<Student> it = studList->begin();
	DynamicArrayIterator<Student> end = studList->end();
	Student* studX;

	cout << "\tId \tName \tGroup" << endl;
	while (it <= end) {
		studX = it.getElement();
		cout << "\t" << studX->getId() << " \t" << studX->name << " \t"
				<< studX->group << endl;
		++it;
	}
}

void ConsoleUI::addHomework() {
	string desc;
	cout << "Description: ";
	cin >> desc;
	try {
		hwCtrl->addHomework(desc);
		cout << "Homework added." << endl;
	} catch (ValidationError& e) {
		cout << "Error: " << e.getMessage() << endl;
	}
}

void ConsoleUI::addStudent() {
	string name, group;
	cout << "Name: ";
	cin >> name;
	cout << "Group: ";
	cin >> group;
	try {
		studCtrl->addStudent(name, group);
		cout << "Student added." << endl;
	} catch (ValidationError& e) {
		cout << "Error: " << e.getMessage() << endl;
	}
}

void ConsoleUI::removeHomework() {
	int id;
	cout << "Homework id: ";
	cin >> id;
	Homework* hw;
	hw = hwCtrl->getById(id);
	if (hw == NULL) {
		cout << "Homework with given id (" << id << ") not found!" << endl;
	} else {
		hwCtrl->removeHomework(id);
		cout << "Homework removed." << endl;
	}
}

void ConsoleUI::removeStudent() {
	int id;
	cout << "Student id: ";
	cin >> id;
	Student* stud;
	stud = studCtrl->getById(id);
	if (stud == NULL) {
		cout << "Student with given id (" << id << ") not found!" << endl;
	} else {
		studCtrl->removeStudent(id);
		cout << "Student removed." << endl;
	}
}

void ConsoleUI::updateHomework() {
	int id;
	cout << "Homework id: ";
	cin >> id;
	Homework* hw;
	hw = hwCtrl->getById(id);

	if (hw == NULL) {
		cout << "Homework with given id (" << id << ") not found!" << endl;
		return;
	}

	cout << "Homework found: " << endl;
	printHomework(hw);

	string desc;
	cout << "New description: ";
	cin >> desc;
	try {
		hwCtrl->updateHomework(id, desc);
		cout << "Homework updated." << endl;
	} catch (ValidationError& e) {
		cout << "Error: " << e.getMessage() << endl;
	}

}

void ConsoleUI::updateStudent() {
	int id;
	cout << "Student id: ";
	cin >> id;
	Student* stud;
	stud = studCtrl->getById(id);

	if (stud == NULL) {
		cout << "Student with given id (" << id << ") not found!" << endl;
		return;
	}

	cout << "Student found: " << endl;
	printStudent(stud);

	string name, group;
	cout << "New name: ";
	cin >> name;
	cout << "New group: ";
	cin >> group;
	try {
		studCtrl->updateStudent(id, name, group);
		cout << "Student updated." << endl;
	} catch (ValidationError& e) {
		cout << "Error: " << e.getMessage() << endl;
	}
}

void ConsoleUI::assignHomework() {
	int studId, hwId;
	float grade;
	cout << "Homework id: ";
	cin >> hwId;
	cout << "Student id: ";
	cin >> studId;
	cout << "Grade: ";
	cin >> grade;
	try {
		studCtrl->assignHomework(0, hwId, studId, grade);
		cout << "Homework assigned." << endl;
	} catch (ValidationError& e) {
		cout << "Error: " << e.getMessage() << endl;
	}
}

void ConsoleUI::showStudentsAndHomeworks() {
	if (studCtrl->size() == 0) {
		cout << "The list is empty." << endl;
		return;
	}

	DynamicArray<Student>* studList = studCtrl->getStudList();
	DynamicArrayIterator<Student> it = studList->begin();
	DynamicArrayIterator<Student> end = studList->end();

	Student* studX;

	cout << "\tId \tName \tGroup" << endl;
	while (it <= end) {
		studX = it.getElement();
		printStudent(studX, hwCtrl);
		++it;
	}
}

void ConsoleUI::findStudentById() {
	int id;
	cout << "Student id: ";
	cin >> id;
	Student* stud;
	stud = studCtrl->getById(id);

	if (stud == NULL) {
		cout << "Student with given id (" << id << ") not found!" << endl;
		return;
	}

	cout << "Student found: " << endl;
	cout << "\tId \tName \tGroup" << endl;
	printStudent(stud, hwCtrl);
}

void ConsoleUI::studentsWithAverageGradeLowerThan() {
	DynamicArray<StudAndGrade>* sadList = averageGradeLowerThan(studCtrl, hwCtrl);

	if (sadList->getSize() == 0) {
		cout << "There are no students with the average grade lower than 5." << endl;
		return;
	}

	DynamicArrayIterator<StudAndGrade> it = sadList->begin();
	DynamicArrayIterator<StudAndGrade> end = sadList->end();
	StudAndGrade* sadX;

	cout << "\tstudId \tName \tGroup \tAverage Grade" << endl;
	while (it <= end) {
		sadX = it.getElement();
		cout << "\t" << sadX->student->getId() << " \t" << sadX->student->name << " \t"
				<< sadX->student->group << " \t" << sadX->grade << endl;
		++it;
	}
}

void ConsoleUI::studentsAtGivenAssignmentSorted() {
	int hwId, sortType;
	cout << "Homework id: " ;
	cin >> hwId;
	if (hwCtrl->getById(hwId) == NULL) {
		cout << "Homework with given id not found." << endl;
		return;
	}

	cout << "Sorting type (1 - by name, 2 - by grades): ";
	cin >> sortType;

	DynamicArray<StudAndGrade>* sadList = listAtSingleAssignment(studCtrl, hwId, sortType);

	if (sadList->getSize() == 0) {
		cout << "There are no students with that homework." << endl;
		return;
	}

	DynamicArrayIterator<StudAndGrade> it = sadList->begin();
	DynamicArrayIterator<StudAndGrade> end = sadList->end();
	StudAndGrade* sadX;

	cout << "\tstudId \tName \tGroup \tGrade" << endl;
	while (it <= end) {
		sadX = it.getElement();
		cout << "\t" << sadX->student->getId() << " \t" << sadX->student->name << " \t"
				<< sadX->student->group << " \t" << sadX->grade << endl;
		++it;
	}

}




