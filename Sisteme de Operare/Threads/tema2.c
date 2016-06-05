//Sa se implementeze un program care creaza doua thread-uri 
//care isi tiparesc ID-ul (pthread_self) de 10 ori si se termina. 
//Faceti in asa fel incat sa asigurati alternanta ID-urilor tiparite (A, B, A, B, ...).

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *funct();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int main(){
        int rc1, rc2;
        pthread_t thread1, thread2;

        if( (rc1 = pthread_create(&thread1, NULL, &funct, NULL)) )
        {
                printf("Eroare la creare thread: %d \n", rc1);
        }
        if( (rc2 = pthread_create(&thread2, NULL, &funct, NULL)) )
        {
                printf("Eroare la creare thread: %d \n", rc2);
        }

        pthread_join (thread1, NULL);
        pthread_join (thread2, NULL);

        return 0;
}

void *funct(){
        int i;
        //pthread_mutex_lock(&mutex1);
        for( i=0; i<10; i++)
        {
                //pthread_mutex_lock(&mutex1);
                printf("Thread ID: %li \n", pthread_self() );
                //pthread_mutex_unlock(&mutex1);
                sleep(1);
        }
        //pthread_mutex_unlock(&mutex1);
}