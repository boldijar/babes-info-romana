/*
 * product.h
 *
 *  Created on: Mar 5, 2015
 *      Author: Nexflame
 */

#ifndef ENTITY_PRODUCT_H_
#define ENTITY_PRODUCT_H_

typedef struct struct_Product
{
	char* type;
	char* model;
	char* manufacturer;
}Product;

void product_init(Product* this, char* type, char* model, char* manufacturer);
void product_destroy(Product* this);

/*
 * Getters for Product
 */
char* product_GetType(Product* this);
char* product_GetModel(Product* this);
char* product_GetManufacturer(Product* this);

#endif /* ENTITY_PRODUCT_H_ */
