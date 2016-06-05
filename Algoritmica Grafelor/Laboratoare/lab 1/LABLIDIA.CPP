/* Sa se faca conversia de la o reprezentare matriciala de adiacenta
     la una matriciala de incidenta a unui graf */
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
typedef int mat[20][20];
typedef int vector[20];

void afisare(mat a, int n, int m)
{  int i,j;
   for(i=1;i<=n;i++)
     {
       cout<<endl;
       for(j=1;j<=m;j++)
	 cout<<a[i][j]<<"  ";
      }
}

void afissir(vector x,int n)
{
   int i;
   cout<<endl;
   for(i=1;i<=n;i++)
   {
     cout<<x[i]<<"  ";
    }
 }

void init(mat a, int n, int m)
{
   int i,j;
   for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
      a[i][j]=0;
}

void initsir(vector x,int n)
{
  int i;
  for(i=1;i<=n;i++)
    x[i]=0;
}

void main()
 {
   int i,j,m=0,n;
   mat a;
   vector x,y;

    cout<<"Introdu nr. de varfuri:";
    cin>>n;
    cout<<"dati elementele matricii de adiacenta:";
    for(i=1;i<=n;i++)
     for (j=1;j<=n;j++)
       {
	 cout<<"a["<<i<<"]["<<j<<"]=";
	 cin>>a[i][j];
       }
  cout<<"matricea de adiacenta este:";
  cout<<endl;
  afisare(a,n,n);

  int nr=1;
  initsir(x,n);

  initsir(y,n*(n-1));
  for (i=1;i<=n;i++)
   {
     for (j=1;j<=n;j++)
       if( a[i][j]==1)
	{
	  y[nr++]=j;
	 }
      x[i+1]=nr;
    }
   x[1]=1;
   cout<<"sirul pozitiilor succesorilor in y"<<endl;
   afissir(x,n);
   cout<<"sirul succesorilor varfurilor"<<endl;
   afissir(y,nr);

   getch();
  }

