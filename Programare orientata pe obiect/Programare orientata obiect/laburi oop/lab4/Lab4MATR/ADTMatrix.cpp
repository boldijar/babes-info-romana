#include "ADTMatrix.h"
#include <iostream>
using namespace std;
#include <conio.h>

void read(_Matrix &a){
	int i,j,l,c,v;
	a.x=new int*[21];
	for(int i=1;i<=20;i++)
		a.x[i]=new int[21];
	for(i=1;i<=a.n;i++)
		for(j=1;j<=a.n;j++)
			a.x[i][j]=0;
	cin>>l>>c>>v;
	while ((l!=0)||(c!=0)||(v!=0)){
		a.x[l][c]=v;
		cin>>l>>c>>v;
	}
}
void print(_Matrix a){
	int i,j;
	for(i=1;i<=a.n;i++){
		for (j=1;j<=a.n;j++)
			cout<<a.x[i][j]<<" ";
		cout<<endl;
	}
}
void dispose(_Matrix &a){
	for (int i=0;i<20;i++){
		delete [] a.x[i];
		a.x[i]=NULL;
	}
	delete [] a.x;
	a.x=NULL;
}

void Mimul(_Matrix a, _Matrix b,_Matrix & c){
  int i,j,k,s;
  c.n=a.n;
  c.x=new int*[21];
	for(int i=1;i<=20;i++)
		c.x[i]=new int[21]; 
    for (i=1;i<=a.n;i++)
      for (j=1;j<=b.n;j++)
	  {
		  s=0;
		  for (k=1;k<=a.n;k++)
              s=s+(a.x[i][k]*b.x[k][j]);
		  c.x[i][j]=s;
	  }
}
void d(_Matrix a, int j, _Matrix & r){//r=minorul elementului 1,j 
	int i,k;
	r.x=new int*[21];
	for(int i=1;i<=20;i++)
		r.x[i]=new int[21]; 
	r.n=a.n-1;
	for (i=2; i<=a.n;i++)
		for (k=1;k<=a.n;k++)
			if(k<j) r.x[i-1][k]=a.x[i][k];
			else if(k>j) r.x[i-1][k-1]=a.x[i][k];
}
int Mdet(_Matrix a){
	int j,semn,det;
    _Matrix r;
    if (a.n==1)
      det=a.x[1][1];
    else {
		det=0;//Dezvoltam determinantul dupa prima linie
		for (j=1;j<=a.n;j++){
			d(a,j,r);//Minorul elementului de pe pozitia 1,j.
			if ((j%2)==0) semn=-1;
			else semn=1;
			det=det+(a.x[1][j]*semn*Mdet(r));
			}
	}
	return det;
}