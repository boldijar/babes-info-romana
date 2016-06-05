/*
 * product.c
 *
 *  Created on: Mar 5, 2015
 *      Author: Nexflame
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "product.h"

void product_init(Product* this, char* type, char* model, char* manufacturer)
{
	if (!this)
	{
		printf("Error: Product is NULL at creation! ABORT CREATION!\n");
		return;
	}

	this->type = malloc(sizeof(char) * (strlen(type)+ 1));
	strcpy(this->type, type);

	this->model = malloc(sizeof(char) * (strlen(model) + 1));
	strcpy(this->model, model);

	this->manufacturer = malloc(sizeof(char) * (strlen(manufacturer) + 1));
	strcpy(this->manufacturer, manufacturer);
}

void product_destroy(Product* this)
{
	if (!this)
	{
		printf("Error: Product is NULL at destroy! ABORT DESTROY!\n");
		return;
	}

	free(this->type);
	this->type = NULL;

	free(this->model);
	this->model = NULL;

	free(this->manufacturer);
	this->manufacturer = NULL;
}

char* product_GetType(Product* this)
{
	if (!this)
		printf("Error: Product is NULL at getType!\n");

	return this->type;
}

char* product_GetModel(Product* this)
{
	if (!this)
		printf("Error: Product is NULL at getModel!\n");

	return this->model;
}

char* product_GetManufacturer(Product* this)
{
	if (!this)
		printf("Error: Product is NULL at getManufacturer!");

	return this->manufacturer;
}
