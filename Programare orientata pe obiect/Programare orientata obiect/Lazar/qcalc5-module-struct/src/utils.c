#include "utils.h"

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

int abs(int x) {
	if (x > 0) {
		return x;
	} else {
		return -x;
	}
}
