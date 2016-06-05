#include <stdio.h>
#include "vector.h"
#include <assert.h>

void test_vector_of_integers() {
	int ints[] = {0, 1, 2, 3, 4, 5, 6, 7};
	int ints_count = sizeof(ints)/sizeof(int);
	Vector vector;
	int i;
	for(i = 0; i < ints_count; i++) {
		vector.push_back(&ints[i]);
	}
	for(i = 0; i < vector.size(); i++) {
		int element = *(int *)vector.get_elem(i);
		assert(ints[i] == element);
	}
}

int main() {
	test_vector_of_integers();
	return 0;
}
