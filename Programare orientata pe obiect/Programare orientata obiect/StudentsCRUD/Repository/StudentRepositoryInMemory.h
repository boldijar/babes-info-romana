/*
 * StudentRepository.h
 *
 *  Created on: 20.04.2012
 *      Author: Florin Mihalache
 */

#ifndef STUDENTREPOSITORYINMEMORY_H_
#define STUDENTREPOSITORYINMEMORY_H_

#include "../Domain/Student.h"
#include "../Domain/Validators.h"
#include "../Utils/DynamicArray.h"
#include "StudentRepository.h"

class StudentRepositoryInMemory: public StudentRepository {
public:
	StudentRepositoryInMemory() :
		_lastId(0) {
	}

	/**
	 * Store a student
	 * Pre: stud - student to be stored
	 */
	void store(Student stud);

	/**
	 * Remove a student from repository, by id
	 */
	void remove(int id);

	/**
	 * Get a student by id
	 */
	Student* getById(int id);

	/**
	 * Count the number of students in repository
	 */
	int size();

	DynamicArray<Student>* getStudList() {
		return &_studList;
	}

private:
	DynamicArray<Student> _studList;
	int _lastId;
};


#endif /* STUDENTREPOSITORYINMEMORY_H_ */
