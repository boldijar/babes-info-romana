/*
 * test_product.c
 *
 *  Created on: Mar 9, 2015
 *      Author: Nexflame
 */

#include <assert.h>
#include <string.h>
#include <malloc.h>
#include "test_product.h"

void test_productCreate()
{
	Product prod;
	product_init(&prod, "Prastie", "V2.1", "China Factory");

	assert(_msize(prod.type) == (strlen("Prastie") + 1) * sizeof(char));
	assert(!strcmp(prod.type, "Prastie"));

	assert(_msize(prod.model) == (strlen("V2.1") + 1) * sizeof(char));
	assert(!strcmp(prod.model, "V2.1"));

	assert(_msize(prod.manufacturer) == (strlen("China Factory") + 1) * sizeof(char));
	assert(!strcmp(prod.manufacturer, "China Factory"));

	product_destroy(&prod);
	assert(_msize(prod.type) == -1);
	assert(_msize(prod.model) == -1);
	assert(_msize(prod.manufacturer) == -1);
}

void test_productGeters()
{
	Product prod;
	product_init(&prod, "Prastie", "V2.1", "China Factory");

	assert(_msize(product_GetType(&prod)) == (strlen("Prastie") + 1) * sizeof(char));
	assert(!strcmp(product_GetType(&prod), "Prastie"));

	assert(_msize(product_GetModel(&prod)) == (strlen("V2.1") + 1) * sizeof(char));
	assert(!strcmp(product_GetModel(&prod), "V2.1"));

	assert(_msize(product_GetManufacturer(&prod)) == (strlen("China Factory") + 1) * sizeof(char));
	assert(!strcmp(product_GetManufacturer(&prod), "China Factory"));

	product_destroy(&prod);
	assert(_msize(product_GetType(&prod)) == -1);
	assert(_msize(product_GetModel(&prod)) == -1);
	assert(_msize(product_GetManufacturer(&prod)) == -1);
}

void test_Products()
{
	test_productCreate();
	test_productGeters();
}
