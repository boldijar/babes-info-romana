/*
 * controller.c
 *
 *  Created on: Mar 10, 2015
 *      Author: Nexflame
 */

#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "controller.h"

void controller_init(Controller* this, Repository* repo)
{
	this->repo = repo;
	repository_init(this->repo, "file.txt");
}

void controller_destroy(Controller* this)
{
	repository_destroy(this->repo);
}


// Functionalities
Vector* controller_ExecShowAllObjects(Controller* this)
{
	if (!this)
	{
		printf("ERROR: Controller is NULL in controller_ExecShowAllObjects!");
		return NULL;
	}

	if (!this->repo)
	{
		printf("ERROR: Repo is NULL in controller_ExecShowAllObjects!");
		return NULL;
	}

	return this->repo->objects;
}

void controller_ExecAddObject(Controller* this, StoreObject* obj)
{
	if (!this)
	{
		printf("ERROR: Controller is NULL in controller_ExecAddObject!");
		return;
	}

	if (!this->repo)
	{
		printf("ERROR: Repo is NULL in controller_ExecAddObject!");
		return;
	}

	repository_AddObject(this->repo, obj);
	repository_Save(this->repo);
}

void controller_ExecDeleteObject(Controller* this, int ID)
{
	if (!this)
	{
		printf("ERROR: Controller is NULL in controller_ExecDeleteObject!");
		return;
	}

	if (!this->repo)
	{
		printf("ERROR: Repo is NULL in controller_ExecDeleteObject!");
		return;
	}

	repository_DeleteObjectByID(this->repo, ID);
	repository_Save(this->repo);
}

void controller_ExecUpdateObject(Controller* this, int ID, StoreObject* newObj)
{
	repository_DeleteObjectByID(this->repo, ID);
	repository_AddObject(this->repo, newObj);
	repository_Save(this->repo);
}

Vector* controller_ExecFilterObjects(Controller* this, FilterType filter, char* min, char* max)
{
	int i = 0;
	int len = repository_GetSize(this->repo);

	Vector* out = malloc(sizeof(Vector));
	vector_init(out);

	for (i = 0; i < len; ++i)
	{
		StoreObject* currObj = (StoreObject*)(vector_getAt(this->repo->objects, i));

		if (!currObj)
			continue;

		switch(filter)
		{
			case FILTER_BY_PRICE:
				if (atoi(min) <= storeObject_GetPrice(currObj) &&
					storeObject_GetPrice(currObj) <= atoi(max))
					vector_pushBack(out, currObj);
				break;
			case FILTER_BY_DATE:
				max = min;
				if (!strcmp(storeObject_GetDate(currObj), min))
					vector_pushBack(out, currObj);
				break;
			case FILTER_BY_MANUFACTURER:
				max = min;
				if (!strcmp(product_GetManufacturer(storeObject_GetProduct(currObj)), min))
					vector_pushBack(out, currObj);
				break;
			default:
				return out;
		}
	}
	return out;
}

/// PREDICATES FOR COMPARE

int __CompareDateAsc(const void* a, const void* b)
{
	StoreObject *pa = *(StoreObject**)a;
	StoreObject *pb = *(StoreObject**)b;

	// Cause we store date as DD.MM.YYYY we have to split this string and sort differently

	// HACK:
	// Compare Years: if same continue checking
	if (strcmp(storeObject_GetDate(pa) + 6, storeObject_GetDate(pb) + 6))
		return strcmp(storeObject_GetDate(pa) + 6, storeObject_GetDate(pb) + 6);

	// Compare Months
	if (strcmp(storeObject_GetDate(pa) + 3, storeObject_GetDate(pb) + 3))
		return strcmp(storeObject_GetDate(pa) + 3, storeObject_GetDate(pb) + 3);

	// Finally days
	return strcmp(storeObject_GetDate(pa), storeObject_GetDate(pb));
}

int __CompareDateDsc(const void* a, const void* b)
{
	StoreObject* pa = *(StoreObject**)a;
	StoreObject* pb = *(StoreObject**)b;

	// HACK:
	// Compare Years: if same continue checking
	if (strcmp(storeObject_GetDate(pa) + 6, storeObject_GetDate(pb) + 6))
		return -strcmp(storeObject_GetDate(pa) + 6, storeObject_GetDate(pb) + 6);

	// Compare Months
	if (strcmp(storeObject_GetDate(pa) + 3, storeObject_GetDate(pb) + 3))
		return -strcmp(storeObject_GetDate(pa) + 3, storeObject_GetDate(pb) + 3);

	// Finally days
	return -strcmp(storeObject_GetDate(pa), storeObject_GetDate(pb));
}

int __ComparePriceAsc(const void* a, const void* b)
{
	StoreObject* pa = *(StoreObject**)a;
	StoreObject* pb = *(StoreObject**)b;

	return storeObject_GetPrice(pa) - storeObject_GetPrice(pb);
}

int __ComparePriceDsc(const void* a, const void* b)
{
	StoreObject* pa = *(StoreObject**)a;
	StoreObject* pb = *(StoreObject**)b;

	return storeObject_GetPrice(pb) - storeObject_GetPrice(pa);
}

Vector* controller_ExecSortObjects(Controller* this, SortType sort, int asc)
{
	int i = 0;
	int len = repository_GetSize(this->repo);

	Vector* out = malloc(sizeof(Vector));
	vector_init(out);

	// Copy vector
	for (i = 0; i < len; ++i)
	{
		StoreObject* currObj = (StoreObject*)(vector_getAt(this->repo->objects, i));

		if (!currObj)
			continue;

    	vector_pushBack(out, currObj);
	}

	int (*cmp)(const void* a, const void* b);

	switch(sort)
	{
		case SORT_BY_PRICE:
			if (asc)
				cmp = &__ComparePriceAsc;
			else
				cmp = &__ComparePriceDsc;
			break;
		case SORT_BY_DATE:
			if (asc)
				cmp = &__CompareDateAsc;
			else
				cmp = &__CompareDateDsc;
			break;
		default:
			cmp = &__ComparePriceAsc;
	}

	qsort(out->entities, vector_getLen(out), sizeof(StoreObject*), cmp);
	return out;
}
