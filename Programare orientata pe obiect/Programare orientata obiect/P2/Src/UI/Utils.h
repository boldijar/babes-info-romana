/*
 * Utils.h
 *
 *  Created on: 02.05.2012
 *      Author: Florin Mihalache
 */

#ifndef UTILS_H_
#define UTILS_H_
#include "../../Src/Domain/Homework.h"
#include "../../Src/Domain/Student.h"
#include "../../Src/Controller/HomeworkController.h"

void printHomework(Homework* hw);
void printStudent(Student* stud);
void printStudent(Student* stud, HomeworkController* hwCtrl);

#endif /* UTILS_H_ */
