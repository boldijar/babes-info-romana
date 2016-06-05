/*
 * StudentRepositoryFile.h
 *
 *  Created on: 20.04.2012
 *      Author: Florin Mihalache
 */

#ifndef STUDENTREPOSITORYFILE_H_
#define STUDENTREPOSITORYFile_H_

#include "../Domain/Student.h"
#include "../Domain/Validators.h"
#include "../Utils/DynamicArray.h"
#include "StudentRepository.h"
#define STUDFILE "Data/students.dat"

class StudentRepositoryFile: public StudentRepository {
public:
	StudentRepositoryFile() {
		_lastId = 0;
		readAllFromFile();
	}

	/**
	 * Store a student
	 * Pre: stud - student to be stored
	 */
	void store(Student stud);
	void store(Student stud, int fromFile);

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

	void readAllFromFile();
	void updateFile();

private:
	DynamicArray<Student> _studList;
    int _lastId;
};


#endif /* STUDENTREPOSITORYFILE_H_ */
