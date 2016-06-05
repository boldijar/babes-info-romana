/*
 * ui.c
 *
 *  Created on: Feb 26, 2015
 *      Author: ilazar
 */
#include "ui.h"
#include "service.h"
#include <stdio.h>
#include <string.h>

void add_task(const char* cmd);
void list_tasks();

void manage_tasks() {
	char cmd[80]; //?
	while (1) {
		printf(">");
		gets(cmd); //? crash if more than 80 chars
		if (strstr(cmd, "add") == cmd) {
			add_task(cmd);
		} else if (strstr(cmd, "list") == cmd) {
			list_tasks();
		} else if (strstr(cmd, "exit") == cmd) {
			break;
		} else {
			printf("Unknown command\n");
		}
	}
}

void add_task(const char* cmd) {
	if (strlen(cmd) <= strlen("add") + 1) { //? validation
		printf("Text empty\n");
	} else {
		Task* task = create_task(cmd + 4); //? validation + I/O files errors
		printf("Task(%s, %d) created\n", task->text, task->status);
	}

}

void list_tasks() {
	Vector* task_list = get_task_list();
	int i = 0;
	for(i = 0; i < task_list->count; i++) {
		printf("Task(%s, %d)\n", task_list->items[i]->text, task_list->items[i]->status);
	}
}
