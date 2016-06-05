/*
 * ProductInMemoryRepository.cpp
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#include "ProductInMemoryRepository.h"

/**
 * Store a product
 * p - product to be stored
 * throw RepositoryException if a product with the same id already exists
 */
void ProductInMemoryRepository::store(Product& p) throw (RepositoryException) {
	//verify if we have a product withe same code
	const Product* aux = getByCode(p.getCode());
	if (aux != NULL) {
		throw RepositoryException("Product with the same code already exists");
	}
	prods.addE(&p);
}

/**
 * Count the number of products in the repository
 */
const Product* ProductInMemoryRepository::getByCode(int code) {
	for (int i = 0; i < prods.getSize(); i++) {
		if (prods.get(i)->getCode() == code) {
			return prods.get(i);
		}
	}
	return NULL;
}
/**
 * Count the number of products in the repository
 */
int ProductInMemoryRepository::getNrProducts() {
	return prods.getSize();
}
ProductInMemoryRepository::ProductInMemoryRepository() {

}

ProductInMemoryRepository::~ProductInMemoryRepository() {

}

