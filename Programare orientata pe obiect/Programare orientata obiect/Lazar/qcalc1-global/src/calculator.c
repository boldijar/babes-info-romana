#include <stdio.h>

int totalM = 0;
int totalN = 1;

int main() {
	int m;
	int n;
	while (1) {
		printf("Enter m, then n to add\n");
		scanf("%d", &m);
		scanf("%d", &n);
		totalM = totalM * n + m * totalN;
		totalN = totalN * n;
		printf("Total: %d/%d\n", totalM, totalN);
	}
	return 0;
}
