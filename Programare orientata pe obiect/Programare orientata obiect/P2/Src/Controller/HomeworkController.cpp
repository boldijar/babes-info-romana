/*
 * HomeworkController.cpp
 *
 *  Created on: 20.04.2012
 *      Author: Florin Mihalache
 */

#include "HomeworkController.h"

void HomeworkController::addHomework(string description) throw (ValidationError) {
	Homework hw(description);
	hw.setId(0);
	_validator->validate(hw);
	_repository->store(hw);
}

int HomeworkController::size() {
	return _repository->size();
}

void HomeworkController::updateHomework(int id, string newDesc) throw (ValidationError) {
	Homework* hw = _repository->getById(id);

	// validate the updated object before adding it in the repository
	Homework* check = new Homework(newDesc);
	check->setId(1);
	_validator->validate(*check);
	delete check;

	hw->description = newDesc;
}

void HomeworkController::removeHomework(int id) {
	_repository->remove(id);
}

Homework* HomeworkController::getById(int id) {
	return _repository->getById(id);
}

HomeworkController::~HomeworkController() {
	delete _repository;
	delete _validator;
}

