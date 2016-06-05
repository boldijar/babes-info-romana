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
#endif /* VALIDATORS_H_ */
