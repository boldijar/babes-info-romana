/*
 * testProduct.h
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#ifndef TESTPRODUCT_H_
#define TESTPRODUCT_H_

#include "Product.h"
#include "ProductValidator.h"
#include <assert.h>

void testCreateProduct() {
	Product p(1, "descr", 3.3);
	assert(p.getCode() == 1);
	assert(p.getDescription()=="descr");
	assert(p.getPrice()==3.3);
}

void testValidateProduct() {
	Product p(1, "descr", 3.3);
	ProductValidator val;
	val.validate(p);

	Product p1(-1, "descr", 3.3);
	try {
		val.validate(p1);
		assert(false);
	} catch (ValidatorException& e) {
		assert(true);
	}

	Product p2(1, "", 3.3);
	try {
		val.validate(p2);
		assert(false);
	} catch (ValidatorException& e) {
		assert(true);
	}

	Product p3(1, "d", 0);
	try {
		val.validate(p3);
		assert(false);
	} catch (ValidatorException& e) {
		assert(true);
	}
}

#endif /* TESTPRODUCT_H_ */
