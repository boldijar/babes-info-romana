/*
 * ProductValidator.cpp
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#include "ProductValidator.h"

void ProductValidator::validate(Product p) throw (ValidatorException) {
	if (p.getCode() < 0) {
		throw ValidatorException("Code is < 0");
	}
	if (p.getDescription().length() == 0) {
		throw ValidatorException("Description is empty");
	}
	if (p.getPrice() <= 0) {
		throw ValidatorException("Price is negative");
	}
}
