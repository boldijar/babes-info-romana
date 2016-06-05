/*
 * repo.h
 *
 *  Created on: Mar 5, 2015
 *      Author: Nexflame
 */

#ifndef REPOSITORY_REPOSITORY_H_
#define REPOSITORY_REPOSITORY_H_

#include "../Entity/StoreObject/storeObject.h"
#include "../Entity/Product/product.h"
#include "../Utils/vector/vector.h"

typedef struct struct_Repo
{
	char* fileName;
	Vector* objects;
}Repository;

// Private:
void repository__loadAll();

// Public:
void repository_init(Repository* this, char* fileName);
void repository_destroy(Repository* this);
int repository_GetSize(Repository* this);
void repository_AddObject(Repository* this, StoreObject* newObject);
StoreObject* repository_FindByID(Repository* this, int ID);
void repository_DeleteObjectByID(Repository* this, int ID);
void repository_Save(Repository* this);

#endif /* REPOSITORY_REPOSITORY_H_ */
