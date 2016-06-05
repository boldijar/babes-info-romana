//Pentru un n dat (5<n<=15) sa se creeze n procese astfel.
//Programul principal creeaza un proces. Acest proces creeaza la randul lui inca un proces
//si tot asa pana cand s-au creat n procese.
//Fiecare proces comunica cu fiul lui folosind cate un canal pipe.
//Parintele genereaza un numar aleator intre 1000 si 10000 si el initiaza jocul.
//Jocul incepe doar dupa ce toate procesele sau creat.
//Fiecare proces scade din valoarea primita o valoare intre 10 si 20 (generata aleator) si trimite
//numarul obtinut fiului propriu. Ultimul fiu nu trimite mai departe.
//Acesta doar dipareste numarul primit si jocul se termina.

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){

        int p2c[2], c2p[2], N, rNumber, a;

        printf("n=");
        srand(time(0)); //generator random
        scanf("%d", &N);

        pipe(p2c);  //pipe parinte -> copil
        pipe(c2p);  //pipe copil -> parinte

        rNumber = rand() % 9000 + 1000;
        write(p2c[1], &rNumber, sizeof(int));
        printf("Numarul generat este: %d\n", rNumber);
		
        int i;
        for (i=0; i<N; i++){
                if( fork() == 0 ) { //sunt in copil
                        if( i != N-1 ){ //daca nu am ajuns la ultimul proces
                                read(p2c[0], &rNumber, sizeof(int));
                                srand(time(0));
                                a = rand() % 10 + 10;
                                printf("Sunt un proces intermediar si scad cu valoarea: %d\n", a);
                                rNumber = rNumber - a;
                                write(c2p[1], &rNumber, sizeof(int));
                                exit(0);
                        }
                        else{ //ultimul proces
                                printf("Sunt ultimul proces si numarul final este: %d\n", rNumber);
                                close(p2c[0]);
                                close(p2c[1]);
                                close(c2p[0]);
                                close(c2p[1]);
                                exit(0);
                        }
                }
                else{ //sunt in parinte
                        read(c2p[0], &rNumber, sizeof(int));
                        write(p2c[1], &rNumber, sizeof(int));
                        //wait(0);
                        sleep(1);
                }
        }
        return 0;
}

