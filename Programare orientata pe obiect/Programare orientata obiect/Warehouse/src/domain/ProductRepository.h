/*
 * ProductRepository.h
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#ifndef PRODUCTREPOSITORY_H_
#define PRODUCTREPOSITORY_H_
#include "Product.h"
#include "ProductValidator.h"
class RepositoryException: public MyException {
public:
	RepositoryException(string msg) :
			MyException(msg) {
	}
};
/**
 * Repository for products
 * Abstract base class for repository (memory, file)
 */
class ProductRepository {
public:
	/**
	 * Store a product
	 * p - product to be stored
	 * throw RepositoryException if a product with the same id already exists
	 */
	virtual void store(Product& p) throw (RepositoryException) = 0;

	/**
	 * Lookup product by code
	 * the code of the product
	 * return the product with the given code or NULL if the product not found
	 */
	virtual const Product* getByCode(int code) = 0;

	/**
	 * Count the number of products in the repository
	 */
	virtual int getNrProducts() = 0;

};

#endif /* PRODUCTREPOSITORY_H_ */
