#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){

        int p2c[2], c2p[2], n;
        int p, ok=0;
        printf("n=");
        scanf("%d", &n);

        pipe(p2c);
        pipe(c2p);

        write(p2c[1], &n, sizeof(int));
        printf("parinte da la copil: %d\n", n);
        if( (p=fork()) < 0){
                printf("Nu s-a putut face fork");
                exit(1);
        }
        else if(p==0){
                if(n%2==0){
                        while( n%2 == 0 ){
                                read(p2c[0], &n, sizeof(int));
                                n=n/2;
                                printf("copil da la parinte: %d\n", n);
                                write(c2p[1], &n, sizeof(int));
                        }
                }
                else{
                        ok=1;
                        //printf("Done copil\n");
                        exit(0);
                }
        }
		if(ok==1){
                printf("Done\n");
                close(c2p[0]);
                close(c2p[1]);
                close(p2c[0]);
                close(p2c[1]);

                return 0;
        }
        else{
                while(n%3==0){
                        read(c2p[0], &n, sizeof(int));
                        n=n/3;
                        printf("parinte da la copil: %d\n", n);
                        write(p2c[1], &n, sizeof(int));

        }
        sleep(1);
        close(c2p[0]);
        close(c2p[1]);
        close(p2c[0]);
        close(p2c[1]);
        printf("done\n");
        }
        return 0;
}
                                              