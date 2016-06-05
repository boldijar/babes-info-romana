//numai pentru un graf CONEX
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <fstream.h>
#include <stdlib.h>
#include <values.h>
const N=25;
int a[N][N],n;

void citire_matrice_adiacenta(int& n,int a[N][N])
{
  ifstream f;
  f.open("drum.txt");
  if (f.fail())
   {
	cerr<<"Nu exista fisierul dat";
	getch();exit(0);
   }
  f>>n;
  for (int i=1;i<=n;i++)
   for (int j=1;j<=n;j++)
	f>>a[i][j];
  f.close();
}

void tiparire_matrice(int n,int m,int a[N][N])
{
 for (int i=1;i<=n;i++)
  {
   for (int j=1;j<=m;j++) printf("%3d",a[i][j]);
   cout<<endl;
  }
}

void determina_succesori_si_diferenta(int n,int a[N][N],int S[N],int R[N],int succ[N],int dif[N])
{
  int w=0,i,j;
  for(i=0;i<N;i++) succ[i]=dif[i]=0;
  for(i=1;i<=S[0];i++)
	for(j=1;j<=n;j++)
	  if (a[S[i]][j]==1)
		 {
		  int b=0;
		  for(int p=1;p<=w;p++) if(succ[p]==j) b++;
		  if (!b) succ[++w]=j;
		 }
 succ[0]=w;
  w=0;
  for(i=1;i<=n;i++)
  {
   int b=0;
   for(j=1;j<=R[0];j++)	if(i==R[j]) b++;
   if (b==0) dif[++w]=i;
  }
 dif[0]=w;
}

//determina excentricitatea varfului p
int determinare_excentricitate(int n,int a[N][N],int p)
{
 int lambda[N],R[N],S[N],i,j;
 for(i=0;i<N;i++) lambda[i]=R[i]=S[i]=0;
 for(i=1;i<=n;i++) lambda[i]=MAXINT;
 lambda[p]=0;
 int k=0;
 R[1]=p;R[0]=1;
 S[1]=p;S[0]=1;
 int succ[N],dif[N];
 do
 {
   determina_succesori_si_diferenta(n,a,S,R,succ,dif);
   for(i=1;i<=succ[0];i++)
   {
	 int b=0;
	 for(j=1;j<=dif[0];j++) if(succ[i]==dif[j]) b++;
	 if(b!=0) lambda[succ[i]]=k+1;
   }
   for(i=0;i<N;i++) S[i]=succ[i];
   int aux[N];for(i=0;i<N;i++) aux[i]=R[i];
   for(i=1;i<=S[0];i++)
   {
	int b=0;
	for(j=1;j<=R[0];j++)
	  if(S[i]==R[j]) b++;
	if(!b) aux[++aux[0]]=S[i];
   }
   for(i=0;i<N;i++) R[i]=aux[i];
   k++;
 }while(R[0]!=n);
 for(i=1;i<=n;i++) cout<<lambda[i]<<" ";
 cout<<endl;
 int max=lambda[1];
 for(i=2;i<=n;i++)
   if(max<lambda[i]) max=lambda[i];
 return max;
}

int diametru(int n,int a[N][N])
{
  int e[N];
  for(int i=1;i<=n;i++) e[i]=determinare_excentricitate(n,a,i);
  int max=e[1];
  for(i=2;i<=n;i++)
   if(max<e[i]) max=e[i];
  return max;
}

void main()
{
 clrscr();
 citire_matrice_adiacenta(n,a);
 tiparire_matrice(n,n,a);
 int d=diametru(n,a);
 if(d<MAXINT) cout<<"Diametrul grafului este:"<<d;
		 else cout<<"Diametrul grafului este infinit";
 getch();
}