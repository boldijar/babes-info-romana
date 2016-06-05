/*
 * StudentRepository.h
 *
 *  Created on: 20.04.2012
 *      Author: Florin Mihalache
 */

#ifndef STUDENTREPOSITORY_H_
#define STUDENTREPOSITORY_H_

#include "../Domain/Student.h"
#include "../Utils/DynamicArray.h"

class StudentRepository {
public:
	/**
	 * Store a student
	 * Pre: stud - student to be stored
	 */
	virtual void store(Student stud) = 0;

	/**
	 * Remove a student from repository, by id
	 */
	virtual void remove(int id) = 0;

	/**
	 * Get a student by id
	 */
	virtual Student* getById(int id) = 0;

	/**
	 * Count the number of students in repository
	 */
	virtual int size() = 0;

	/**
	 * Used to update persistent repository
	 */
	virtual void homeworkAssigned() = 0;

	virtual DynamicArray<Student>* getStudList() = 0;

	virtual ~StudentRepository() {};

private:
	DynamicArray<Student> _studList;
};


#endif /* STUDENTREPOSITORY_H_ */
