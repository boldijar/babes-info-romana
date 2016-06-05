#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arce.in");

struct arc{
int x,y,c;
}u[20],U[20];

int n,k=0,m,viz[20]={0};

void citire()
{
f>>n;
m=n*(n-1)/2;
int i;
for(i=1;i<=m;i++)
f>>u[i].x>>u[i].y>>u[i].c;
}

void ordonare(arc u[20],int n)
{
int i,j;
arc aux;
for(i=1;i<n;i++)
  for(j=i+1;j<=n;j++)
     if(u[i].c>u[j].c)
        {
        aux=u[i];
        u[i]=u[j];
        u[j]=aux;
        }
}

int afisare(arc U[20],int n)
{
int i,s=0;
for(i=1;i<=n;i++)
{
    cout<<"("<<U[i].x<<","<<U[i].y<<") ";
    s=s+U[i].c;
}
 cout<<endl;
 return s;
}

void ciclu()
{
int i,j;
k++;
U[k]=u[1];
viz[U[k].x]++;
viz[U[k].y]++;
j=2;
while(k<n)
{
   if(viz[u[j].x]+viz[u[j].y]==1||k==n-1&&viz[u[j].x]==1&&viz[u[j].y]==1)
     {
     k++;
     U[k]=u[j];
     viz[U[k].x]++;
     viz[U[k].y]++;
    }
    j++;
}
}

int main()
{
    citire();
    ordonare(u,m);
    cout<<"Din muchiile intitiale ordonate:"<<endl;
    afisare(u,m);
    ciclu();
    cout<<"Se aleg muchiile:"<<endl;
    int p=afisare(U,n);
    cout<<"Valoare ciclu: "<<p<<endl;
    return 0;

}
