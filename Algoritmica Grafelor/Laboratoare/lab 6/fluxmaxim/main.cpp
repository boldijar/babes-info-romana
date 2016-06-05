#include <iostream>

#include <fstream>




using namespace std;

ifstream f("date.in");




struct muchie{int x,y,c;}u[100];




struct etichete{int e1,e3;

char e2;}e[100];




int n,m,fi0,fi[100];




void citire()

{f>>n>>m;

for(int i=1;i<=m;i++)

   f>>u[i].x>>u[i].y>>u[i].c;

}




int min(int a,int b)

{

if(a<b)return a;

   else return b;

}

int indice_muchie(int i,int j)

{

int k;

for(k=1;k<=m;k++)

   if(u[k].x==i&&u[k].y==j)return k;

return 0;

}




int main()

{int k,l,i,j,t;

int s=1;t=3;//nodul sursa si nodul terminal

citire();

e[1].e1=1;e[1].e3=1000000;

while(1)

{

   do{k=0;

   for(i=1;i<=n;i++)

 if(e[i].e1!=0)

   for(l=1;l<=m;l++)

      {if(u[l].x==i&&e[u[l].y].e1==0&&fi[l]<u[l].c)

        {

            j=u[l].y;

            e[j].e1=i;

            e[j].e2='+';

            e[j].e3=min(e[i].e3,u[l].c-fi[l]);

            k=1;

        }

       if(u[l].y==i&&e[u[l].x].e1==0&&fi[l]<u[l].c)

        {

            j=u[l].x;

            e[j].e1=i;

            e[j].e2='-';

            e[j].e3=min(e[i].e3,fi[l]);

            k=1;

        }

      }

   }while(e[t].e1==0&&k!=0);

   if(k==0){

   cout<<fi0;

   break;

   }

   int eps=e[t].e3;

   j=t;

   while(j!=s)

   {

       i=e[j].e1;

       if(e[j].e2=='+') fi[indice_muchie(i,j)]+=eps;

          else fi[indice_muchie(j,i)]-=eps;

       j=i;

   }

   fi0+=eps;



   }




cin>>i;

    return 0;

}
