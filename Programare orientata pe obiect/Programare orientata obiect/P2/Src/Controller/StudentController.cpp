/*
 * StudentController.cpp
 *
 *  Created on: 21.04.2012
 *      Author: Florin Mihalache
 */

#include "StudentController.h"

void StudentController::addStudent(string name, string group) throw (ValidationError) {
	Student stud(name, group);
	_validator->validate(stud);
	_repository->store(stud);
}

void StudentController::updateStudent(int id, string newName, string newGroup) throw (ValidationError) {
	Student* stud = _repository->getById(id);

	// validate the updated object before adding it in the repository
	Student* check = new Student(newName, newGroup);
	check->setId(1);
	_validator->validate(*check);
	delete check;

	stud->name = newName;
	stud->group = newGroup;
}

void StudentController::removeStudent(int id) {
	_repository->remove(id);
}

int StudentController::size() {
	return _repository->size();
}

void StudentController::assignHomework(int ahwId, int hwId, int studId, float grade) throw (ValidationError) {
	if (_hwRepository->getById(hwId) == NULL) {
		throw ValidationError("Homework with given id not found");
	}

	AssignedHw ahw;
	if (ahwId == 0)
			ahw.setAhwId(++_lastAhwId);
	else
		_lastAhwId = ahwId;
	ahw.setHwId(hwId);
	ahw.setGrade(grade);
	_ahwValidator->validate(ahw);

	Student* stud = _repository->getById(studId);
	if (stud == NULL) {
		throw ValidationError("Student with given id not found");
	}

	stud->addHwToList(ahw);
	_repository->homeworkAssigned();
}

Student* StudentController::getById(int id) {
	return _repository->getById(id);
}

StudentController::~StudentController() {
	delete _repository;
	delete _validator;
	delete _ahwValidator;
}

vector<AssignedHw>* StudentController::getHwList(int studId) {
	Student* stud;
	stud = getById(studId);
	return stud->getHwList();
}

