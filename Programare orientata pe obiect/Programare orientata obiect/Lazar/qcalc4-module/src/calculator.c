#include <stdio.h>
#include "rational.h"
/*
 * calculator.c
 *
 *  Created on: 27 Feb 2012
 *      Author: ilazar
 */

int totalM = 0;
int totalN = 1;

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
