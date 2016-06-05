#include <stdio.h>
#include <pthread.h>

#define N 10

int cine = 0;

pthread_mutex_t mtx;

void* zero(void* p) {
    int n=0;
    while(n < N) {
        pthread_mutex_lock(&mtx);
        if(cine == 0) {
            printf("zero\n");
            cine = 1;
            n++;
        }
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}

void* unu(void* p) {
    int n=0;
    while(n < N) {
        pthread_mutex_lock(&mtx);
        if(cine == 1) {
            printf("\n");
            cine = 0;
            n++;
        }
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}

int main() {
    pthread_t z, u;

    pthread_mutex_init(&mtx, NULL);

    pthread_create(&z, NULL, zero, NULL);
    pthread_create(&u, NULL, unu, NULL);

    pthread_join(z, NULL);
    pthread_join(u, NULL);

    pthread_mutex_destroy(&mtx);

    return 0;
}





