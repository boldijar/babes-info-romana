#include "vector.h"
#include <malloc.h>
#include <assert.h>

#define DEFAULT_MAX_SIZE 3

/* Initializes the vector.
 * Post: size == 0
 */
void init(Vector* vector) {
	assert(vector != NULL);
	vector->size = 0;
	vector->elements = malloc(sizeof(Element) * DEFAULT_MAX_SIZE);
	vector->capacity = DEFAULT_MAX_SIZE;
}

/* Destroys the vector. */
void destroy(Vector* vector) {
	free(vector->elements);
}

/*
 * Returns the size of a vector.
 */
int size(Vector* vector) {
	assert(vector != NULL);
	return vector->size;
}

/*
 * Inserts a new element at the end.
 */
void push_back(Vector* vector, Element element) {
	assert(vector != NULL);
	if (vector->size == vector->capacity) {
		int new_capacity = vector->capacity + vector->capacity / 2;
		Element* new_elements = malloc(sizeof(Element) * new_capacity);
		int i;
		for (i = 0; i < vector->capacity; i++) {
			new_elements[i] = vector->elements[i];
		}
		free(vector->elements);
		vector->elements = new_elements;
		vector->capacity = new_capacity;
	}
	vector->elements[vector->size] = element;
	vector->size++;
}

/*
 * Returns the element at a given index.
 * Pre: 0 <= index < size
 */
Element get_elem(Vector* vector, int index) {
	assert(0 <= index && index < vector->capacity);
	return vector->elements[index];
}

