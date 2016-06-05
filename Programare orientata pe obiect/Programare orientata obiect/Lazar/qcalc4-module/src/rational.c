/*
 * q.c
 *
 *  Created on: 27 Feb 2012
 *      Author: ilazar
 */
#include "rational.h"
#include "utils.h"

void add(int* toM, int* toN, int m, int n) {
	*toM = *toM * n + *toN * m;
	*toN = *toN * n;
	int gcdTo = gcd(abs(*toM), abs(*toN));
	*toM = *toM / gcdTo;
	*toN = *toN / gcdTo;
}
