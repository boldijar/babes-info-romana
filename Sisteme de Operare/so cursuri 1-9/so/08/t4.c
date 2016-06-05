#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 10

void* f(void* arg) {
    int i;
    int k = (int)arg;

    free(arg);

    for(i=0; i<N; i++) {
        printf("%d\n", k);
    }
    return NULL;
}

int main() {
    int i;
    pthread_t t[10];

    for(i=0; i<10; i++) {
        pthread_create(&t[i], NULL, f, (void*)i);
    }

    for(i=0; i<N; i++) {
        printf("M\n");
    }

    for(i=0; i<10; i++) {
        pthread_join(t[i], NULL);
    }
    return 0;
}
