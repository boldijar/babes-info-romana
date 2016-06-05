/*
 * ProductInMemoryRepository.h
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#ifndef PRODUCTINMEMORYREPOSITORY_H_
#define PRODUCTINMEMORYREPOSITORY_H_
#include "../domain/ProductRepository.h"
#include "../utils/DynamicArray.h"
/**
 * Store the products in memory (in a dynamic array)
 */
class ProductInMemoryRepository: public ProductRepository {
public:
	/**
	 * Store a product
	 * p - product to be stored
	 * throw RepositoryException if a product with the same id already exists
	 */
	void store(Product& p) throw (RepositoryException);
	/**
	 * Lookup product by code
	 * the code of the product
	 * return the product with the given code or NULL if the product not found
	 */
	const Product* getByCode(int code);
	/**
	 * Count the number of products in the repository
	 */
	int getNrProducts();

	ProductInMemoryRepository();
	~ProductInMemoryRepository();
private:
	DynamicArray<Product*> prods;
};

#endif /* PRODUCTINMEMORYREPOSITORY_H_ */
