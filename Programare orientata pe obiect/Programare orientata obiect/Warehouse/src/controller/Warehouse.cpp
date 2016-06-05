/*
 * Warehouse.cpp
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#include "Warehouse.h"

Warehouse::Warehouse(ProductRepository *repo, ProductValidator* val) {
	this->repo = repo;
	validator = val;
}
Product Warehouse::addProduct(int code, string desc, double price)
		throw (ValidatorException, RepositoryException) {
	//create product
	Product p(code, desc, price);
	//validate product
	validator->validate(p);
	//store product
	repo->store(p);
	return p;
}

Warehouse::~Warehouse() {
	delete repo;
	delete validator;
}
