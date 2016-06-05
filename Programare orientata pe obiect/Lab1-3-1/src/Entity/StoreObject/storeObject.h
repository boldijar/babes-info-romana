/*
 * storeObject.h
 *
 *  Created on: Mar 5, 2015
 *      Author: Nexflame
 */

#ifndef ENTITY_STOREOBJECT_STOREOBJECT_H_
#define ENTITY_STOREOBJECT_STOREOBJECT_H_

#include "../../Utils/utils.h"
#include "../Product/product.h"

typedef struct struct_Object
{
	int ID;
	Product* product;
	char* date;
	int price;
	int quantity;
}StoreObject;

void storeObject_init(StoreObject* this, int ID, Product* product, int price, char* date, int quantity);
void storeObject_destroy(StoreObject* this);

int storeObject_GetID(StoreObject* this);
Product* storeObject_GetProduct(StoreObject* this);
int storeObject_GetPrice(StoreObject* this);
void storeObject_SetPrice(StoreObject* this, int price);
char* storeObject_GetDate(StoreObject* this);
void storeObject_SetDate(StoreObject* this, char* date);
int storeObject_GetQuantity(StoreObject* this);
void storeObject_SetQuantity(StoreObject* this, int quantity);

#endif /* ENTITY_STOREOBJECT_STOREOBJECT_H_ */
