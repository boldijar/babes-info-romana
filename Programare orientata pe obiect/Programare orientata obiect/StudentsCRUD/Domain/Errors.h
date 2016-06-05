/*
 * Errors.h
 *
 *  Created on: 19.04.2012
 *      Author: Florin Mihalache
 */

#ifndef ERRORS_H_
#define ERRORS_H_

#include <string>
using namespace std;

class Error {
public:
	Error(string message) :
			msg(message) {
	}
	const string& getMessage() const {
		return msg;
	}
private:
	string msg;
};

class ValidationError: public Error {
public:
	ValidationError(string message) :
			Error(message) {
	}
};

class RepositoryError: public Error {
public:
	RepositoryError(string message) :
			Error(message) {
	}
};

#endif /* ERRORS_H_ */
