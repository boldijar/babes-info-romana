/*
 * StudentRepositoryFile.cpp
 *
 *  Created on: 20.04.2012
 *      Author: Florin Mihalache
 */

#include "StudentRepositoryFile.h"
#include <fstream>
#include <string>
#include <stdlib.h>

void StudentRepositoryFile::store(Student stud) {
	stud.setId(++_lastId);
	_studList.addElem(stud);
	updateFile();
}

void StudentRepositoryFile::store(Student stud, int fromFile) {
	_studList.addElem(stud);
}

void StudentRepositoryFile::remove(int id) {
	DynamicArrayIterator<Student> it = _studList.begin();
	DynamicArrayIterator<Student> end = _studList.end();
	Student* stud;
	for (; it <= end; ++it) {
		stud = it.getElement();
		if (stud->id == id) {
			_studList.deleteElem(it.getPointee());
		}
	}
	updateFile();
}

Student* StudentRepositoryFile::getById(int id) {
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

int StudentRepositoryFile::size() {
	return _studList.getSize();
}

void StudentRepositoryFile::readAllFromFile() {
	ifstream file;
	file.open(STUDFILE);
	string line;
	Student* studX = new Student();
	AssignedHw* ahwX;
	int pos = -1;
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			if (!line.empty()) {
				if (line == "*") { // read homeworks
					getline(file, line);
					ahwX = new AssignedHw();
					ahwX->ahwId = atoi(line.c_str());
					_lastAhwId = ahwX->ahwId;
					getline(file, line);
					ahwX->hwId = atoi(line.c_str());
					getline(file, line);
					ahwX->grade = atof(line.c_str());

					_studList.getElem(pos)->addHwToList(*ahwX);
					delete ahwX;
				} else {
					// read student
					delete studX;
					studX = new Student();
					studX->id = atoi(line.c_str());
					_lastId = atoi(line.c_str());
					getline(file, line);
					studX->name = line;
					getline(file, line);
					studX->group = line;
					store(*studX, 1);
					pos++;
				}
			}
		}
		file.close();
	}
}

void StudentRepositoryFile::homeworkAssigned() {
	updateFile();
}

void StudentRepositoryFile::updateFile() {
	ofstream file;
	file.open(STUDFILE);

	DynamicArrayIterator<Student> it = _studList.begin();
	DynamicArrayIterator<Student> end = _studList.end();
	Student* studX;
	vector<AssignedHw>* hwList;
	AssignedHw* ahw;

	while (it <= end) {
		studX = it.getElement();
		file << studX->getId() << endl;
		file << studX->name << endl;
		file << studX->group << endl;
		hwList = studX->getHwList();
		if (hwList->size() != 0) { // the student has assigned homeworks
			vector<AssignedHw>::iterator itH = hwList->begin();
			vector<AssignedHw>::iterator endH = hwList->end();
			while (itH != endH) {
				ahw = &(*itH);
				file << "*" << endl;
				file << ahw->ahwId << endl;
				file << ahw->hwId << endl;
				file << ahw->grade << endl;
				++itH;
			}
		}
		++it;
	}
	file.close();
}

