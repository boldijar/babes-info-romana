/*
 * HomeworkRepositoryFile.cpp
 *
 *  Created on: 10.05.2012
 *      Author: Florin Mihalache
 */
#include "HomeworkRepositoryFile.h"
#include <fstream>
#include <string>
#include <stdlib.h>

void HomeworkRepositoryFile::store(Homework hw) {
	hw.setId(++_lastId);
	_hwList.addElem(hw);
	updateFile();
}

void HomeworkRepositoryFile::store(Homework hw, int fromFile) {
	_hwList.addElem(hw);
}

void HomeworkRepositoryFile::remove(int id) {
	DynamicArrayIterator<Homework> it = _hwList.begin();
	DynamicArrayIterator<Homework> end = _hwList.end();
	Homework* hw;
	for (; it <= end; ++it) {
		hw = it.getElement();
		if (hw->id == id) {
			_hwList.deleteElem(it.getPointee());
		}
	}
	updateFile();
}

void HomeworkRepositoryFile::readAllFromFile() {
	ifstream file;
	file.open(HWFILENAME);
	string line;
	Homework hwX;
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			if (!line.empty()) {
				hwX.id = atoi(line.c_str());
				_lastId = atoi(line.c_str());
				getline(file, line);
				hwX.description = line;
				store(hwX, 1);
			}
		}
		file.close();
	}
}

void HomeworkRepositoryFile::updateFile() {
	ofstream file;
	file.open(HWFILENAME);

	DynamicArrayIterator<Homework> it = _hwList.begin();
	DynamicArrayIterator<Homework> end = _hwList.end();
	Homework* hwX;

	while (it <= end) {
		hwX = it.getElement();
		file << hwX->getId() << endl;
		file << hwX->description << endl;
		++it;
	}
	file.close();
}

Homework* HomeworkRepositoryFile::getById(int id) {
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

int HomeworkRepositoryFile::size() {
	return _hwList.getSize();
}


