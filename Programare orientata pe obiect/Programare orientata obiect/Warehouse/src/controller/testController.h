/*
 * testController.h
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#ifndef TESTCONTROLLER_H_
#define TESTCONTROLLER_H_
#include "Warehouse.h"
#include "../domain/Product.h"
#include "../domain/ProductValidator.h"
#include "../domain/ProductRepository.h"
#include "../repository/ProductInMemoryRepository.h"
#include <assert.h>
void testAdd() {
	ProductValidator* val = new ProductValidator();
	ProductRepository* repo = new ProductInMemoryRepository();
	Warehouse wh(repo, val);
	Product p = wh.addProduct(1, "das", 3.2);
	assert(p.getCode()==1);
	assert(p.getDescription()=="das");
	assert(p.getPrice()==3.2);
}

#endif /* TESTCONTROLLER_H_ */
