#include "Operations.h"
#include <iostream>
using namespace std;
#include <conio.h>

void read(vector &v){
	int n,x,k,j,f;
	int i;
	cout<<"Give the number of elements:";
	cin>>n;
	cout<<"Give the elements:"<<endl;
	v.a=new int[100];
    cout<<"Number"<<1<<"=";
		cin>>x;
		i=1;
		v.a[i]=x;
		v.n=1;
	for(i=2;i<=n;i++)
	{
		cout<<"Number"<<i<<"=";
		cin>>x;
		k=1;
		while ((k<=v.n)&&(v.a[k]<x))
			k=k+1;
		insertion(v, x, k);
	}
}
void print(vector v){
	for(int i=1; i<=v.n;i++)
		cout<<v.a[i]<<" ";
	    cout<<"\n";
}
void release(vector & v){
	delete[] v.a;
	v.n=0;
}
void pos_seq_cons(vector v, int &p1,int &p2){
	/*
	Returneaza pozitia de inceput(p1) si de final(p2) pt. prima secv. de elemente consecutive, de pe pozitii consecutive.
	*/
	while ((p1<v.n)&&(v.a[p1]!=(v.a[p1+1]-1))) p1++; //cautam inceputul secventei
	p2=p1+1;
	while ((p2<v.n)&&(v.a[p2]==(v.a[p2+1]-1))) p2++; //extinde secventa pana la final
	if (p2>v.n){
		p1=0;
		p2=-1; //conventie daca nu exista nici un sir crescator
	}
}
void del_seq(vector & v, int p1, int p2){
	if (p1<p2){
	int l=p2-p1;
	for (int i=p2+1; i<=v.n;i++) v.a[i-l-1]=v.a[i];
	v.n=v.n-l-1;
	}

}
void del_all_seq(vector &v){
	int p1,p2;
	p1=1;
	pos_seq_cons(v,p1,p2);
	while (p1<p2){
	    del_seq(v, p1, p2);
		pos_seq_cons(v,p1,p2);
	}
}
void merge(vector v1, vector v2, vector &v3){
	v3.a=new int[5000];
	for (int i=1; i<=v1.n;i++) 
		v3.a[i]=v1.a[i];
	for (int i=1; i<=v2.n;i++) 
		v3.a[v1.n+i]=v2.a[i];
	v3.n=v1.n+v2.n;

}
void insertion(vector &v, int x, int p){
	int f;
	for (f=v.n+1;f>=p+1;f--)
		v.a[f]=v.a[f-1];
	v.a[p]=x;
	v.n=v.n+1;
}
void sort(vector &v){
	int i,aux;
	bool gata;
	do{
	   gata=true;
	   for(i=1;i<=v.n-1;i++)
		   if (v.a[i]>v.a[i+1]){
			   gata=false;
			   aux=v.a[i];
			   v.a[i]=v.a[i+1];
			   v.a[i+1]=aux;
		   }
	}
	while (gata!=true);
}
int getElem(vector v, int i){
	return v.a[i];
}
int getSize(vector v){
	return v.n;
}
int compare (int x,int y){
	if (x>y)
		return 1;
	else 
		if (x=y)
			return -1;
	else 
		return 0;
}