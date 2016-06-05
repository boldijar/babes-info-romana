//Programul principal citeste de la intrarea standard numere cat timp 
//utilizatorul introduce numere pozitive.
//Pentru fiecare numar se creeaza un proces nou care il dubleaza 
//si creeaza un nou proces care determina numarul fibonaci care are numarul de ordine 
//numarul primit, eg. pentru un n=8 numarul fibonacii este: 21. 
//Numarul astfel obtinut este trimis ca raspuns printr-un canal pipe procesului parinte.
//Pentru a determina numarul fibonacii de pe o anumita pozitie procesul 
//foloseste popen pentru a lansa un script shell care sa determine acest numar.


#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int nr,p, pfp[2],a;
	char cmd[1000];
	char buffer[BUFSIZ];
	printf("Dati numarul: ");
	scanf("%d", &nr);
	while( nr > 0)
	{
		pipe(pfp);
		if( pipe(pfp) < 0)
		{
			perror("Nu s-a putut crea pipe!");
			exit(0);
		}
		
		p=fork();
		wait(0);
		
		if(p < 0)
		{
			perror("Nu s-a putut crea procesul!");
			exit(0);
		}

		if(p == 0)
		{
			nr=2*nr;
			snprintf(cmd, sizeof(cmd), "./fibo.sh %d", nr);
			FILE *fp = popen(cmd, "r");
			fgets(buffer, BUFSIZ, fp);
			a=atoi(buffer);
			pclose(fp);
			write(pfp[1], &a, sizeof(int));
			break;
		}

		wait(0);
		read(pfp[0], &a, sizeof(int));
		close(pfp[0]);
		close(pfp[1]);
		printf("Al  %d-lea numar din sirul lui fibonacci este %d. \n", 2*nr, a);
		printf("Dati numarul: ");
		scanf("%d", &nr);
	}
	return 0;
}

			
