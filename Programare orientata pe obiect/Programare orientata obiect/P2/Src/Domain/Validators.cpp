/*
 * Validators.cpp
 *
 *  Created on: 19.04.2012
 *      Author: Florin Mihalache
 */

#include "Validators.h"

void StudentValidator::validate(Student student) throw (ValidationError) {
	if (student.getId() < 0) {
		throw ValidationError("Student id <= 0");
	}
	if (student.name.empty()) {
		throw ValidationError("Student name is empty");
	}
	if (student.group.empty()) {
		throw ValidationError("Student group is empty");
	}
}

void HomeworkValidator::validate(Homework homework) throw (ValidationError) {
	if (homework.getId() < 0) {
		throw ValidationError("Homework id <= 0");
	}
	if (homework.description.empty()) {
		throw ValidationError("Homework description is empty");
	}
}

void AssignedHwValidator::validate(AssignedHw homework) throw (ValidationError) {
	if (homework.getGrade() <= 0) {
		throw ValidationError("Homework grade <= 0");
	}
	if (homework.getGrade() > 10) {
		throw ValidationError("Homework grade > 10");
	}
}


