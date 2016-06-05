//Pentru fiecare argument din linia de comanda se vor lansa cate doua procese care vor concura in a determina:
//- lungimea liniei maxime, daca argumentul este fisier (folosind popen si wc).
//- dimensiunea in octeti daca argumentul este director (folosind popen si du).
//Fiecare proces inainte de a trimite raspunsul parintelui (prin pipe) doarme intre 1 si 5 secunde (sleep).
//Pentru comunicarea dintre fii si parinte se foloseste un singur canal pipe.
//Fiecare proces ii transmite parintelui o structura in care se afla pidul propriu, argumentul si numarul determinat.
//Parintele citeste si afiseaza doar primele n/2 raspunsuri (n fiind numarul de argumente), restul fiind ignorate.



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<string.h>
struct t{
        int pid,k;
        char c[255];
};
int main (int argc,char *argv[] )
{

       int main (int argc,char *argv[] )
{

        int i,p1,p2,d,c2p[2];
        pipe(c2p);
        for(i=1;i<=argc;i++)
        {
                p1=fork();
                if(p1==0){//copil
                        struct stat st;
                        if( stat(argv[i],&st) == 0 )
                        {
                                if( st.st_mode & S_IFDIR )
                                {
                                char v[111]="du ";
                                strcat(v,argv[i]);
                                int k;
                                FILE *f=popen(v,"r");
                                fscanf(f,"%d",&k);
                                close(f);
                                 struct t s;
                                s.k=k;
                                s.pid=getpid();
                                strcpy(s.c,argv[i]);
                                sleep(rand()%5);
                                write(c2p[1],&s,sizeof( struct t));
                                exit(0);
        //it's a director
                                }
                                 else if( st.st_mode & S_IFREG )
                                {
                                char v[111]="wc -L ";
                                strcat(v,argv[i]);
                                int k;
                                FILE *f=popen(v,"r");
                                fscanf(f,"%d",&k);
                                close(f);
                                 struct t s;
                                s.k=k;
                                s.pid=getpid();
                                strcpy(s.c,argv[i]);
                                sleep(rand()%5);

                                write(c2p[1],&s,sizeof( struct t));
                                exit(0);


         //it's a file
                                }
                        }
                exit(0);
                }
                else{//parinte
                        p2=fork();
                        if(p2==0){
         struct stat st;
                              if( stat(argv[i],&st) == 0 )
                                {
                                        if( st.st_mode & S_IFDIR )
                                        {
                                        char v[111]="du ";
                                        strcat(v,argv[i]);
                                        int k;
                                        FILE *f=popen(v,"r");
                                        fscanf(f,"%d",&k);
                                        close(f);
                                 struct t s;
                                s.k=k;
                                s.pid=getpid();
                                strcpy(s.c,argv[i]);
                                sleep(rand()%5);

                                write(c2p[1],&s,sizeof(struct t));
                              exit(0);

        //it's a directory

                                          }
                                 else if( st.st_mode & S_IFREG )
                                {
                                char v[111]="wc -L ";
                                strcat(v,argv[i]);
                                int k;
                                FILE *f=popen(v,"r");
                                fscanf(f,"%d",&k);
                                close(f);
                              struct t s;
                                s.k=k;
                                s.pid=getpid();
                                strcpy(s.c,argv[i]);
                               sleep(rand()%5);

                                write(c2p[1],&s,sizeof( struct t));
                                exit(0);

        //it's a file
                                }
                                 }
                        exit(0);
                }
                }
        }

        for(i=1;i<=argc/2;i++){
          struct t s;
                                read(c2p[0],&s,sizeof( struct t));
                                printf("%d %d %s \n",s.pid,s.k,s.c);

        }
        close(c2p);
        return 0;
}
