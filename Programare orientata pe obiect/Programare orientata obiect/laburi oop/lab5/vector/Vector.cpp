#include "Vector.h"

struct _vect
{
	int n;
	Telem *e;
	cpyfct cpy;
	cmpfct cmp;
	delfct del;
}

void Create(vect &v, cpyfct spy, cmpfct cmp,delfct del)
{
	v=new _vect;
	v->n=0;
	v->e=new Telem[20];
	v->cmp=cmp;
	v->cpy=cpy;
	v->del=del;
}

int Belongs(vect v, Telem a)
{
	for(int i=0;i<v->n;i++)
		if(v->cmp(v->e[i],a)==0)
			return 1;
    return 0;
}

void Add(vect &v, Telem a)
{
	v->n++;
	v->cpy(v->e[v->n],a);
}

int Card(vect v)
{ 
	return v->n;
}

Telem getElem(vect v, int a)
{
	if(a<=v->n)
	    return v->e[a];
	else
		return 0;
}

int getPoz(vect v,Telem a)
{
	for(int i=0;i<v->n;i++)
		if(v->cmp(v->e[i],a)==0)
			return i;
    return 0;
}

int Empty(vect v)
{
	return v->n==0;
}

void Dealloc(vect &v)
{
	for (int i=0;i<v->n;i++)
		v->del(v->e[i]);
    delete[] v->e;
}
