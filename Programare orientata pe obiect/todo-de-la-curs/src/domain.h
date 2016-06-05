/*
 * domain.h
 *
 *  Created on: Mar 4, 2015
 *      Author: ilazar
 */

#ifndef DOMAIN_H_
#define DOMAIN_H_

enum task_status {
	ACTIVE, DONE
};

struct task {
	char* text;
	enum task_status status;
};
typedef struct task Task;

void init_task(Task* task, const char* text);
void destroy_task(Task* task);

#endif /* DOMAIN_H_ */
