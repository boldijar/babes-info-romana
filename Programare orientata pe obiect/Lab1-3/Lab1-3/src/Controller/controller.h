/*
 * controller.h
 *
 *  Created on: Mar 10, 2015
 *      Author: Nexflame
 */

#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

#include "../Repository/repository.h"

typedef enum enum_FilterType
{
	FILTER_BY_PRICE			= 1,
	FILTER_BY_DATE,
	FILTER_BY_MANUFACTURER,

	MAX_FILTERS
}FilterType;

typedef enum enum_SortType
{
	SORT_BY_PRICE,
	SORT_BY_DATE,

	MAX_PRICES
}SortType;

typedef struct struct_Controller
{
	Repository* repo;
}Controller;

void controller_init(Controller* this, Repository* repo);
void controller_destroy(Controller* this);

// Controller functionalities
/*
 * Get a Vector of all StoreObjects in controller or NULL otherwise
 */
Vector* controller_ExecShowAllObjects(Controller* this);
void controller_ExecAddObject(Controller* this, StoreObject* obj);
void controller_ExecDeleteObject(Controller* this, int ID);
void controller_ExecUpdateObject(Controller* this, int ID, StoreObject* newObj);
/*
 * Param:
 * if FilterType is:
 * 						FILTER_BY_PRICE 		- 	min = min value of price in range
 * 													max = max value of price in range
 * 						FILTER_BY_DATE 			- 	min = max = Date you want to filter
 * 						FILTER_BY_MANUFACTURER 	- 	min = max = Manufacturer you want to filter
 * 	Return a Vector with elements
 * 	If no elements found - vector is empty - YOU SHOULD DESTROY IT
 */
Vector* controller_ExecFilterObjects(Controller* this, FilterType filter, char* min, char* max);
Vector* controller_ExecSortObjects(Controller* this, SortType sort, int asc);
#endif /* CONTROLLER_CONTROLLER_H_ */
