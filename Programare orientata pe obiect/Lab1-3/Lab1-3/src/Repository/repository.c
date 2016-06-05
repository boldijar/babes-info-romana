/*
 * repo.c
 *
 *  Created on: Mar 5, 2015
 *      Author: Nexflame
 */

#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "repository.h"

void repository__loadAll(Repository* this)
{
	if (!this)
	{
		printf("Error: Repository is NULL in repository__loadAll! ABORT READ FILE!");
		return;
	}

	if (!this->fileName)
	{
		printf("Error: No given FileName in repository__loadAll! ABORT READ FILE!");
		return;
	}

	FILE* loader = fopen(this->fileName, "r");

	if (!loader)
	{
		printf("Error: Can't find file (File name: %s) in repository__loadAll! ABORT READ FILE!", this->fileName);
		return;
	}

	char* line = malloc(512 * sizeof(char));
	int lineCounter = 1;
	while (fgets(line, 512, loader))
    {
		// Split this line after this format:
		// 1.ID(int) 2.ProductType(char*) 3.ProductModel(char*) 4.ProductManufacturer(char*) 5.Price(int) 6.Date(char*) 7.Quality(int)

		char* tmp = malloc((strlen(line) + 1) * sizeof(char));
		strcpy(tmp, line);

		char* token = strtok(tmp, " ");
		int tokenNr = 0;

		// Store all token in vector
		Vector tokens;
		vector_init(&tokens);

		while (token)
		{
			vector_pushBack(&tokens, token);
			token = strtok(NULL, " ");
			++tokenNr;
		}

		if (vector_getLen(&tokens) == 7)
		{
			// Create StoreObject and store it
			// 1. Get ID
			int id = atoi(vector_getAt(&tokens, 0));

			// 2, 3, 4. Get Product
			char* productType = malloc((strlen(vector_getAt(&tokens, 1)) + 1) * sizeof(char));
			char* productModel = malloc((strlen(vector_getAt(&tokens, 2)) + 1)  * sizeof(char));
			char* productManufacturer = malloc((strlen(vector_getAt(&tokens, 3)) + 1)  * sizeof(char));

			strcpy(productType, vector_getAt(&tokens, 1));
			strcpy(productModel, vector_getAt(&tokens, 2));
			strcpy(productManufacturer, vector_getAt(&tokens, 3));

			Product* prod = malloc(sizeof(Product));
			product_init(prod, productType, productModel, productManufacturer);

			// 5. Get Price
			int price = atoi(vector_getAt(&tokens, 4));
			// 6. Get Date
			char* date = malloc((strlen(vector_getAt(&tokens, 5)) + 1) * sizeof(char));
			strcpy(date, vector_getAt(&tokens, 5));
			// 7. Get Quality
			int quantity = atoi(vector_getAt(&tokens, 6));

			StoreObject* obj = malloc(sizeof(StoreObject));
			storeObject_init(obj, id, prod, price, date, quantity);

			repository_AddObject(this, obj);

			// Free memory
			free(productType);
			free(productModel);
			free(productManufacturer);
			free(date);
		}
		else
			printf("Error: Not enough parameters (found: %d) found while reading file (File Name: %s) on line: %d (Continue reading next line!)\n", vector_getLen(&tokens), this->fileName, lineCounter);

		// Free memory
		vector_destroy(&tokens);
		free(tmp);
		++lineCounter;
    }

	fclose(loader);
}

void repository__saveAll(Repository* this)
{
	if (!this)
	{
		printf("Error: Repository is NULL in repository__loadAll! ABORT WRITE FILE!");
		return;
	}

	if (!this->fileName)
	{
		printf("Error: No given FileName in repository__loadAll! ABORT WRITE FILE!");
		return;
	}

	FILE* writer = fopen(this->fileName, "w");

	if (!writer)
	{
		printf("Error: Can't find file (File name: %s) in repository__loadAll! ABORT WRITE FILE!", this->fileName);
		return;
	}

	int i = 0;
	int len = repository_GetSize(this);
	for (i = 0; i < len; ++i)
	{
		StoreObject* currObj = (StoreObject*)(vector_getAt(this->objects, i));
		if (currObj)
			fprintf(writer, "%d %s %s %s %d %s %d\n", 	storeObject_GetID(currObj),
														product_GetType(storeObject_GetProduct(currObj)),
														product_GetModel(storeObject_GetProduct(currObj)),
														product_GetManufacturer(storeObject_GetProduct(currObj)),
														storeObject_GetPrice(currObj), storeObject_GetDate(currObj),
														storeObject_GetQuantity(currObj));
	}
	fclose(writer);
}

void repository_init(Repository* this, char* fileName)
{
	if (!this)
	{
		printf("Error: Repository is NULL in repository_init! ABBORT CREATING!\n");
		return;
	}

	this->objects = malloc(sizeof(Vector));
	vector_init(this->objects);

	this->fileName = NULL;

	if (!fileName)
		printf("Error: No initial file to load at initializing repository.\n");
	else
	{
		this->fileName = malloc((strlen(fileName) + 1) * sizeof(char));
		strcpy(this->fileName, fileName);
		repository__loadAll(this);
	}
}

void repository_destroy(Repository* this)
{
	if (!this)
	{
		printf("Error: Repository is NULL in repository_destroy! ABBORT DESTROING!\n");
		return;
	}

	if (this->fileName)
		free(this->fileName);

	// Go through all elements of vector and deallocate them
	int i;
	int len = vector_getLen(this->objects);
	for (i = 0; i < len; ++i)
		storeObject_destroy(vector_getAt(this->objects, i));

	vector_destroy(this->objects);
	free(this->objects);
}

int repository_GetSize(Repository* this)
{
	if (!this)
	{
		printf("Error: Repository is NULL in repository_GetSize!");
		return -1;
	}

	if (!this->objects)
	{
		printf("Error: Vector is uninitialized in repository_GetSize!");
		return -1;
	}

	return vector_getLen(this->objects);
}

void repository_AddObject(Repository* this, StoreObject* newObject)
{
	if (!this)
	{
		printf("Error: Repository is NULL in repository_AddObject! ABBORT ADDING!\n");
		return;
	}

	if (!newObject)
	{
		printf("Error: SotreObject is NULL in repository_AddObject! ABBORT ADDING!\n");
		return;
	}

	if (repository_FindByID(this, storeObject_GetID(newObject)))
	{
		printf("Error: Object (ID: %d) already in repository! ABBORT ADDING!\n", storeObject_GetID(newObject));
		return;
	}

	vector_pushBack(this->objects, newObject);
}

StoreObject* repository_FindByID(Repository* this, int ID)
{
	if (!this)
	{
		printf("Error: Repository is NULL in repository_FindByID! ABBORT FINDING!");
		return NULL;
	}

	int i = 0;
	int len = repository_GetSize(this);
	for (i = 0; i < len; ++i)
		if (storeObject_GetID(vector_getAt(this->objects, i)) == ID)
			return vector_getAt(this->objects, i);
	return NULL;
}

void repository_DeleteObjectByID(Repository* this, int ID)
{
	if (!this)
	{
		printf("Error: Repository is NULL in repository_DeleteObjectByID! ABBORT DELETING!");
		return;
	}

	int i = 0;
	int len = repository_GetSize(this);
	for (i = 0; i < len; ++i)
		if (storeObject_GetID(vector_getAt(this->objects, i)) == ID)
		{
			vector_removeAt(this->objects, i);
			return;
		}

	// Not found -> Send error
	printf("Error: No object found with ID: %d in repository!", ID);
}

void repository_Save(Repository* this)
{
	if (!this)
	{
		printf("Error: Repository is NULL in repository_Save! ABBORT SAVING!");
		return;
	}

	repository__saveAll(this);
}
