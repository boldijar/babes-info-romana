//Implementati un program care scrie intr-o variabila globala un numar aleator de la 0 la 9 
//si apoi creeaza 10 thread-uri. Fiecare thread va verifica variabila globala si daca valoarea 
//e chiar numarul de ordine al thread-ului (transmis din main la creare), 
//va genera un nou numar de la 0 la 9 (diferit de numarul de ordine propriu) si il va scrie in variabila globala.
//Thread-urile se termina dupa ce variabila globala a fost schimabta de 20 de ori.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

int valoare = 5;
int contor = 0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


void * func(void * val) {
	
	
	//printf("%d \n  \n",v);
		int v;
	v = *(int*)val;
	for(;;) {
	
		pthread_mutex_lock(&mtx);
		if (contor == 20) exit(1);
		if(v == valoare){
			
			printf("%d \n",valoare);
			printf("%d \n \n",contor);
			
				contor++;
			
			valoare = rand()%9+0;
			
			//break;
			
			}
		pthread_mutex_unlock(&mtx);
		
		
}

return NULL;
	
}
int main(int argc,char * argv[]) {
	int i;
	valoare = rand()%9+0;
	pthread_t threads[10];
	pthread_mutex_init(&mtx,NULL);
	for(i=0;i<=9;++i) {
		//int *p = (int*)malloc(sizeof(int));
		int * a = (int*)malloc(sizeof(int));
		*a = i;
		pthread_create(&threads[i],NULL,func,a);
	}

	for(i=0;i<10;++i) {
		pthread_join(threads[i],NULL);
	}
	printf("%d \n \n",contor);
	pthread_mutex_destroy(&mtx);
return 0;
}
