#include "dictionar.h"
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include<iostream.h>

 typedef struct lsi
 { char expl[100];
   lsi *urm;
  }nod;
 lsi *TD[499];

 int precizie=500;

 int f(char*val) //functia de dispersie
 { int i,x;
   int suma=0;

   for (i=0;i< strlen(val);i++)
	{
		suma=suma+(*(val+i));
	}
   x=suma%precizie;
   return x;
 }

 void constr_dict (int &n)
 { int i,o;
   nod *q,*p;
   char x[20];
   char def[100];

   printf("Dati nr de elem din dictionar ");
   scanf("%d",&n);
   for (i=0;i<n;i++)
   { 	printf("Dati elementul definit %d ",i);
	scanf("%s",&x);
	printf("Definitia lui %s: ",x);
	//scanf("%s",def);
	cin.get(def,100);
        cin.get();
	o=f(x);
	q=new nod;
	strcpy(q->expl,def);
	q->urm=NULL;
	if (TD[o]==NULL)
	   TD[o]=q;
	else
	{      p=TD[o];
	       while (p->urm!=NULL)
		 p=p->urm;
	       p->urm=q;
	       q->urm=NULL;
	}

    }
 clrscr();
 printf("Efectuat!\n");
 delay(1500);
 clrscr();
 }

 void adaug_dict()
 { int i,o;
   char x[20];
   nod *q,*p;
   char def[100];

   for (i=0;i<1;i++)
   { 	printf("Dati elementul definit: ");
	scanf("%s",&x);
	printf("Definitia lui %s: ",x);
	//scanf("%s",def);
	cin.get(def,100);
	cin.get();
	o=f(x);
	q=new nod;
	strcpy(q->expl,def);
	q->urm=NULL;
	if (TD[o]==NULL)
	   TD[o]=q;
	else
	{      p=TD[o];
	       while (p->urm!=NULL)
		 p=p->urm;
	       p->urm=q;
	       q->urm=NULL;
	}

    }
  clrscr();
  printf("Efectuat!");
  delay(1500);
  clrscr();
 }

 void caut_dict (char *x)
 {  lsi *q;
    int i,verif;
    verif=0;
    printf("Dati cuvantul cautat ");
    scanf("%s",x);
    for (i=0;i<precizie;i++)

	if (f(x)==i && TD[i]!=NULL)
	{ verif=1;
	  q=TD[i];
	  while(q!=NULL)
	  {	printf("\n def este: %s ",q->expl);
		q=q->urm;
	  }

	}

    if (verif==0) printf("Cuvantul nu se regaseste in dictionar");
   printf("\nApasati o tasta");
   getch();
   clrscr();
 }

