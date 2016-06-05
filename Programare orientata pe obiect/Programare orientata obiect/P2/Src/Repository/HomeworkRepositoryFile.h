/*
 * HomeworkRepository.h
 *
 *  Created on: 19.04.2012
 *      Author: Florin Mihalache
 */

#ifndef HOMEWORKREPOSITORYFILE_H_
#define HOMEWORKREPOSITORYFILE_H_
#include "../Domain/Homework.h"
#include "../Domain/Validators.h"
#include "../Utils/DynamicArray.h"
#include "../Repository/HomeworkRepository.h"
#define HWFILENAME "Data/homeworks.dat"

class HomeworkRepositoryFile: public HomeworkRepository {
public:
	HomeworkRepositoryFile() {
		_lastId = 0;
		readAllFromFile();
	}

	/**
	 * Store a homework
	 * Pre: hw - homework to be stored
	 */
	void store(Homework hw);

	void store(Homework hw, int fromFile);

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

	void readAllFromFile();
	void updateFile();

private:
	DynamicArray<Homework> _hwList;
	int _lastId;
};

#endif /* HOMEWORKREPOSITORYFILE_H_ */
