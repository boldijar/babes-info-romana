/*
 * testInMemoryRepo.h
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#ifndef TESTINMEMORYREPO_H_
#define TESTINMEMORYREPO_H_
#include "../domain/Product.h"
#include "ProductInMemoryRepository.h"
#include <assert.h>

void testStoreInMemory() {
	ProductInMemoryRepository repo;
	assert( repo.getNrProducts()==0);
	Product p(1, "1", 2.1);
	repo.store(p);
	assert( repo.getNrProducts()==1);
}

void testStoreExceptionInMemory() {
	ProductInMemoryRepository repo;
	Product p(1, "1", 2.1);
	repo.store(p);
	Product p2(1, "13", 7.1);
	try {
		repo.store(p2);
		assert(false);
		//if we get there is an error.. the store method should throw an exception
	} catch (RepositoryException& ex) {
		assert(true);
	}
}

void testGetByIdInMemory() {
	ProductInMemoryRepository repo;
	Product p(1, "1", 2.1);
	repo.store(p);
	assert( repo.getByCode(3)==NULL);
	assert( repo.getByCode(1)->getCode()==1);
}

#endif /* TESTINMEMORYREPO_H_ */
