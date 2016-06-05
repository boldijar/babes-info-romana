#include <stdio.h>
#include "vector.h"
#include <assert.h>

void test_vector_of_integers() {
	int ints_count = 8;
	Vector<int> vector;
	int i;
	for(i = 0; i < ints_count; i++) {
		vector.push_back(i);
	}
	for(i = 0; i < vector.size(); i++) {
		assert(i == vector[i]);
		vector[i] = -i;
		assert(-i == vector[i]);
	}
}

int main() {
	test_vector_of_integers();
	return 0;
}
