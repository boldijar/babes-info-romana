/*
 * service.h
 *
 *  Created on: Feb 26, 2015
 *      Author: ilazar
 */

#ifndef SERVICE_H_
#define SERVICE_H_
#include "domain.h"

typedef struct vector {
	Task* items[100]; //? Task
	int count;
} Vector;

Task* create_task(const char* text);
Vector* get_task_list();

#endif /* SERVICE_H_ */
