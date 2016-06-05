#include <stdio.h>
#include "vector.h"
#include <malloc.h>
#include <assert.h>

void test_vector_of_integers() {
	int ints[] = {0, 1, 2, 3, 4, 5, 6, 7};
	int ints_count = sizeof(ints)/sizeof(int);
	Vector vector;
	init(&vector);
	int i;
	for(i = 0; i < ints_count; i++) {
		push_back(&vector, &ints[i]);
	}
	for(i = 0; i < size(&vector); i++) {
		int element = *(int *)get_elem(&vector, i);
		assert(ints[i] == element);
	}
	destroy(&vector);
}

int main() {
	test_vector_of_integers();
	return 0;
}
