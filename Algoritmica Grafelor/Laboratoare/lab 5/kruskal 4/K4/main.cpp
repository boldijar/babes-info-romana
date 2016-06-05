#include <iostream>

#include <fstream>

using namespace std;
struct muchie{int x,y,c;}M[50];
int comp[50],excl[50];
int a[50][50],n,m;
ifstream f("muchii.in");

void citeste()
{
    f>>n>>m;
    for(int i=1;i<=m;i++)
      {f>>M[i].x>>M[i].y>>M[i].c;
      }

}

int conex()
{int i,j,u,v,t;
for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)a[i][j]=0;
for(i=1;i<=m;i++)
      if(excl[i]==0)
         a[M[i].x][M[i].y]=a[M[i].y][M[i].x]=M[i].c;//construim adiacenta cu muchiile neexcluse
//formam componentele conexe pe graful partial obtinut prin exluderea muchiilor
//la inceput fiecare varf apartine componentei conexe data de el
for(i=1;i<=n;i++)comp[i]=i;
for(i=1;i<n;i++)
  for(j=i+1;j<=n;j++)
    if(a[i][j]!=0)//daca doua varfuri sunt adiacente, unim componentele lor conexe
        {u=comp[i];
         v=comp[j];
      for(t=1;t<=n;t++)//toate varfurire din componenta lui j trec in componenta lui i
         if(comp[t]==v)comp[t]=u;
}
//verificam conexitatea-tot sirul comp aceeasi valoare

int conexx=1;
for(i=2;i<=n;i++)
 if(comp[1]!=comp[i])conexx=0;
 return conexx;
}

void afis()
{
int i;
for(int i=1;i<=m;i++)
 if(excl[i]==0)cout<<M[i].x<<" "<<M[i].y<<endl;
}

void Kruskal()
{
int i,j,k,min,vf;
for(k=1;k<=m;k++){excl[k]=1; //muchia k e exclusa
      if(conex()==0)//daca nu e conex fara mukia k
         {//alegem muchia minima la care se poate ajunge dintr-un varf din comp conexa a lui vf
             vf=M[k].x;
             min=vf;
             for(j=1;j<=m;j++)//parcurg muchii
                if(excl[j]!=0)//din cele eexcluse
                     if(comp[M[j].y]!=comp[M[j].x])//cele adiacente cu varfuri i
                      if (M[j].c<M[min].c)min=j;//o aleg pe cea cu cost minim-indicele ei
            excl[min]=0;//se adauga muchia minima
         }
         }
}


int main()
{
citeste();
Kruskal();
afis();
return 0;
}
