/*
 * HomeworkRepository.h
 *
 *  Created on: 19.04.2012
 *      Author: Florin Mihalache
 */

#ifndef HOMEWORKREPOSITORYINMEMORY_H_
#define HOMEWORKREPOSITORYINMEMORY_H_
#include "../Domain/Homework.h"
#include "../Domain/Validators.h"
#include "../Utils/DynamicArray.h"
#include "HomeworkRepository.h"

class HomeworkRepositoryInMemory: public HomeworkRepository {
public:
	HomeworkRepositoryInMemory() :
		_lastId(0) {
	}

	/**
	 * Store a homework
	 * Pre: hw - homework to be stored
	 */
	void store(Homework hw);

	/**
	 * Remove a homework from repository, by id
	 */
	void remove(int id);

	/**
	 * Get a homework by id
	 */
	Homework* getById(int id);

	/**
	 * Count the number of homeworks in repository
	 */
	int size();

	DynamicArray<Homework>* getHwList() {
		return &_hwList;
	}

private:
	DynamicArray<Homework> _hwList;
	int _lastId;
};

#endif /* HOMEWORKREPOSITORYINMEMORY_H_ */
