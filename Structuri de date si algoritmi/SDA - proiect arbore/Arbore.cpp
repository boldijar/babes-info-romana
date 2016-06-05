#include "Arbore.h"
#include <iostream>
using namespace std;

ARBORE::ARBORE()
{
	len=0;
}
int ARBORE::getLen()
{
	return len;
}
void ARBORE::Len_down()
{
	len--;
}
void ARBORE::Len_up()
{
	len++;
}
void ARBORE::setLen(int k)
{
	len=k;
}
void ARBORE::Init(int k)
{
	len++;
	nod[len].setInfo(k);
}
int ARBORE::Adauga(int k)
{
	int p,c;
	if(len==0)
	{
		Init(k);
		return 1;
	}
	p=1;
	c=1;
	while(!nod[c].vid())
	{
		if(k<=nod[c].getInfo())
		{
			p=c;
			c=nod[p].getSt();
		}
		else
		{
			p=c;
			c=nod[p].getDr();
		}
	}
	len++;
	nod[len].setInfo(k);
	nod[len].setDad(p);
	if(k<=nod[p].getInfo())
		nod[p].setSt(len);
	else
		nod[p].setDr(len);
}
int ARBORE::elimina(int i)
{
	int c,p;
	if(nod[i].getSt()!=0)
	{
		p=nod[i].getSt();
		c=nod[p].getDr();
		while(c)
		{
			p=c;
			c=nod[p].getDr();
		}
		nod[i].setInfo(nod[p].getInfo());
		if(nod[p].getSt()==0)
		{
			Zap(p);
			return 0;
		}
		else return p;
	}
	if(nod[i].getDr()!=0)
	{
		p=nod[i].getDr();
		c=nod[p].getSt();
		while(c)
		{
			p=c;
			c=nod[p].getSt();
		}
		nod[i].setInfo(nod[p].getInfo());
		if(nod[p].getDr()==0)
		{
			Zap(p);
			return 0;
		}
		else return p;
	}
	Zap(i);
	return 0;
}
void ARBORE::Eliminare(int k)
{
	int i;
	i=getInd(k);
	do{
		i=elimina(i);
	}while(i);
}
int ARBORE::Zap(int i)
{
	int aux,a,b,j,c;
	aux=nod[i].getInfo();
	nod[i].vidare();
	for(j=1;j<=len;j++)
	{
		a=nod[j].getSt();
		b=nod[j].getDr();
		c=nod[j].getDad();
		if(a==i)
			nod[j].setSt(0);
		if(a>i)
			nod[j].setSt(a-1);
		if(b==i)
			nod[j].setDr(0);
		if(b>i)
			nod[j].setDr(b-1);
		if(c>i)
			nod[j].setDad(c-1);
	}
	for(j=i;j<=len;j++)
	{
		nod[j].setInfo(nod[j+1].getInfo());
		nod[j].setDr(nod[j+1].getDr());
		nod[j].setSt(nod[j+1].getSt());
		nod[j].setDad(nod[j+1].getDad());
	}
	len--;
	return aux;
}
int ARBORE::getInd(int k)
{
	int c=1;
	while(nod[c].getInfo()!=k)
	{
		if(k<nod[c].getInfo())
			c=nod[c].getSt();
		else
			c=nod[c].getDr();
		if(nod[c].vid())
			return 0;
	}
	return c;
}

void ARBORE::Preordine(int i)
{
	int parcurs[50],j,p;
	for(j=1;j<=50;j++)
		parcurs[j]=0;
	cout<<"Preordine ";
	p=i;
	while(parcurs[i]!=3)
	{
		parcurs[p]++;
		if(parcurs[p]==1) 
			cout<<nod[p].getInfo()<<" ";
		if((parcurs[p]==1)&&(nod[p].getSt()))
			p=nod[p].getSt();
		if((parcurs[p]==2)&&(nod[p].getDr()))
			p=nod[p].getDr();
		if(parcurs[p]==3)
			p=nod[p].getDad();
	}
	cout<<endl;
}

void ARBORE::Inordine(int i)
{
	int parcurs[50],j,p;
	for(j=1;j<=50;j++)
		parcurs[j]=0;
	p=i;
	cout<<"Inordine ";
	while(parcurs[i]!=3)
	{
		parcurs[p]++;
		if(parcurs[p]==2) 
			cout<<nod[p].getInfo()<<" ";
		if((parcurs[p]==1)&&(nod[p].getSt()))
			p=nod[p].getSt();
		if((parcurs[p]==2)&&(nod[p].getDr()))
			p=nod[p].getDr();
		if(parcurs[p]==3)
			p=nod[p].getDad();
	}
	cout<<endl;
}

void ARBORE::Postordine(int i)
{
	int parcurs[50],j,p;
	for(j=1;j<=50;j++)
		parcurs[j]=0;
	p=i;
	cout<<"Postordine ";
	while(parcurs[i]!=3)
	{
		parcurs[p]++;
		if(parcurs[p]==3) 
			cout<<nod[p].getInfo()<<" ";
		if((parcurs[p]==1)&&(nod[p].getSt()))
			p=nod[p].getSt();
		if((parcurs[p]==2)&&(nod[p].getDr()))
			p=nod[p].getDr();
		if(parcurs[p]==3)
			p=nod[p].getDad();
	}
	cout<<endl;
}