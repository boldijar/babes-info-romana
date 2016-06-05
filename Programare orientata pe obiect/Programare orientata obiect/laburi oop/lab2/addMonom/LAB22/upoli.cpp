#include "upoli.h"
#include <iostream>
using namespace std;

void init(poli &p)
{
	for(int i=0;i<=30;i++) p.coef[i]=0;
}


void readm(monom &m)
{
	float c,d;
	cout<<"Give the coefficent of the monom:"; 
	cin>>c;
	cout<<"Give the degree of the monom:";
	cin>>d;
	m.c=c;
	m.d=d;
}

void readp(poli &p)
{
	cout<<"Give the degree:";
	cin>>p.gr;
	init(p);
	for(int i=p.gr;i>=0;i--)
		cin>>p.coef[i];
}

void addmonom(poli p,monom m,poli &s)
{
	init(s);
	s=p;
	s.coef[m.d]=s.coef[m.d]+m.c;
	if (m.d>s.gr)
			s.gr=m.d;
	while ( (s.coef[s.gr]==0) && (s.gr>=0) )
		s.gr-=1;	
}

void printp(poli p)
{
 cout<<p.coef[p.gr]<<"x^"<<p.gr;
 for(int i=p.gr-1;i>0;i--)
		if (p.coef[i]!=0)
			if (p.coef[i]>0) cout<<"+"<<p.coef[i]<<"x^"<<i;
			else cout<<p.coef[i]<<"x^"<<i;
if (p.coef[0]!=0)
	if (p.coef[0]>0)
			cout<<"+"<<p.coef[0];
	else	cout<<p.coef[0];
}

