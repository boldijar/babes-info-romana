// Dandu-se reprezentarea unui graf sub forma listei predecesorilor se cere sa
//  se construiasca lista succesorilor.

#include <stdio.h>
#include <conio.h>

int a1[20],a2[20],b1[20],b2[20];
int n,m;

void citire(int a[20], int &n, int b[20], int &m)
{ printf("\n Citirea listei predecesorilor ");
  printf("\n Introduceti numarul de varfuri:");
  printf("\n n=");scanf("%d",&n);
  printf("\n Introduceti vectorul a1");
  printf("\n   a1[i]=indicele din b1 unde incep predecesorii varfului i");
  for(int i=1;i<=n;i++)
    { printf("\n a1[%d]=",i);scanf("%d",&a[i]); }
  printf("\n Introduceti numarul de predecesori:");
  printf("\n m=");scanf("%d",&m);
  printf("\n Introduceti vectorul b1 format din predecesori");
  for(int j=1;j<=m;j++)
    { printf("\n b1[%d]=",j);scanf("%d",&b[j]); }
}

void afisare(int a[20], int n, int b[20], int m)
{ printf("\n Afisarea vectorului a2 : ");
  for(int i=1;i<=n;i++)    printf("%d ",a[i]);
  printf("\n Afisarea vectorului b2 (succesorilor): ");
  for(int j=1;j<=m;j++)    printf("%d ",b[j]);
}

void trecere(int a1[20],int n, int b1[20], int m, int a2[20], int b2[20])
{ int x=0,l;
  a2[1]=1;
  for(int i=1;i<=n;i++)
    { l=0;
      for(int j=1;j<=m;j++)
       if (b1[j]==i)
	 for(int k=1;k<=n;k++)
	   { if ( (k==1) && (j==a1[1])) {x++;b2[x]=k;l++;}
	     if ( (a1[k]<j) && (j<a1[k+1]) )    { x++;b2[x]=k;l++;  }
	     if ( (a1[k]<j) && (j==a1[k+1]) )    { x++;b2[x]=k+1;l++;  }
	     if ( (k==n) && (j>a1[n]) ) {x++;b2[x]=n;l++;}

	    }
      if (i!=6) a2[i+1]=a2[i]+l;
     }
}

void main()
{ clrscr();
  citire(a1,n,b1,m);
  trecere(a1,n,b1,m,a2,b2);
  afisare(a2,n,b2,m);
  getch();
}