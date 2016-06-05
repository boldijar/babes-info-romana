/*
 * ui.c
 *
 *  Created on: Mar 10, 2015
 *      Author: Nexflame
 */

#include <stdio.h>
#include <malloc.h>
#include "ui.h"

void ui__printMenu()
{
	printf("Menu:\n");
	printf("1. Show objects in store\n");
	printf("2. Add object in store\n");
	printf("3. Delete object from store\n");
	printf("4. Update object in store\n");
	printf("5. Filter objects in store by price:\n");
	printf("6. Filter objects in store by date:\n");
	printf("7. Filter objects in store by manufacturer:\n");
	printf("8. Sort objects by price ascending\n");
	printf("9. Sort objects by price descending\n");
	printf("10. Sort objects by date ascending\n");
	printf("11. Sort objects by date descending\n");
	printf("\n0. Exit\n");
	printf("Give command:");
}

int ui__getCMD()
{
	int cmd = EXIT_CMD;

	scanf("%d", &cmd);

	if ((Commands)cmd >= (Commands)MAX_COMMANDS || (Commands)cmd < EXIT_CMD)
		return ERROR_CMD;
	return cmd;
}

////////////////////////////////
//     		COMMANDS
////////////////////////////////

void ui_execCMDShowAllObjects(UI* this)
{
	Vector* vect = controller_ExecShowAllObjects(this->ctrl);

	int i = 0;
	int len = vector_getLen(vect);

	for (i = 0; i < len; ++i)
	{
		StoreObject* currObj = (StoreObject*)(vector_getAt(vect, i));
		if (currObj)
			printf("%d %s %s %s %d %s %d\n", 	storeObject_GetID(currObj),
												product_GetType(storeObject_GetProduct(currObj)),
												product_GetModel(storeObject_GetProduct(currObj)),
												product_GetManufacturer(storeObject_GetProduct(currObj)),
												storeObject_GetPrice(currObj), storeObject_GetDate(currObj),
												storeObject_GetQuantity(currObj));
	}
	printf("\n");
}

void ui_execCMDAddObject(UI* this)
{
	// Collect infos from typer
	int ID;
	char* date = malloc(256 * sizeof(char));
	int price;
	int quantity;

	Product* product = malloc(sizeof(Product));
	char* product_Type = malloc(256 * sizeof(char));
	char* product_Model = malloc(256 * sizeof(char));
	char* product_Manufacturer = malloc(256 * sizeof(char));

	printf("Give an ID: ");
	scanf("%d", &ID);
	// Validate ID

	// Product
	printf("Give a Product Type: ");
	scanf("%s", product_Type);
	// Validate Product Type
	printf("Give a Product Model: ");
	scanf("%s", product_Model);
	// Validate Product Model
	printf("Give a Product Manufacturer: ");
	scanf("%s", product_Manufacturer);
	// Validate Product Manufacturer
	// Make Product
	product_init(product, product_Type, product_Model, product_Manufacturer);

	printf("Give a Price: ");
	scanf("%d", &price);
	// Validate Price

	printf("Give Date: ");
	scanf("%s", date);
	// Validate Date

	printf("Give Quantity: ");
	scanf("%d", &quantity);
	// Validate quantity

	// Make StoreObject
	StoreObject* obj = malloc(sizeof(StoreObject));
	storeObject_init(obj, ID, product, price, date, quantity);

	controller_ExecAddObject(this->ctrl, obj);
	// Only free do not destroy entire object
	free(product_Type);
	free(product_Model);
	free(product_Manufacturer);
	free(date);
}

void ui_execCMDDeleteObject(UI* this)
{
	int ID;

	printf("Give an ID: ");
	scanf("%d", &ID);
	// Validate ID

	controller_ExecDeleteObject(this->ctrl, ID);
}

void ui_execCMDUpdateObject(UI* this)
{
	int ID;

	printf("Give ID for current product: ");
	scanf("%d", &ID);
	// Validate ID

	// Collect infos from typer
	char* date = malloc(256 * sizeof(char));
	int price;
	int quantity;

	Product* product = malloc(sizeof(Product));
	char* product_Type = malloc(256 * sizeof(char));
	char* product_Model = malloc(256 * sizeof(char));
	char* product_Manufacturer = malloc(256 * sizeof(char));

	// Product
	printf("Give a Product Type: ");
	scanf("%s", product_Type);
	// Validate Product Type
	printf("Give a Product Model: ");
	scanf("%s", product_Model);
	// Validate Product Model
	printf("Give a Product Manufacturer: ");
	scanf("%s", product_Manufacturer);
	// Validate Product Manufacturer
	// Make Product
	product_init(product, product_Type, product_Model, product_Manufacturer);

	printf("Give a Price: ");
	scanf("%d", &price);
	// Validate Price

	printf("Give Date: ");
	scanf("%s", date);
	// Validate Date

	printf("Give Quantity: ");
	scanf("%d", &quantity);
	// Validate quantity

	// Make StoreObject
	StoreObject* obj = malloc(sizeof(StoreObject));
	storeObject_init(obj, ID, product, price, date, quantity);


	controller_ExecUpdateObject(this->ctrl, ID, obj);

	// Free objects cause we deep-copy them
	free(product_Type);
	free(product_Model);
	free(product_Manufacturer);
	free(date);
}

void ui_execCMDFilterObjects(UI* this, FilterType filter)
{
	char* min = malloc(256 * sizeof(char));
	char* max = malloc(256 * sizeof(char));

	switch (filter)
	{
		case FILTER_BY_PRICE:
			printf("Give minimum price:\n");
			scanf("%s", min);
			printf("Give maximum price:\n");
			scanf("%s", max);
			break;
		case FILTER_BY_DATE:
			printf("Give day:\n");
			scanf("%s", min);
			break;
		case FILTER_BY_MANUFACTURER:
			printf("Give manufacturer:\n");
			scanf("%s", min);
			break;
		default:
			return;
	}

	Vector* vect = controller_ExecFilterObjects(this->ctrl, filter, min, max);

	int i = 0;
	int len = vector_getLen(vect);
	// Print what we filtered:
	for (i = 0; i < len; ++i)
	{
		StoreObject* currObj = (StoreObject*)(vector_getAt(vect, i));
		if (currObj)
			printf("%d %s %s %s %d %s %d\n", 	storeObject_GetID(currObj),
												product_GetType(storeObject_GetProduct(currObj)),
												product_GetModel(storeObject_GetProduct(currObj)),
												product_GetManufacturer(storeObject_GetProduct(currObj)),
												storeObject_GetPrice(currObj), storeObject_GetDate(currObj),
												storeObject_GetQuantity(currObj));
	}
	printf("\n");

	vector_destroy(vect);

	free(vect);
	free(min);
	free(max);
}

void ui_execCMDSortObjects(UI* this, SortType sort, int asc)
{
	Vector* vect = controller_ExecSortObjects(this->ctrl, sort, asc);

	int i = 0;
	int len = vector_getLen(vect);
	// Print what we filtered:
	for (i = 0; i < len; ++i)
	{
		StoreObject* currObj = (StoreObject*)(vector_getAt(vect, i));
		if (currObj)
			printf("%d %s %s %s %d %s %d\n", 	storeObject_GetID(currObj),
												product_GetType(storeObject_GetProduct(currObj)),
												product_GetModel(storeObject_GetProduct(currObj)),
												product_GetManufacturer(storeObject_GetProduct(currObj)),
												storeObject_GetPrice(currObj), storeObject_GetDate(currObj),
												storeObject_GetQuantity(currObj));
	}
	printf("\n");

	vector_destroy(vect);
	free(vect);
}

////////////////////////////////

void ui__execCMD(UI* this, int cmd)
{
	int asc = 0;
	switch(cmd)
	{
		case CMD_SHOW_OBJECTS:
			ui_execCMDShowAllObjects(this);
			break;
		case CMD_ADD_OBJECT:
			ui_execCMDAddObject(this);
			break;
		case CMD_DELETE_OBJECT:
			ui_execCMDDeleteObject(this);
			break;
		case CMD_UPDATE_OBJECT:
			ui_execCMDUpdateObject(this);
			break;
		case CMD_FILTER_OBJECTS_PRICE:
			ui_execCMDFilterObjects(this, FILTER_BY_PRICE);
			break;
		case CMD_FILTER_OBJECTS_MANUFACTURER:
			ui_execCMDFilterObjects(this, FILTER_BY_MANUFACTURER);
			break;
		case CMD_FILTER_OBJECTS_DATE:
			ui_execCMDFilterObjects(this, FILTER_BY_DATE);
			break;
		case CMD_SORT_OBJECTS_PRICE_ASC:
			asc = 1;
			/* no break */
		case CMD_SORT_OBJECTS_PRICE_DSC:
			ui_execCMDSortObjects(this, SORT_BY_PRICE, asc);
			break;
		case CMD_SORT_OBJECTS_DATE_ASC:
			asc = 1;
			/* no break */
		case CMD_SORT_OBJECTS_DATE_DSC:
			ui_execCMDSortObjects(this, SORT_BY_DATE, asc);
			break;
	}
}

void ui_init(UI* this, Controller* ctrl)
{
	this->ctrl =ctrl;
}

void ui_destroy(UI* this)
{
	; // Blank?
}

void ui_run(UI* this)
{
	while(1)
	{
		ui__printMenu();
		int cmd = ui__getCMD();
		switch (cmd)
		{
			case EXIT_CMD:
				return;
			case ERROR_CMD:
				printf("Command is invalid!\n");
				break;
			default:
				ui__execCMD(this, cmd);
		}
	}
}

void runUI()
{
	printf("Hello!");
}
