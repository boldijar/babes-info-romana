
/*
Programul principal citeste comenzi introduse de utilizator pana acesta introduce comanda stop.
Pentru fiecare comanda citita programul principal creeaza un proces (A) care la randul lui mai face un proces (B) care 
lanseaza folosind una din functiile exec comanda. Procesul A redirecteaza iesirea standard a procesului B (folosind dup2)
intr-un pipe din care va afisa pe ecran tot ce citeste.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main () {
	char cmd[20];
	int pipefd[2];
	pipe(pipefd);

	while (1) {
		scanf("%s", &cmd);
		if (strcmp(cmd, "stop") == 0) {
			printf("bye\n");
			exit(0);
		} 

		int p = fork();
		if ( p == 0 ) {
			printf(" copil A\n" );
			exit(0);

		}
		if ( p > 0 ) {
			printf (" tatic A\n");
			//proces A.
			int k = fork();
			if ( k == 0 ) {
				printf (" copil B\n");
				printf("eu ar trebui sa citesc din pipe \n");
				dup2(pipefd[0], 0);
				close(pipefd[1]);
				execlp("grep", "grep", "", NULL);
				exit(0);
			}
			if ( k > 0 ) {
				// proces B
				printf(" tatic B, eu o sa fac exec \n");
				dup2(pipefd[1], 1);
				close(pipefd[0]);
				execlp(cmd, cmd, NULL, NULL);
			}
		}
	}
	return 0;
}