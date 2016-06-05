/*
 * HomeworkController.h
 *
 *  Created on: 20.04.2012
 *      Author: Florin Mihalache
 */

#ifndef HOMEWORKCONTROLLER_H_
#define HOMEWORKCONTROLLER_H_
#include "../Domain/Homework.h"
#include "../Domain/Validators.h"
#include "../Repository/HomeworkRepository.h"
#include <string>

class HomeworkController {
public:
	/**
	 * Constructor
	 * Needs a repository and a validator
	 */
	HomeworkController(HomeworkRepository* repository, HomeworkValidator* validator) :
			_repository(repository), _validator(validator) {
	}

	/**
	 * Add a homework
	 * The id is generated automatically
	 * Throws ValidationError if description is empty
	 */
	void addHomework(string description) throw (ValidationError);

	/**
	 * Update a homework
	 * 		id - homework id
	 * 		newDesc - new description for the homework
	 * The id cannot be changed
	 */
	void updateHomework(int id, string newDesc) throw (ValidationError);

	/**
	 * Remove a homework by id
	 */
	void removeHomework(int id);

	/**
	 * Number of homeworks stored
	 */
	int size();

	/**
	 * Get a homework by id
	 */
	Homework* getById(int id);

	/**
	 * Destructor
	 */
	~HomeworkController();

	DynamicArray<Homework>* getHwList() {
		return _repository->getHwList();
	}

private:
	HomeworkRepository* _repository;
	HomeworkValidator* _validator;
};


#endif /* HOMEWORKCONTROLLER_H_ */
