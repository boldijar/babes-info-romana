#include <stdio.h>
/*
 * calculator.c
 *
 *  Created on: 27 Feb 2012
 *      Author: ilazar
 */

int totalM = 0;
int totalN = 1;

/*
 * Return the greatest common divisor of two natural numbers.
 * Pre: a, b >= 0, a*a + b*b != 0
 */
int gcd(int a, int b) {
	if (a == 0) {
		return b;
	} else if (b == 0) {
		return a;
	} else {
		while (a != b) {
			if (a > b) {
				a = a - b;
			} else {
				b = b - a;
			}
		}
		return a;
	}
}

/*
 * Return the absolute value of an integer.
 */
int abs(int x) {
	if (x > 0) {
		return x;
	} else {
		return -x;
	}
}

/*
 * Add (m, n) to (toM, toN) - operation on rational numbers
 * Pre: toN != 0 and n != 0
 */
void add(int* toM, int* toN, int m, int n) {
	*toM = *toM * n + *toN * m;
	*toN = *toN * n;
	int gcdTo = gcd(abs(*toM), abs(*toN));
	*toM = *toM / gcdTo;
	*toN = *toN / gcdTo;
}

int main() {
	int m;
	int n;
	while (1) {
		printf("Enter m, then n to add\n");
		scanf("%d", &m);
		scanf("%d", &n);
		add(&totalM, &totalN, m, n);
		printf("Total: %d/%d\n", totalM, totalN);
	}
	return 0;
}
