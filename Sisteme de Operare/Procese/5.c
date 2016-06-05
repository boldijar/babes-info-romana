/*
	Pentru fiecare argument din linia de comanda sa creeze un proces (A) care la randul lui mai face un proces (B).
Procesul nepot (B) determina numarul de vocale din argumentul asociat, folosind un script shell lansat cu popen.
Nepotul (procesul B) ii transmite parintelui lui (procesul A) numarul astfel obtinul print-un canal pipe propriu.
Comunicarea dinte programul principal si procesele lui (procesele de tip A) se face print-un singur pipe.
Programul principal colecteaza toate rezultatele si le afiseaza pe ecran.
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 100
 
int main(int argc, char const *argv[])
{
	FILE *fp;
	char result[N], cmd[N], msg[N];
	int c2p[2], n2c[2];
	int i;
	
	for (i = 1; i < argc; ++i) {
		pipe(c2p);
		pipe(n2c);
		// child code
		if (0 == fork()) {
			// nephew code
			if (0 == fork()) {
				sprintf(cmd, "echo %s | grep -o [AEIOUaeiou] | wc -l", argv[i]);
				fp = popen(cmd, "r");
				fgets(result, N, fp);
				pclose(fp);
				write(n2c[1], result, 10);
				exit(0);
			}
			read(n2c[0], msg, 10);
			close(n2c[0]);
			close(n2c[1]);
			wait(0);
			write(c2p[1], msg, 10);
			exit(0);
		}
		// parent code
		read(c2p[0], result, 10);
		close(c2p[0]);
		close(c2p[1]);
		wait(0);
		printf("%s\n", argv[i]);
		printf("%s\n", result);
	}
	return 0;
}