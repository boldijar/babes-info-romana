/*
 * utils.c
 *
 *  Created on: Mar 4, 2015
 *      Author: ilazar
 */

#include "utils.h"
#include <malloc.h>

void init_vector(Vector* v) {
	v->n = 0;
	v->capacity = 4;
	v->elem = malloc(sizeof(E) * v->capacity); // owner is Vector
}

void push_back(Vector* v, E e) {
	if (v->n >= v->capacity) {
		int new_capacity = 2*v->capacity;
		v->elem = malloc(sizeof(E) * v->capacity); // owner is Vector
		E* new_space = malloc(sizeof(E) * new_capacity);
		int i;
		for(i = 0; i < v->n; i++) {
			new_space[i] = v->elem[i];
		}
		v->capacity = new_capacity;
		free(v->elem);
		v->elem = new_space;
	}
	v->elem[v->n] = e;
	v->n++;
}

int size(const Vector* v) {
	return v->n;
}

E get_elem(const Vector* v, int i) {
	return v->elem[i];
}

void destroy_vector(Vector* v) {
	free(v->elem);
}
