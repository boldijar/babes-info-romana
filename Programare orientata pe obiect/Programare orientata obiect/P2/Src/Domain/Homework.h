/*
 * Homework.h
 *
 *  Created on: 19.04.2012
 *      Author: Florin Mihalache
 */

#ifndef HOMEWORK_H_
#define HOMEWORK_H_
#include <string>
using namespace std;

class Homework {
public:
	int id;
	string description;

	/**
	 * Constructor
	 */
	Homework(string description) :
			id(0), description(description) {
	}
	Homework() :
		id(0), description("") {}

	void setId(int id) {
		this->id = id;
	}

	int getId() {
		return id;
	}
};

class AssignedHw {
public:
	int hwId, ahwId;
	float grade;

	void setAhwId(int id) {
		this->ahwId = id;
	}

	int getAhwId() {
		return ahwId;
	}

	void setHwId(int id) {
		this->hwId = id;
	}

	int getHwId() {
		return hwId;
	}

	void setGrade(float grade) {
		this->grade = grade;
	}

	float getGrade() {
		return grade;
	}

};

#endif /* HOMEWORK_H_ */
