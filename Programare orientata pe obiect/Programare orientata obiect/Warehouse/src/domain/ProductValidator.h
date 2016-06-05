/*
 * ProductValidator.h
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#ifndef PRODUCTVALIDATOR_H_
#define PRODUCTVALIDATOR_H_
#include "Product.h"
#include <string>
/**
 * Generic exception used in the application
 * We will derive specialized exceptions from this class
 */
class MyException {
public:
	MyException(string& msg) {
		this->msg = msg;
	}
	const string& getMsg() const {
		return msg;
	}

private:
	string msg;
};

class ValidatorException: public MyException {
public:
	ValidatorException(string msg) :
			MyException(msg) {
	}

};

class ProductValidator {
public:
	/**
	 * validate a product
	 * a product is valid if the code>=0, price is >0
	 * the name is not empty
	 * throw ValidateException if the product is invalid
	 */
	void validate(Product p) throw (ValidatorException);
};

#endif /* PRODUCTVALIDATOR_H_ */
