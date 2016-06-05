/*
 * test_Repository.c
 *
 *  Created on: Mar 9, 2015
 *      Author: Nexflame
 */

#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "test_Repository.h"

void test_repositoryCreateDestroy()
{
	Repository repo;
	repository_init(&repo, "repoTests.txt");

	assert(_msize(repo.objects) == sizeof(Vector));

	assert(vector_getLen(repo.objects) == 10);

	// Test 2 elements
	// #1
	assert(storeObject_GetID(vector_getAt(repo.objects, 1)) == 2);
	assert(!strcmp(product_GetType(storeObject_GetProduct(vector_getAt(repo.objects, 1))), "Laptop"));
	assert(!strcmp(product_GetModel(storeObject_GetProduct(vector_getAt(repo.objects, 1))), "v3.2"));
	assert(!strcmp(product_GetManufacturer(storeObject_GetProduct(vector_getAt(repo.objects, 1))), "Lenovo"));
	assert(storeObject_GetPrice(vector_getAt(repo.objects, 1)) == 5200);
	assert(storeObject_GetQuantity(vector_getAt(repo.objects, 1)) == 69);

	// #2
	assert(storeObject_GetID(vector_getAt(repo.objects, 9)) == 10);
	assert(!strcmp(product_GetType(storeObject_GetProduct(vector_getAt(repo.objects, 9))), "Laptop"));
	assert(!strcmp(product_GetModel(storeObject_GetProduct(vector_getAt(repo.objects, 9))), "v12.3"));
	assert(!strcmp(product_GetManufacturer(storeObject_GetProduct(vector_getAt(repo.objects, 9))), "HP"));
	assert(storeObject_GetPrice(vector_getAt(repo.objects, 9)) == 2200);
	assert(storeObject_GetQuantity(vector_getAt(repo.objects, 9)) == 69);


	repository_destroy(&repo);
	//assert(_msize(repo.objects) == -1);
	//assert(_msize(repo.fileName) == -1);
}

void test_repositoryAddObject()
{
	Repository repo;
	repository_init(&repo, "repoTests.txt");

	assert(_msize(repo.objects) == sizeof(Vector));

	assert(vector_getLen(repo.objects) == 10);

	// Test 2 elements
	// #1
	assert(storeObject_GetID(vector_getAt(repo.objects, 1)) == 2);
	assert(!strcmp(product_GetType(storeObject_GetProduct(vector_getAt(repo.objects, 1))), "Laptop"));
	assert(!strcmp(product_GetModel(storeObject_GetProduct(vector_getAt(repo.objects, 1))), "v3.2"));
	assert(!strcmp(product_GetManufacturer(storeObject_GetProduct(vector_getAt(repo.objects, 1))), "Lenovo"));
	assert(storeObject_GetPrice(vector_getAt(repo.objects, 1)) == 5200);
	assert(storeObject_GetQuantity(vector_getAt(repo.objects, 1)) == 69);

	// #2
	assert(storeObject_GetID(vector_getAt(repo.objects, 9)) == 10);
	assert(!strcmp(product_GetType(storeObject_GetProduct(vector_getAt(repo.objects, 9))), "Laptop"));
	assert(!strcmp(product_GetModel(storeObject_GetProduct(vector_getAt(repo.objects, 9))), "v12.3"));
	assert(!strcmp(product_GetManufacturer(storeObject_GetProduct(vector_getAt(repo.objects, 9))), "HP"));
	assert(storeObject_GetPrice(vector_getAt(repo.objects, 9)) == 2200);
	assert(storeObject_GetQuantity(vector_getAt(repo.objects, 9)) == 69);

	// Create object
	StoreObject* obj = malloc(sizeof(StoreObject));
	Product* prod = malloc(sizeof(Product));
	product_init(prod, "Chitara", "Conteaza", "Made In China");
	storeObject_init(obj, 15, prod, 100, "azi", 200);

	// Add Object
	repository_AddObject(&repo, obj);

	assert(vector_getLen(repo.objects) == 11);

	assert(!strcmp(product_GetType(storeObject_GetProduct(vector_getAt(repo.objects, 10))), "Chitara"));
	assert(!strcmp(product_GetModel(storeObject_GetProduct(vector_getAt(repo.objects, 10))), "Conteaza"));
	assert(!strcmp(product_GetManufacturer(storeObject_GetProduct(vector_getAt(repo.objects, 10))), "Made In China"));
	assert(storeObject_GetPrice(vector_getAt(repo.objects, 10)) == 100);
	assert(storeObject_GetQuantity(vector_getAt(repo.objects, 10)) == 200);

	repository_destroy(&repo);
}

void test_repositoryFindByID()
{
	Repository repo;
	repository_init(&repo, "repoTests.txt");

	assert(_msize(repo.objects) == sizeof(Vector));

	assert(vector_getLen(repo.objects) == 10);

	StoreObject* obj = repository_FindByID(&repo, 5);
	assert(storeObject_GetID(obj) == 5);
	assert(!strcmp(product_GetType(storeObject_GetProduct(obj)), "Laptop"));
	assert(!strcmp(product_GetModel(storeObject_GetProduct(obj)), "v2.2"));
	assert(!strcmp(product_GetManufacturer(storeObject_GetProduct(obj)), "Dell"));
	assert(storeObject_GetPrice(obj) == 7200);
	assert(storeObject_GetQuantity(obj) == 89);

	repository_destroy(&repo);
}

void test_repositoryDeleteByID()
{
	Repository repo;
	repository_init(&repo, "repoTests.txt");

	assert(_msize(repo.objects) == sizeof(Vector));

	assert(vector_getLen(repo.objects) == 10);

	StoreObject* obj6 = repository_FindByID(&repo, 6);
	int oldSize = repository_GetSize(&repo);

	// remove Obj5 and test if obj6 is in his place
	repository_DeleteObjectByID(&repo, 5);

	assert(repository_GetSize(&repo) == oldSize - 1);
	assert(vector_getAt(repo.objects, 4) == obj6);

	repository_destroy(&repo);
}

void test_repositorySave()
{
	Repository repo;
	repository_init(&repo, "repoTests.txt");

	assert(_msize(repo.objects) == sizeof(Vector));

	assert(vector_getLen(repo.objects) == 10);

	// Create object
	StoreObject* obj = malloc(sizeof(StoreObject));
	Product* prod = malloc(sizeof(Product));
	product_init(prod, "Chitara", "Conteaza", "MadeInChina");
	storeObject_init(obj, 15, prod, 100, "azi", 200);

	// Add Object
	repository_AddObject(&repo, obj);

	repository_Save(&repo);
	repository_destroy(&repo);

	Repository repo2;
	repository_init(&repo2, "repoTests.txt");

	assert(_msize(repo2.objects) == sizeof(Vector));

	assert(vector_getLen(repo2.objects) == 11);

	repository_DeleteObjectByID(&repo2, 15);
	repository_Save(&repo2);

	repository_destroy(&repo2);
}

void test_Repositories()
{
	test_repositoryCreateDestroy();
	test_repositoryAddObject();
	test_repositoryFindByID();
	test_repositoryDeleteByID();
	test_repositorySave();
}
