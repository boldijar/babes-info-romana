/*
 * HomeworkRepository.cpp
 *
 *  Created on: 19.04.2012
 *      Author: Florin Mihalache
 */

#include "HomeworkRepositoryInMemory.h"
#include <iostream>

void HomeworkRepositoryInMemory::store(Homework hw) {
	_lastId++;
	hw.setId(_lastId);
	_hwList.addElem(hw);
}

void HomeworkRepositoryInMemory::remove(int id) {
	DynamicArrayIterator<Homework> it = _hwList.begin();
	DynamicArrayIterator<Homework> end = _hwList.end();
	Homework* hw;
	for (; it <= end; ++it) {
		hw = it.getElement();
		if (hw->id == id) {
			_hwList.deleteElem(it.getPointee());
		}
	}
}

Homework* HomeworkRepositoryInMemory::getById(int id) {
	if (size() == 0) {
		return NULL;
	}

	DynamicArrayIterator<Homework> it = _hwList.begin();
	DynamicArrayIterator<Homework> end = _hwList.end();
	Homework* hw;

	for (; it <= end; ++it) {
		hw = it.getElement();
		if (hw->id == id) {
			return hw;
		}
	}
	return NULL;
}

int HomeworkRepositoryInMemory::size() {
	return _hwList.getSize();
}
