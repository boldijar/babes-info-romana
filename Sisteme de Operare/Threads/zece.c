// scrieti un program c care primeste ca si argument oricate numere naturale. pprogramul lanseaza un thread pentru
//fiecare numar care determina daca numarul este par sau prim. la sfarsit afisam suma totala a numerelor pare si
//suma totala a numerelor prime.


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_TH 5

int sum_prim=0;
int sum_par=0;


pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void *PrintM (void *argv)
{
  int nr= (int) argv;
  
  pthread_mutex_lock(&mutex);
  
  if (nr % 2 == 0 ) {
          printf("Nr %d e par!\n",nr);
          sum_par=sum_par+nr;
  }
  else{
          int i;
          int ok=1;
          for(i=2;i<nr-1;++i)
            if (nr % i ==0 ){
                  ok=0;
                  break;
                }
          if (ok) {
                      printf("Nr %d e prim!\n",nr);
                      sum_prim=sum_prim+nr;
          } 
      }
  pthread_mutex_unlock(&mutex);
  
  pthread_exit (NULL);
}

int main (int argc, char *argv[])
{
  pthread_t threads[NUM_TH];
  int rc,n;
  long t;
  for (t = 1; t < argc; t++)
    {
      n=atoi(argv[t]);
      
      rc = pthread_create (&threads[t], NULL, PrintM, (void *) n);
      if (rc)
	{
	  printf ("ERROR; codul de retur pentru pthread_create() este %d\n",
		  rc);
	  exit (-1);
	}
    }
    
    for(t=1;t<argc;t++)
      pthread_join(threads[t],NULL);
    
    printf("Suma argumentelor pare: %d\n",sum_par);
    printf("SUma argumentelor prime: %d\n",sum_prim);
  pthread_exit (NULL);
}
