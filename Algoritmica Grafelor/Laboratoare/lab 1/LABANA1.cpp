/* Sa se faca conversia de la o reprezentare matriciala de adiacenta
     la una matriciala de incidenta a unui graf */
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
typedef int mat[20][20];

void afisare(mat a, int n, int m)
{  int i,j;
   for(i=1;i<=n;i++)
  { cout<<endl;
    for(j=1;j<=m;j++)
      cout<<a[i][j]<<"   ";
      cout<<'\n';
  }

}

void init(mat a, int n, int m)
{  int i,j;
   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      a[i][j]=0;
}
int ret1(int i,int n,mat a)
{ int k;
      for (k=1;k<=n;k++)
       if (a[k][i]==1) return k;
}
int ret_1(int i,int n,mat a)
{ int k;
   for(k=1;k<=n;k++)
    if (a[k][i]==-1) return k;
}

void main()
 {   int i,j,m=0,n,k,l,c,d;
     mat a,b;
  cout<<"Introdu nr. de varfuri:";
  cin>>n;
  cout<<"Introdu perechile de varfuri, intre care exista arce; (0,0)=end"<<endl;
  do
   {
  cin>>i;  cin>>j;
  if ((i!=0) && (j!=0))
    {  m++;
      a[i][m]=1;
      a[j][m]=-1;
    }
   }
  while ((i!=0) && (j!=0));
  for (k=1;k<=n;k++)
  for (l=1;l<=m;l++)
    if ((a[k][l]!=1)&&(a[k][l]!=-1))
      a[k][l]=0;
  cout<<"matricea de incidenta este\n";
  cout<<"\n";
  afisare(a,n,m);
  init(b,n,n);
  for (k=1;k<=n;k++)
   for (l=1;l<=m;l++)
   { c=ret1(l,n,a);
     d=ret_1(l,n,a);
     b[c][d]=1;
    }
  cout<<"\n";
  cout<<"matricea de adiacenta este\n";
  afisare(b,n,n);
    getch();
  }

