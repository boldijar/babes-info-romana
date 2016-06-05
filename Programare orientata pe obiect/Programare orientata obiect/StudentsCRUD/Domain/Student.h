/*
 * Student.h
 *
 *  Created on: 19.04.2012
 *      Author: Florin Mihalache
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include <vector>
#include "../Utils/DynamicArray.h"
using namespace std;

class Student {
public:
	int id;
	string name, group;

	/**
	 * Constructor
	 */
	Student(string name, string group) :
			id(0), name(name), group(group) {
	}
	Student() :
			id(0), name(""), group("") {
	}

	void setId(int id) {
		this->id = id;
	}

	int getId() {
		return id;
	}
};

#endif /* STUDENT_H_ */
