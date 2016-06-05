#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<iostream.h>
#include<stdio.h>
#include "dictionar.h"

 void menu(int i)
 { int k;
   char *y;
   if(i>4 || i<1)
    { clrscr();
      printf("Introduceti un numar valid ");
      delay(1500);
      clrscr();
    }
   else
   switch(i)
   { case 1:constr_dict(k);break;
     case 2:adaug_dict();break;
     case 3:caut_dict(y);break;
     case 4:exit(1);
   }

 }

 void main ()
 { clrscr();
   int l;
   do {
	printf("\n-----MENIU-----\n");
	printf("1 - Construire dictionar - \n");
	printf("2 - Adauga o definitie in dictionar - \n");
	printf("3 - Cautare cuvant dorit - \n");
	printf("4 - Iesire program - \n");
	printf("Dati optiunea : "); scanf("%d",&l);
	menu(l);
       } while(l!=4);
  }
