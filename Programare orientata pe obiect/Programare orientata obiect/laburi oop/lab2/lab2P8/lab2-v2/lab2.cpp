# include "lab2.h"
# include <iostream>
using namespace std;
# include <conio.h>

int search(int x, set a){
	int i,gasit;
	gasit=0;
	for(i=1;i<=a.n;i++)
		if (x==a.v[i])
			gasit=1;
	return gasit;
}
void add(int x,set & a){
	a.n=a.n+1;
	a.v[a.n]=x;
}
void read(set & a){
	cout<<"Give the number of elements:";
	cin>>a.n;
	cout<<"Give the elements:"<<endl;
	for(int i=1;i<=a.n;i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>a.v[i];
		
		// printf("a[%d]=",i);
		// scanf("%d",& a[i]);
	}
}
void print(set a){
	for(int i=1;i<=a.n;i++)
		cout<<a.v[i]<<" ";
	getch();
}