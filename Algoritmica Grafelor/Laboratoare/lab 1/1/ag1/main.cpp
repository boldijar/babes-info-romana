#include <iostream>
#include <fstream>
using namespace std;
int in[10][20],n,m,alfa[10],beta[10];

void citire()
{
ifstream f("incidenta.in");
f>>n>>m;
int i,j;
for(i=1;i<=n;i++)
  for(j=1;j<=m;j++)f>>in[i][j];
f.close();
}

void transf()
{
int k=0;
int vf,i,j;
for(vf=1;vf<=n;vf++)
  {alfa[vf]=k+1;
      for(i=1;i<=m;i++)
        if(in[vf][i]==1)
          for(j=1;j<=n;j++)
            if(in[j][i]==-1)
              {
                  k++;beta[k]=j;
              }
  }
}
void afissir(int a[20],int n)
{
int i;
for(i=1;i<=n;i++)
   cout<<a[i]<<" ";
cout<<endl;
}

void afissucc(int vf)
{int i,c=0;
    cout<<"succesorii nodului "<<vf<<" sunt:";
    for(i=alfa[vf];i<alfa[vf+1];i++)
      {cout<<beta[i]<<" ";c++;}
      if(c==0)cout<<"Nu exista";
    cout<<endl;
}
int main()
{int i;
 citire();
 transf();
 cout<<"alfa:";afissir(alfa,n);
 cout<<"beta:";afissir(beta,m);
 cout<<"Lista succesorilor este:";
 for(i=1;i<=n;i++)
    afissucc(i);

    return 0;
}
