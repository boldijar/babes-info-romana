/*
 * Validators.h
 *
 *  Created on: 19.04.2012
 *      Author: Florin Mihalache
 */

#ifndef VALIDATORS_H_
#define VALIDATORS_H_

#include "Errors.h"
#include "Student.h"
#include "Homework.h"

class StudentValidator {
public:
	/**
	 * Validate a student
	 * A student is valid if:
	 * 		name and group are not empty
	 * 		id > 0
	 * Throws ValidationError otherwise
	 */
	void validate(Student student) throw (ValidationError);
};

class HomeworkValidator {
public:
	/**
	 * Validate a homework
	 * A homework is valid if:
	 * 		description is not empty
	 * 		id > 0
	 * Throws ValidationError otherwise
	 */
	void validate(Homework homework) throw (ValidationError);;
};

class AssignedHwValidator {
public:
	/**
	 * Validate an assigned homework
	 * An assigned homework is valid if:
	 * 		grade > 0
	 * Throws ValidationError otherwise
	 */
	void validate(AssignedHw homework) throw (ValidationError);;
};

#endif /* VALIDATORS_H_ */
