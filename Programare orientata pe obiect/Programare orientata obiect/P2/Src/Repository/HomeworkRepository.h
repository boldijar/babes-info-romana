/*
 * HomeworkRepository.h
 *
 *  Created on: 19.04.2012
 *      Author: Florin Mihalache
 */

#ifndef HOMEWORKREPOSITORY_H_
#define HOMEWORKREPOSITORY_H_
#include "../Domain/Homework.h"
#include "../Utils/DynamicArray.h"
#include "HomeworkRepository.h"

class HomeworkRepository {
public:
	/**
	 * Store a homework
	 * Pre: hw - homework to be stored
	 */
	virtual void store(Homework hw) = 0;

	/**
	 * Remove a homework from repository, by id
	 */
	virtual void remove(int id) = 0;

	/**
	 * Get a homework by id
	 */
	virtual Homework* getById(int id) = 0;

	/**
	 * Count the number of homeworks in repository
	 */
	virtual int size() = 0;

	virtual DynamicArray<Homework>* getHwList() = 0;

	virtual ~HomeworkRepository(){};

private:
	DynamicArray<Homework> _hwList;
};

#endif /* HOMEWORKREPOSITORY_H_ */
