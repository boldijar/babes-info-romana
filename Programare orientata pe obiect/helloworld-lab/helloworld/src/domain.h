/*
 * domain.h
 *
 *  Created on: Feb 26, 2015
 *      Author: ilazar
 */

#ifndef DOMAIN_H_
#define DOMAIN_H_

enum status {
	ACTIVE, DONE //0, 1
};

typedef enum status Status;

struct task {
	char* text;
	Status status;//int
};

typedef struct task Task;

#endif /* DOMAIN_H_ */
