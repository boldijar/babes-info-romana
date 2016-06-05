/*for each command line argument the main process will create a new process (A). This process (A) will create a new process (B).
The nephew process (B) will establish the number of vowels that are part of the argument's name, using a shell script launched with popen. 
The B process will send to his parent (A) the number received using a private pipe channel.
The communication between the main process and his subprocesses (of type A) will be maintained using a shared pipe channel.
The main process will collect all the results and will print them.*/
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char* argv[]){

	int m2a[2],a2m[2],a2b[2],b2a[2];
	int p;
	pipe(m2a);
	pipe(a2m);
	pipe(a2b);
	pipe(b2a);
	int info;
	int total=0;
	int trei = 2;
	int i=1;
	for( ; i < argc ; ++i){
		///create process A
		p = fork();
		if(p==0){
			///create the process B
			if(fork() == 0){
				write(b2a[1],&trei,sizeof(int));
				
				//FILE *pp;
				char* comm = mallloc(100);
				strcpy(comm,"echo ");
				strcat(comm,argv[i]);
				strcat(comm," | sed 's/[^aeiou]//' | wc -m");
				printf("%s\n",comm); 
				/*
				pp = popen("echo "+argv[i]+" | sed 's/[^aeiou]//' | wc -m","r");					      if ( pp != NULL){
						char line[1];
						line = fgets(line,sizeof(char)*1,pp);
						printf("%c\n",line);
					    }*/
				 exit(0);        ///Stop the process B

			}		
			else{
				///here we are in the parrent of B( meaning A)
				read(b2a[0],&info,sizeof(int));
				write(a2m[1],&info,sizeof(int));
				wait(NULL);
				exit(0);	///stop the process A
			}	
				
		}
		else{
		///here we are in the main process
		read(a2m[0],&info,sizeof(int));
		total+=info;
		wait(NULL);		
		}

	}
	printf("Write the total %d\n",total);
	

return 0;
}
