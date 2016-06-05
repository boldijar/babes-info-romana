#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 2 threaduri si 2 variabile globale (numerepare si numereimpare). Threadurile genereaza numere la intamplare,
//  incrementand variabila in concordanta cu paritatea numarului generat pana fiecare thread genereaza peste 
//  100 de numere.

#define COUNT 100

int odd = 0, even = 0;

void* parity(void* p) {
	int c = 0, n;
	srand(time(NULL));
	while (c < COUNT) {
		n = rand() % 10;
		c++;
		if (n % 2 == 0) {
			even++;
			printf("Number '%d' is even. Even count is: '%d'. Total count is: '%d'\n", n, even, c);
		}
		else {
			odd++;
			printf("Number '%d' is odd. Odd count is: '%d'. Total count is: '%d'\n", n, odd, c);
		}
	}
	return NULL;
}

int main() {
	pthread_t	t[2];

	pthread_create(&t[0], NULL, parity, NULL);
	pthread_create(&t[1], NULL, parity, NULL);

	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);

	printf("Total even: %d\n", even);
	printf("Total odd: %d\n", odd);

	return 0;
}