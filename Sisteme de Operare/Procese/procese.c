//Pentru fiecare argument din linia de comanda parintele lanseaza cate un proces (tip A).
//Procesul incearca sa execute, intr-un nou proces (tip B) 
//folosind una din functiile exec, argumentul primit.
//In caz de insucces, procesul de tip A, ii trimite parintelui 
//printr-un canal pipe codul de eroare (valoarea errno) generat de functia exec.
//In caz de succes, procesele de tip A, dupa ce executia procesului fiu (tip B) 
//s-a incheiat ii trasmite parintelui codul 0, folosind acelasi canal pipe.
//Parintele va afisa pentru fiecare argument daca executia a reusit sau nu. 
//Doar pentru argumentele la care executia a esuat se afiseaza codul de eroare.

#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
int main(int argc, char* argv[]){
        int i,a,b,c2p[2],ok,status;
        pipe(c2p);
        for(i=1;i<argc;i++){
                a=fork();
                if(a==-1)
                        perror("fork error");
                else    ///proces de tip A
                if(a==0){
                        b=fork();       //proces de tip B
                        if(b==-1)perror("fork error");
                        if(b==0){
                                execl(argv[i],(char*)NULL);
                                write(c2p[1],&errno,sizeof(int));
                                exit(-1);
                        }
                        else{
                                waitpid(b,&status,0);
                                if (WEXITSTATUS(status)!=255) {
                                ok=0;
                                write(c2p[1],&ok,sizeof(int));
                                }exit(0);

                        }
                }
                else{
                        wait(0);
                        read(c2p[0],&ok,sizeof(int));
                        if(ok==0){
                                printf("%s ok<----------\n",argv[i]);
                        }
                        else{
                                printf("%s bad-<---------\n",argv[i]);
                        }
                }
        }
        return 0;
}

