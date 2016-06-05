/*
 * test_storeObject.c
 *
 *  Created on: Mar 9, 2015
 *      Author: Nexflame
 */

#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "test_storeObject.h"
#include "../../Entity/Product/product.h"

void test_StoreObjectCreate()
{
	StoreObject obj;

	// Product should be on heap(dynamically allocated)
	Product* prod = malloc(sizeof(Product));
	product_init(prod, "Mere", "v1", "Acasa");

	storeObject_init(&obj, 1, prod, 100, "azi", 200);
	assert(_msize(obj.product) == sizeof(Product));

	// Check values
	assert(obj.ID == 1);
	assert(obj.price == 100);
	assert(!strcmp(obj.date, "azi"));
	assert(obj.quantity == 200);
	// Check Product values
	assert(!strcmp(product_GetType(storeObject_GetProduct(&obj)), "Mere"));
	assert(!strcmp(product_GetModel(storeObject_GetProduct(&obj)), "v1"));
	assert(!strcmp(product_GetManufacturer(storeObject_GetProduct(&obj)), "Acasa"));

	storeObject_destroy(&obj);
	//assert(_msize(obj.product) == -1);
	//assert(_msize(prod) == -1);

	assert(obj.ID == -1);
	assert(obj.price == -1);
	assert(obj.quantity == -1);
}

void test_StoreObjectGettersSetters()
{
	StoreObject obj;

	// Product should be on heap(dynamically allocated)
	Product* prod = malloc(sizeof(Product));
	product_init(prod, "Mere", "v1", "Acasa");

	storeObject_init(&obj, 1, prod, 100, "azi", 200);
	assert(_msize(obj.product) == sizeof(Product));

	// Check Product values
	assert(!strcmp(product_GetType(storeObject_GetProduct(&obj)), "Mere"));
	assert(!strcmp(product_GetModel(storeObject_GetProduct(&obj)), "v1"));
	assert(!strcmp(product_GetManufacturer(storeObject_GetProduct(&obj)), "Acasa"));

	// Getters
	assert(storeObject_GetID(&obj) == 1);
	assert(storeObject_GetPrice(&obj) == 100);
	assert(!strcmp(storeObject_GetDate(&obj), "azi"));
	assert(storeObject_GetQuantity(&obj) == 200);

	// Setters
	storeObject_SetPrice(&obj, 555);
	assert(storeObject_GetPrice(&obj) == 555);

	storeObject_SetDate(&obj, "maine");
	assert(!strcmp(storeObject_GetDate(&obj), "maine"));

	storeObject_SetQuantity(&obj, 1234);
	assert(storeObject_GetQuantity(&obj) == 1234);

	storeObject_destroy(&obj);
	//assert(_msize(obj.product) == -1);
	//assert(_msize(prod) == -1);

	assert(storeObject_GetID(&obj) == -1);
	assert(storeObject_GetPrice(&obj) == -1);
	assert(storeObject_GetQuantity(&obj) == -1);
}

void test_SotreObjects()
{
	test_StoreObjectCreate();
	test_StoreObjectGettersSetters();
}
