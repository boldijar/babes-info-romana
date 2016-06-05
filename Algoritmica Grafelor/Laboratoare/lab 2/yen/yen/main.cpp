#include <iostream>

#include <fstream>

using namespace std;

#define inf 10000000

int v[100][100],n , la[100],l[100][100];




void citire()

{int i,j;

    ifstream f("graf.in");

    f>>n;

    for (i=1;i<=n;i++)

        for (j=1;j<=n;j++)

            f>>v[i][j];







}




void tipar(int la[])

{

int i;

for(i=1;i<=n;i++)

    cout<<la[i]<<" ";

    cout<<endl;

}




void ford(int vf)

{int modif,i,j;

for (i=1;i<=n;i++)

    if(i==vf)

        la[i]=0;

    else la[i]=v[vf][i];

    tipar(la);

    do{modif=0;

     for(j=1;j<=n;j++)

        for(i=1;i<=n;i++)

            if (v[i][j]!=inf &&  la[i]!=inf)

                if(la[j]>la[i]+v[i][j])

                    {la[j]=la[i]+v[i][j];

                    modif=1;}

    tipar(la);

    }while(modif==1);




}







void yen(int vf)

{int i,j,modif;

for (i=1;i<=n;i++)

    if(i==vf)

        la[i]=0;

    else la[i]=v[vf][i];

    tipar(la);

 do{modif=0;

     for(j=1;j<=n;j++)

        for(i=1;i<=n;i++)

            if(v[i][j]!=inf &&  la[i]!=inf)

                if(la[j]>la[i]+v[i][j])

                    {la[j]=la[i]+v[i][j];

                    modif=1;

                    }

   for(j=n;j>=1;j--)

      for(i=1;i<=n;i++)

            if(v[i][j]!=inf &&  la[i]!=inf)

                if(la[j]>la[i]+v[i][j])

                    {la[j]=la[i]+v[i][j];

                    modif=1;

                    }

    }while(modif);

    tipar(la);







}







void drum(int p,int q)

{int d[100],k,i,j;

   //se porneste invers, se adauga varful final

   if(la[q]!=inf)

   {







    k=1;

    d[k]=q;




    while(d[k]!=p)

      {

          //drumul de la p la d[k](initial q) trece prin varful intermediar j

          //daca costul minim al drumului p->d[k] este egal cu costul minim al drumului

          //p->j la care se adauga arcul (j,d[k])

          for(j=1;j<=n;j++)

                if(v[j][d[k]]!=inf && v[j][d[k]]!=0) //sa existe arcul(j,d[k])

                    if(la[j]+v[j][d[k]]==la[d[k]])

          {

              k++;

              d[k]=j;

          }

      }

      for(i=k;i>=1;i--)cout<<d[i]<<" ";}

      else cout<<"nu exista drum de la "<<p<<" la "<<q;

}




int main()

{

   citire();

   int p,q;

   cin>>p>>q;

   cout<<endl<<"yen:"<<endl;

   yen(p);

   cout<<"drum"<<endl;

   drum(p,q);

   return 0;

}
