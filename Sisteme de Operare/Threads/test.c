// program C, care primeste ca si argumente nume de fisiere, pt fiecare argument se lanseaza cate un thread care
// a) determinam numarul de cuvinte din fisier si calculez media numarului de cuvinte.


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
#define N 100
int medie;

void* func(void* ar){
        FILE* pt;
        char cmd[N], result[N];
        strcpy(cmd, "cat ");
        strcat(cmd, ar);
        strcat(cmd, "| wc -w");

        pt = popen(cmd, "r");
        fgets(result, 20, pt);
        pclose(pt);

        puts(ar);
        printf(" numar cuvinte: %s \n",  result);

        int j;
        j = atoi(result);
		
        pthread_mutex_lock(&m);
			medie = medie + j;
        pthread_mutex_unlock(&m);
        return NULL;
}

int main(int argc, char* argv[]){
        pthread_t t[20];
        int i;
        for( i=1; i<argc; i++){
                pthread_create( &t[i], NULL, func, argv[i]);
                pthread_join( t[i], NULL);
        }
        medie = medie / (argc-1);
        printf("Medie= %d\n", medie);
        return 0;
}
                     