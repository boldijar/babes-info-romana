/*
        Sa se scrie un program care are 2 variabile globale, nrpare, nrimpare. Programul
creeaza 2 thread-uri si fiecare dintre ele genereaza nr aleatoare intre 10 si 50.
Daca nr generat este par se incrementeaza nrpare, daca e impar se incrementeaza nrimpare.
Threadurile isi termina executia cand nrpar * nrimpar divizibil cu 3 si nrpar*nrimpar>50.
Programul principal asteapta terminarea threadurilor si afiseaza cele 2 variabile
*/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int nr_pare, nr_impare;

void* f(){
        int r;
        while(1){
                pthread_mutex_lock(&m);
                        if( (nr_pare * nr_impare)%3 == 0  &&  nr_pare*nr_impare > 50)
                                break;
                pthread_mutex_unlock(&m);

                r=rand()%40+10;
                //printf("%d\n",r);
                if(r%2 == 0){
                        pthread_mutex_lock(&m);
                        nr_pare++;
                        pthread_mutex_unlock(&m);
                }
                else{
                        pthread_mutex_lock(&m);
                        nr_impare++;
                        pthread_mutex_unlock(&m);
                }
        }
        pthread_mutex_unlock(&m);
		return NULL;
}

int main(){
        pthread_t t1, t2;

        pthread_create(&t1, NULL, f, NULL);
        pthread_create(&t2, NULL, f, NULL);

        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        printf("%d, %d", nr_pare, nr_impare);
        return 0;
}

