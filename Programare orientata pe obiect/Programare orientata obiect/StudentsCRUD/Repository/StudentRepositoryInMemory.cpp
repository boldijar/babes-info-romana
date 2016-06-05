/*
 * StudentRepository.cpp
 *
 *  Created on: 20.04.2012
 *      Author: Florin Mihalache
 */

#include "StudentRepositoryInMemory.h"

void StudentRepositoryInMemory::store(Student stud) {
	stud.setId(++_lastId);
	_studList.addElem(stud);
}

void StudentRepositoryInMemory::remove(int id) {
	DynamicArrayIterator<Student> it = _studList.begin();
	DynamicArrayIterator<Student> end = _studList.end();
	Student* stud;
	for (; it <= end; ++it) {
		stud = it.getElement();
		if (stud->id == id) {
			_studList.deleteElem(it.getPointee());
		}
	}
}

Student* StudentRepositoryInMemory::getById(int id) {
	if (size() == 0) {
		return NULL;
	}

	DynamicArrayIterator<Student> it = _studList.begin();
	DynamicArrayIterator<Student> end = _studList.end();
	Student* stud;
	for (; it <= end; ++it) {
		stud = it.getElement();
		if (stud->id == id) {
			return stud;
		}
	}
	return NULL;
}

int StudentRepositoryInMemory::size() {
	return _studList.getSize();
}
