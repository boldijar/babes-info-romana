#include <stdio.h>
#include "rational.h"
#include "calculator.h"

int main() {
	Calculator c;
	reset(&c);
	int m;
	int n;
	while (1) {
		printf("Enter m, then n to add\n");
		scanf("%d", &m);
		scanf("%d", &n);
		Rational r;
		init(&r, m, n);
		add_number(&c, r);
		Rational total = get_total(&c);
		printf("Total: %d/%d\n", total.m, total.n);
	}
	return 0;
}
