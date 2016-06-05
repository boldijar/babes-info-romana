/*
 * utils.h
 *
 *  Created on: Mar 4, 2015
 *      Author: ilazar
 */

#ifndef UTILS_H_
#define UTILS_H_

typedef void* E;

typedef struct vector {
	int n;
	E* elem;
	int capacity;
} Vector;

void init_vector(Vector* v);
void push_back(Vector* v, E e);
int size(const Vector* v);
E get_elem(const Vector* v, int i);
void destroy_vector(Vector* v);

#endif /* UTILS_H_ */
