/*
 * StudentController.h
 *
 *  Created on: 21.04.2012
 *      Author: Florin Mihalache
 */

#ifndef STUDENTCONTROLLER_H_
#define STUDENTCONTROLLER_H_
#include "../Domain/Validators.h"
#include "../Repository/StudentRepository.h"
#include <string>

class StudentController {
public:
	/**
	 * Constructor
     * Needs: StudentRepository, StudentValidator
	 */
    StudentController(StudentRepository* repository, StudentValidator* validator) :
            _repository(repository), _validator(validator) {
	}

	/**
	 * Add a student
	 * The id is generated automatically
	 * Throws ValidationError if name or group is empty
	 */
	void addStudent(string name, string group) throw (ValidationError);

	/**
	 * Update a student
	 * 		id - student id
	 * 		newName - new name for the student
	 * 		newGroup - new group for the student
	 * The id cannot be changed
	 */
	void updateStudent(int id, string newName, string newGroup) throw (ValidationError);

	/**
	 * Remove a student by id
	 */
	void removeStudent(int id);

	/**
	 * Number of students stored
	 */
	int size();

	/**
	 * Get a student by id
	 */
	Student* getById(int id);

	/**
	 * Destructor
	 */
	~StudentController();

	DynamicArray<Student>* getStudList() {
		return _repository->getStudList();
	}

private:
	StudentRepository* _repository;
	StudentValidator* _validator;
};




#endif /* STUDENTCONTROLLER_H_ */
