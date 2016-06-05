/*
 * ConsoleUI.h
 *
 *  Created on: 26.04.2012
 *      Author: Florin Mihalache
 */

#ifndef CONSOLEUI_H_
#define CONSOLEUI_H_
#include "../../Src/Controller/HomeworkController.h"
#include "../../Src/Controller/StudentController.h"
#include "Utils.h"


class ConsoleUI {
public:
	ConsoleUI(HomeworkController *hwCtrl, StudentController *studCtrl) :
			hwCtrl(hwCtrl), studCtrl(studCtrl) {
	}
	void showUI();

private:
	HomeworkController *hwCtrl;
	StudentController *studCtrl;
	void showMenu();
	void showManageListsMenu();
	void showStatisticsMenu();
	void manageLists();
	void showHomeworks();
	void showStudents();
	void addHomework();
	void addStudent();
	void removeHomework();
	void removeStudent();
	void updateHomework();
	void updateStudent();
	void assignHomework();
	void showStudentsAndHomeworks();
	void findStudentById();
	void statistics();
	void studentsWithAverageGradeLowerThan();
	void studentsAtGivenAssignmentSorted();
};

#endif /* CONSOLEUI_H_ */
