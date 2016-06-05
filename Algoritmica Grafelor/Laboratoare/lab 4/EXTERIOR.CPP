//program care determina toate multimile exterior stabile ale unui graf oarecare
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream.h>
#include <stdio.h>
const N=20;
typedef int sir[N];
typedef int matrice[N][N];
matrice a,g;
int n;
sir X,T;

void citire_graf(int& n,matrice a)
{
   ifstream f;
   f.open("extern.txt");
   if(f.fail()){cerr<<"Eroare la citire";getch();exit(0);}
   f>>n;
   for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) f>>a[i][j];
   f.close();
}

void afisare_matrice(int n,int m,matrice a)
{
  for(int i=1;i<=n;i++)
  {
	for(int j=1;j<=m;j++)  printf("%3d",a[i][j]);
	cout<<endl;
  }
  cout<<endl;
}

void afisare_sir(sir s)
{
 for(int i=1;i<=s[0];i++) cout<<s[i]<<" ";
 cout<<endl;
}

void constructie_graf_bipartit(int n,matrice a,matrice g)
{
 for(int j=1;j<=n;j++)
  for(int i=1;i<=n;i++)
	if((i==j)||(a[i][j])) g[j][i]=1;
 for(int i=0;i<=n;i++) X[i]=i;
}

void procedura_de_reducere(int n,matrice g,sir X,sir T)
{
  int Kod;
  do
   {
	Kod=0;
	for(int j=1;j<=n;j++)
	  {
		int k=0,poz=0;
		for(int i=1;i<=n;i++)
		 if(g[i][j]!=0) {k++;poz=i;}
		if(k==1)
		{
		   T[++T[0]]=poz;
		   X[poz]=0;
		   for(int p=1;p<=n;p++)
			if(g[poz][p]!=0)
			{
			  g[poz][p]=0;
			  for(int r=1;r<=n;r++)
			   if(g[r][p]!=0) g[r][p]=0;
			}
		   Kod=1;
		}
	  }
	}while(Kod);
}

int e_nul(int n,sir x)//intoarce 1 daca x este nul si 0 in caz contrar
{
 for(int i=0;i<=n;i++) if(x[i]) return 0;
 return 1;
}

void copiere_matrice(int n,matrice g,matrice g1)//g1:=g
{
  for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	  g1[i][j]=g[i][j];
}

void copiere_sir(sir x,sir x1)//x1:=x
{
 for(int i=0;i<N;i++) x1[i]=x[i];
}

void determinare_multimi_exterior_stabile(int n,matrice g1,sir X1,sir T1)
{
  matrice g;sir X,T;
  copiere_matrice(n,g1,g);
  copiere_sir(X1,X);
  copiere_sir(T1,T);
  if(e_nul(n,X)) {afisare_sir(T);getch();exit(0);}
   else
	for(int i=1;i<=n;i++)
	  if(X[i]!=0)
	  {
		cout<<i<<endl;
		T[++T[0]]=i;
		X[i]=0;
		for(int j=1;j<=n;j++)
		  if(g[i][j]!=0)
			for(int l=1;l<=n;l++)
			  if(g[l][j]!=0) g[l][j]=0;
		for(int p=1;p<=n;p++)//se elimina acele varfuri care nu au nici
		 {//un succesor
		   int t=0;
		   for(int k=1;k<=n;k++) if(g[p][k])t++;
		   if(!t) X[p]=0;
		 }
		cout<<"Matricea g in pasul c)\n";
		getch();
		afisare_matrice(n,n,g);
		procedura_de_reducere(n,g,X,T);
		cout<<"Matricea g dupa reducere in pasul b)\n";
		getch();
		afisare_matrice(n,n,g);
		determinare_multimi_exterior_stabile(n,g,X,T);
	 }
}
void main()
{
  clrscr();
  citire_graf(n,a);
  afisare_matrice(n,n,a);
  constructie_graf_bipartit(n,a,g);
  afisare_matrice(n,n,g);
  determinare_multimi_exterior_stabile(n,g,X,T);
  getch();
}