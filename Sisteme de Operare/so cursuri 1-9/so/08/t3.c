#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 10

void* f(void* arg) {
    int i;
    int k = *((int*)arg);

    free(arg);

    for(i=0; i<N; i++) {
        printf("%d\n", k);
    }
    return NULL;
}

int main() {
    int i, j, k;
    int* p;
    pthread_t t[10];

    for(i=0; i<10; i++) {
        p = (int*)malloc(sizeof(int));
        *p = i;
        pthread_create(&t[i], NULL, f, p);
    }

    for(j=0; j<N; j++) {
        printf("M\n");
    }

    for(k=0; k<10; k++) {
        pthread_join(t[k], NULL);
    }
    return 0;
}
