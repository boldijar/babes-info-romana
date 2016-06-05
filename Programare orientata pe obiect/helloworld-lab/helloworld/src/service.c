/*
 * service.c
 *
 *  Created on: Feb 26, 2015
 *      Author: ilazar
 */
#include "domain.h"
#include "service.h"
#include <string.h>
#include <malloc.h>

Vector* task_list = 0;

void ensure_task_list() {
	if (task_list == 0) {
		task_list = malloc(sizeof(Vector));
		task_list->count = 0;
	}
}

Task* create_task(const char* text) {
	Task* task = malloc(sizeof(Task)); //? owner
	task->text = malloc(sizeof(char) * (strlen(text) + 1)); //? owner
	strcpy(task->text, text);
	task->status = ACTIVE;
	ensure_task_list();
	task_list->items[task_list->count++] = task;
	return task;
}

Vector* get_task_list() {
	ensure_task_list();
	return task_list;
}
