//			PROBLEMA COMIS-VOIAJORULUI
//    Se da un numar oareacre de puncte care trebuie vizitate de un comis
// voiajor.Acesta trebuie sa se intoarca la locul de pornire si sa parcurga
// o distanta minima. Sa se determine o ordina de vizitare a oraselor circulara
// asttfel incat distanta parcursa sa fie minima, cunoscandu-se distanta dintre
// oricare doua orase.
//      Consideram graful G=(X,U),unde X=multimea oraselor |X|=n
//      G graf complet notat cu Kn
//      Pentru orice muchie u din U, l(u)=distanta dintre extremitatile lui u
//      Trebuie determinat un ciclu hamiltoniam de valoare minima
//       		DESCRIEREA ALGORITMULUI
// Se porneste dintr-un varf oarecare. La fiecare pas se alege muchia de
// valoare cea mai mica care uneste ultimul varf ales cu unul din varfurile
// nealese. Repet acest procedeu pana ce se aleg toate varfurile grafului.

#include <stdio.h>
#include <conio.h>
 

int n;                  //numarul de orase
int a[20][20];          //matricea distantelor dintre orase

void citire(int a[20][20],int &n)
{
 FILE *f;
 f=fopen("in.txt","rt");
 while(!feof(f))
    { fscanf(f,"%d",&n);
      for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	   fscanf(f,"%d",&a[i][j]);
     }
 fclose(f);
}

void afisare(int a[20][20],int n)
{
 FILE *f;
 f=fopen("out.txt","wt");
 for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
	   fprintf(f,"%d",a[i,j]);
     
 fclose(f);
}

void main()
{ clrscr();
  citire(a,n);
  afisare(a,n);
  getch();
}

