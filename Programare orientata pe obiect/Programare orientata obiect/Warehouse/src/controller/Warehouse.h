/*
 * Warehouse.h
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#ifndef WAREHOUSE_H_
#define WAREHOUSE_H_
#include "../domain/Product.h"
#include "../domain/ProductValidator.h"
#include "../domain/ProductRepository.h"

#include <string>
/**
 * Controller
 * Implement all the user actions
 */
class Warehouse {
public:
	/**
	 * Need a repo and a validator to do the job
	 */
	Warehouse(ProductRepository* repo, ProductValidator* validator);
	/**
	 * Add a product to the warehouse'
	 * code, desc, price of the product
	 * Throw ValidatorException if the product is invalid
	 * throw RepositoryExcepiton if a product with the given code already exists
	 */
	Product addProduct(int code, string desc, double price)
			throw (ValidatorException, RepositoryException);

	/**
	 * Responsable to de-allocate the repo and the validator
	 */
	~Warehouse();
private:
	ProductRepository* repo;
	ProductValidator* validator;
};

#endif /* WAREHOUSE_H_ */
