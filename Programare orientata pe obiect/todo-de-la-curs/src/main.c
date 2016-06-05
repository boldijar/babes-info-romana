/**
 * main.c
 * Represents an interactive program for managing personal tasks.
 *
 * Created on: Feb 26, 2015
 *     Author: ilazar
 */

#include <stdlib.h>
#include <stdio.h>
#include "domain.h"
#include "utils.h"
#include <string.h>
#include <malloc.h>

int main() {
	char text[1000];
	Task* task = 0;
	Vector tasks;
	init_vector(&tasks);
	int i;
	while (1) {
		gets(text);
		task = malloc(sizeof(Task));
		init_task(task, text);
		push_back(&tasks, task);
		if (strlen(text) == 0) {
			break;
		}
	}
	for (i = 0; i < size(&tasks); i++) {
		task = get_elem(&tasks, i);
		printf("%s %d", task->text, task->status);
	}
	for (i = 0; i < size(&tasks); i++) {
		destroy_task(task);
		free(task);
	}
	destroy_vector(&tasks);
	return EXIT_SUCCESS;
}
