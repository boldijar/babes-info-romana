				 //PROBLEMA ORDONANTARII
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

const N=20;
typedef int sir[N];
typedef int matrice[N][N];
sir m;
matrice d;//matricea duratelor activitatilor
int n;//numarul de activitati

void citire_matricea_duratelor_activitatilor(int& n,matrice d)
{
  sir k;
  cout<<"Dati numarul de activitati:n=";cin>>n;
  cout<<"Dati durata primei activitati:";cin>>k[1];
  for(int i=2;i<=n;i++)
   {
	 cout<<"Dati durata activitatii "<<i<<": ";cin>>k[i];
	 int n1=0;
	 cout<<"   Dati cate activitati precedente are activitatea "<<i<<": ";
	 cin>>n1;
	 for(int j=1;j<=n1;j++)
	   {
		  cout<<"         Activitatea cu nr "<<j<<" precedenta activitatii "<<i<<": ";
		  int p;cin>>p;
		  d[p][i]=k[p];
	   }
   }
  //completez coloana n+1 din matricea duratelor activitatilor
 for (i=1;i<=n;i++)
  {
	int b=0;
	for(int j=1;j<=n;j++) if(d[i][j]) b++;
	if(!b) d[i][n+1]=k[i];
  }
}

//d are n+2 linii (0..n+1) si n+2 coloane(0..n+1)
void afisare_matrice(int n,int m,matrice a)
{
 for(int i=0;i<n;i++)
  {
	for(int j=0;j<m;j++) printf("%3d",a[i][j]);
	cout<<endl;
  }
 cout<<endl;
}

void afisare_sir(int n,sir a)
{
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<endl;
}

void determinare_momente_minime(int n,sir t,matrice d)
{
  for(int i=0;i<=n+1;i++)
  {
	 int max=0;
	 for(int j=0;j<=n+1;j++)
	   if(d[j][i]!=0)
		 if(max<t[j]+d[j][i])max=t[j]+d[j][i];
	 t[i]=max;
  }
}

int verifica_daca_succ_este_inclus_in_S(sir succ,sir S) //verifica daca succ este inclus in S
{
 int b=0;
 for(int j=1;j<=succ[0];j++)
  {
	 int p=0;
	 for(int k=1;k<=S[0];k++)  if(succ[j]==S[k]) p++;
	 if(p) b++;
   }
 return(b==succ[0]);
}

void determinare_momente_maxime(int n,sir t,sir T,matrice d)
{
  sir S;for(int i=0;i<N;i++) S[i]=0;
  T[n+1]=t[n+1]; S[++S[0]]=n+1;
  do
   {
	 for(int i=0;i<=n;i++)
	 {
	  int b=0;for(int j=1;j<=S[0];j++) if(S[j]==i) b++;
	  if(!b)//daca i nu apartine lui S
		{
		   sir succ;for(int j=0;j<N;j++) succ[j]=0;
		   for(j=0;j<=n+1;j++) if(d[i][j]!=0) succ[++succ[0]]=j;//determin succesorii lui i
		   if(verifica_daca_succ_este_inclus_in_S(succ,S))
			{
			  int minim=T[succ[1]]-d[i][succ[1]];
			  for(j=2;j<=succ[0];j++)
				if (minim>T[succ[j]]-d[i][succ[j]]) minim=T[succ[j]]-d[i][succ[j]];
			  T[i]=minim;S[++S[0]]=i;
			}
		}
	 }
   }while(S[0]!=n+2);
}

void determinare_marje_de_timp(int n,sir m,matrice d)
{
  sir t,T;
  for(int i=0;i<N;i++)t[i]=T[i]=0;
  determinare_momente_minime(n,t,d);
  determinare_momente_maxime(n,t,T,d);
  afisare_sir(n+2,t);
  afisare_sir(n+2,T);
  for(i=0;i<=n+1;i++)  m[i]=T[i]-t[i];
  for(i=0;i<=n+1;i++)  cout<<"m["<<i<<"]="<<T[i]<<"-"<<t[i]<<"="<<m[i]<<endl;
}

void main()
{
  clrscr();
  citire_matricea_duratelor_activitatilor(n,d);
  afisare_matrice(n+2,n+2,d);
  determinare_marje_de_timp(n,m,d);
  cout<<"Marjele de timp:";afisare_sir(n+2,m);
  getch();
}