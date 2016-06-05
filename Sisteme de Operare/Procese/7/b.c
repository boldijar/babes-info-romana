/*Pentru fiecare argument, din lina de comanda, programul principal va lansa cate un proces. 
Fiecare proces determina daca argumentul asociat cu el este director, fisier sau altceva.
In functie de tipul argumentului procesul ii trimite parintelui, prin pipe, urmatoarele valori:
- daca argumentul este fisier ii trimite dimensiunea acestuia (a se vedea st_size de la stat).
- daca ii director ii transmite numarul de fisiere de tip text (folosind file) aflate in director sau in subdirectoarele lui. 
Pentru a determina numarul de fisiere text se va lansa un script, folosind popen.
- daca argumentul nu ii nici fisier nici director, se va transmite un numar generat aleator intre 5 si 15.
Fiecare proces fiu comunica cu parintele, printr-un canal pipe propriu.
Inainte de a scrie sau citii din pipe fiecare proces va afisa ce s-a scris sau ce s-a citit din pipe.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

unsigned int random_number(int min, int max) {
    time_t seconds = time(NULL);
    srand(seconds);
    unsigned int rd = rand() % (max-min+1) + min;
    return rd;
}

int main (int argc, char* argv[])
{
    int i, fd[2], pid, nr = 1, rd = -1; //fd este pipe-ul, pid este fork-ul,
    char str[20];
    for(i = 1; i < argc; i++) {
		if (pipe (fd) < 0) {
			printf ("Nu s-a putut deschide pipe");
			exit(1);
		}
		puts("INCEPUT: ");
		if ((pid = fork ()) < 0) { //eroare la fork()
			printf ("Nu s-a putut face fork");
			exit(1);
		}
		
		if (pid == 0) { // sunt in copil (fork-ul s-a efectuat cu succes)
			puts("P2");
			strcpy(str, "./s.sh "); // str=./s.sh    - comanda de executie a scriptului
			strcat(str, argv[i]);			//concatenam str cu argumentele date ca parametru => avem comanda de executie a scriptului shell cu argumentele date
			FILE* fin = popen(str, "r"); //pune in ,,fin" rezulatul executiei comenzii ce se afla in str
			char linie[1024];
			if (fgets(linie, 1024, fin) != NULL) //citeste prima linie din fisierul fin, care poate fi valoarea in bytes a unui fisier, sau fisierele text dintr-un director
			{
				nr = atoi(linie); //conversie str to int
				printf("Numarul trimis de FIU: %d\n", nr);
				write(fd[1], &nr, sizeof(int)); //scriu in pipe valoarea lui nr
			}
			else { //daca fin e null, deci daca nu e nici fisier nici director
				rd = random_number(5, 15);
				printf("Random Number: %d\n", rd);
				printf("Numarul trimis de FIU: %d\n", rd);
				write(fd[1], &rd, sizeof(int)); //scriu in pipe nu numar generat oarecare
			}
			pclose(fin); //inchidem fisierul fin
			sleep(2);
			exit(0); //ies din fiu
		}
		else {
			wait(NULL); //astept dupa fii
			puts("P1");
			//printf("Random Number Parinte: %d \n", nr);
			read (fd[0], &nr, sizeof(int)); 
			printf("Numarul primit de PARINTE este: %d \n", nr);
	   }
		close(fd[0]); //inchid capatul de citire al pipe-ului
		close(fd[1]); //inchid capatul de scriere al pipe-ului
		puts("TERMINAT");
		//sleep(1);
	}    
	return 0;
}
