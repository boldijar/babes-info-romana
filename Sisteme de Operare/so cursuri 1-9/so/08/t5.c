#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define T 1000

int contor = 0;
pthread_mutex_t mtx;

void* f(void* arg) {
    int i;

    for(i=0; i<1000000; i++) {
        pthread_mutex_lock(&mtx);
        contor++;
        pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t t[T];

    pthread_mutex_init(&mtx, NULL);

    for(i=0; i<T; i++) {
        pthread_create(&t[i], NULL, f, NULL);
    }

    for(i=0; i<T; i++) {
        pthread_join(t[i], NULL);
    }

    pthread_mutex_destroy(&mtx);

    printf("%d\n", contor);
    return 0;
}
