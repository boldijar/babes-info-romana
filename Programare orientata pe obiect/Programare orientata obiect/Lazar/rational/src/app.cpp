#include "rational.h"

void test_create() {
	Q a;
	Q b(2);
	Q c(1, 2);
	Q* pd = new Q(1, 3);
	//...
	delete pd;
}

Q test_return() {
	Q result(1);
	return result;
}

void test_add() {
	Q a;
	Q b(2);
	a.add(b).add(b);
	Q c = a + b;
}

int main() {
//	test_create();
//	Q a = test_return();
//	Q b = a; //and copy
	test_add();

	return 0;
}
