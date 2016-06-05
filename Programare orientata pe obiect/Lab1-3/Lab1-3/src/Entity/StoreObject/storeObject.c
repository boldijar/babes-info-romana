/*
 * Object.c
 *
 *  Created on: Mar 5, 2015
 *      Author: Nexflame
 */

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "storeObject.h"

void storeObject_init(StoreObject* this, int ID, Product* product, int price, char* date, int quantity)
{
	if (!this)
	{
		printf("Error: StoreObject is NULL at creation! ABORT CREATION!(Undefined behavior will occur)\n");
		return;
	}

	this->ID = ID;

	if (!product)
		printf("Error: Product is NULL in constructor for object (ID: %d)(Undefined behavior will occur)\n", ID);
	this->product = product;

	this->date = malloc((strlen(date) + 1) * sizeof(char));
	strcpy(this->date, date);

	this->price = price;
	this->quantity = quantity;
}

void storeObject_destroy(StoreObject* this)
{
	if (!this)
	{
		printf("Error: StoreObject is NULL at destroy! ABORT DESTROY!(Undefined behavior will occur)\n");
		return;
	}

	this->ID = -1;
	this->price = -1;
	free(this->date);
	this->quantity = -1;

	// Destroy product + release memory
	product_destroy(storeObject_GetProduct(this));
	free(storeObject_GetProduct(this));
}

int storeObject_GetID(StoreObject* this)
{
	if (!this)
	{
		printf("Error: StoreObject is NULL at storeObject_GetID!\n");
		return -1;
	}

	return this->ID;
}

Product* storeObject_GetProduct(StoreObject* this)
{
	if (!this)
	{
		printf("Error: StoreObject is NULL at storeObject_GetProduct!\n");
		return NULL;
	}

	if (!this->product)
	{
		printf("Error: Product is NULL at storeObject_GetProduct!\n");
		return NULL;
	}

	return this->product;
}

int storeObject_GetPrice(StoreObject* this)
{
	if (!this)
	{
		printf("Error: StoreObject is NULL at storeObject_GetPrice!\n");
		return -1;
	}

	return this->price;
}

void storeObject_SetPrice(StoreObject* this, int price)
{
	if (!this)
	{
		printf("Error: StoreObject is NULL at storeObject_SetPrice!\n");
		return;
	}

	this->price = price;
}

char* storeObject_GetDate(StoreObject* this)
{
	if (!this)
	{
		printf("Error: StoreObject is NULL at storeObject_GetDate!\n");
		return NULL;
	}

	return this->date;
}

void storeObject_SetDate(StoreObject* this, char* date)
{
	if (!this)
	{
		printf("Error: StoreObject is NULL at storeObject_SetDate!\n");
		return;
	}

	if (!date)
	{
		printf("Error: Invalid string (date) passed in storeObject_SetDate!\n");
		return;
	}


	this->date = realloc(this->date, (strlen(date) + 1) * sizeof(char));
	strcpy(this->date, date);
}

int storeObject_GetQuantity(StoreObject* this)
{
	if (!this)
	{
		printf("Error: StoreObject is NULL at storeObject_GetQuantity!\n");
		return -1;
	}

	return this->quantity;
}

void storeObject_SetQuantity(StoreObject* this, int quantity)
{
	if (!this)
	{
		printf("Error: StoreObject is NULL at storeObject_SetQuantity!\n");
		return;
	}

	this->quantity = quantity;
}

