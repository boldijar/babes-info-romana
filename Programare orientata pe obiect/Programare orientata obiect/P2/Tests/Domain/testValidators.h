/*
 * testValidators.h
 *
 *  Created on: 19.04.2012
 *      Author: Florin Mihalache
 */

#ifndef TESTVALIDATORS_H_
#define TESTVALIDATORS_H_
#include "../../Src/Domain/Validators.h"
#include <iostream>

void testValidators() {
	// Homework validator
	Homework hw("Lab1");
	HomeworkValidator hwVal;
	hw.setId(1);
	hwVal.validate(hw);

	hw.setId(-1);
	try {
		hwVal.validate(hw);
		assert(false);
	} catch (ValidationError& e) {
		assert(true);
	}

	hw.description = "";
	hw.setId(1);
	try {
		hwVal.validate(hw);
		assert(false);
	} catch (ValidationError& e) {
		assert(true);
	}

	// Assigned homework validator
	AssignedHw ahw;
	AssignedHwValidator ahwVal;
	ahw.setHwId(hw.getId());
	ahw.setGrade(5.5);

	ahwVal.validate(ahw);
	ahw.setGrade(0);
	try {
		ahwVal.validate(ahw);
		assert(false);
	} catch (ValidationError& e) {
		assert(true);
	}

	// Student validator
	Student stud("Andrei", "214");
	StudentValidator studVal;
	stud.setId(1);
	studVal.validate(stud);

	stud.setId(-1);
	try {
		studVal.validate(stud);
		assert(false);
	} catch (ValidationError& e) {
		assert(true);
	}

	stud.setId(1);
	stud.name = "";
	try {
		studVal.validate(stud);
		assert(false);
	} catch (ValidationError& e) {
		assert(true);
	}

	stud.name = "Mihai";
	stud.group = "";
	try {
		studVal.validate(stud);
		assert(false);
	} catch (ValidationError& e) {
		assert(true);
	}
}

#endif /* TESTVALIDATORS_H_ */
