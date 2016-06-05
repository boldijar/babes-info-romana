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
#include "../Repository/HomeworkRepository.h"
#include <string>

class StudentController {
public:
	/**
	 * Constructor
	 * Needs: StudentRepository, StudentValidator, HomeworkRepository, AssignedHwValidator
	 */
	StudentController(StudentRepository* repository, StudentValidator* validator,
			HomeworkRepository* hwRepository, AssignedHwValidator* ahwValidator) :
			_repository(repository), _validator(validator), _hwRepository(hwRepository),
			_ahwValidator(ahwValidator), _lastAhwId(0) {
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
	 * Assign a homework to a student
	 * 		ahwId - assigned homework id
	 * 		hwId - homework id
	 * 		studId - student id
	 * 		grade - student's grade on this homework
	 * 	Throws ValidationError if given id's are incorrect
	 */
	void assignHomework(int ahwId, int hwId, int studId, float grade) throw (ValidationError);

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

	vector<AssignedHw>* getHwList(int studId);

private:
	StudentRepository* _repository;
	StudentValidator* _validator;
	HomeworkRepository* _hwRepository;
	AssignedHwValidator* _ahwValidator;
	int _lastAhwId;
};




#endif /* STUDENTCONTROLLER_H_ */
