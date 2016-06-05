#include "calculator.h"
#include "rational.h"

void reset(Calculator* c) {
	init(&c->total, 0, 1);
}
void add_number(Calculator* c, Rational r) {
	add(&c->total, r);
}

Rational get_total(Calculator* c) {
	return c->total;
}


