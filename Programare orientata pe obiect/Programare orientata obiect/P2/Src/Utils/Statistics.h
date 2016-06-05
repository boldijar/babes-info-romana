/*
 * Statistics.h
 *
 *  Created on: 07.05.2012
 *      Author: Florin Mihalache
 */

#ifndef STATISTICS_H_
#define STATISTICS_H_
#include "../../Src/Domain/Homework.h"
#include "../../Src/Domain/Student.h"
#include "../../Src/Controller/HomeworkController.h"
#include "../../Src/Controller/StudentController.h"

#include "DynamicArray.h"

struct StudAndGrade {
	Student* student;
	float grade;
};

/**
 * Computes the average grade of a given student
 */
float averageGrade(Student* stud, HomeworkController* hwCtrl);

/**
 * Returns a pointer to a list of students with
 *  the average grade lower than 5
 */
DynamicArray<StudAndGrade>* averageGradeLowerThan(StudentController* studCtrl, HomeworkController* hwCtrl);

/**
 * Returns a pointer to a sorted list of students and grades at a single assignment
 * 		Pre: sortType: - 1 alphabetical
 * 					   - 2 by their grades
 */
DynamicArray<StudAndGrade>* listAtSingleAssignment(StudentController* studCtrl,
		int assignmentId, int sortType);

/**
 * Sorts a list of StudAndGrade
 * 		Pre: sortType: - 1 alphabetical
 * 					   - 2 by their grades
 */
void sortStudAndGrade(DynamicArray<StudAndGrade>* list, int sortType);

#endif /* STATISTICS_H_ */
