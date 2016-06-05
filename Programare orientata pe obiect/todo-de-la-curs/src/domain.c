/*
 * domain.c
 *
 *  Created on: Mar 4, 2015
 *      Author: ilazar
 */

#include "domain.h"
#include <string.h>
#include <malloc.h>

void init_task(Task* task, const char* text) {
	task->text = malloc(sizeof(char) * (strlen(text) + 1));
	strcpy(task->text, text);
	task->status = ACTIVE;
}

void destroy_task(Task* task) {
	free(task->text);
}

