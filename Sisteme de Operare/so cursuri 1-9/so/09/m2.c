#include <stdio.h>
#include <pthread.h>

#define N 10

pthread_mutex_t mtxz;
pthread_mutex_t mtxu;

void* zero(void* p) {
    int n=0;
    while(n < N) {
        pthread_mutex_lock(&mtxz);
        printf("zero\n");
        n++;
        pthread_mutex_unlock(&mtxu);
    }
    return NULL;
}

void* unu(void* p) {
    int n=0;
    while(n < N) {
        pthread_mutex_lock(&mtxu);
        printf("\n");
        n++;
        pthread_mutex_unlock(&mtxz);
    }
    return NULL;
}

int main() {
    pthread_t z, u;

    pthread_mutex_init(&mtxz, NULL);
    pthread_mutex_init(&mtxu, NULL);

    pthread_mutex_lock(&mtxu);

    pthread_create(&z, NULL, zero, NULL);
    pthread_create(&u, NULL, unu, NULL);

    pthread_join(z, NULL);
    pthread_join(u, NULL);

    pthread_mutex_destroy(&mtxz);
    pthread_mutex_destroy(&mtxu);

    return 0;
}





