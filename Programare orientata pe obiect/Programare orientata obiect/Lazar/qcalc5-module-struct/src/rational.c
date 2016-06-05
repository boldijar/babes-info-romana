/*
 * q.c
 *
 *  Created on: 27 Feb 2012
 *      Author: ilazar
 */
#include "rational.h"
#include "utils.h"

void init(Rational* r, int m, int n) {
	r->m = m;
	r->n = n;
}

void add(Rational* a, Rational b) {
	a->m = a->m * b.n + a->n * b.m;
	a->n = a->n * b.n;
	int gcdTo = gcd(abs(a->m), abs(a->n));
	a->m = a->m / gcdTo;
	a->n = a->n / gcdTo;
}
