#include "Vector.h"
#include <iostream>
using namespace std;

struct _Vector
{
	TElem *a;
	int n;
	cpyFun cpy;
	cmpFun cmp;
	delFun del;
};

struct _Iterator
{
	Vector m;
	int crt;
};

void newVector(Vector &v, cpyFun cpy, cmpFun cmp, delFun del) {
    v=new _Vector;
	v->a=new TElem[20];
	v->n=0;
	v->cpy=cpy;
	v->cmp=cmp;
	v->del=del;
}

void add(Vector &v,TElem e) {
	v->a[v->n]=e;
	v->n++;
}

int getcard(Vector v){
	return v->n;
}

TElem getElem(Vector v, int i){
	return v->a[i];
}

void dealocate(Vector& v){
	for(int i=0;i<v->n;i++)
		v->del(v->a[i]);
	delete[] v->a;
	delete v;
}


void sort(Vector &v){
	int x,y;
	for(int i=0; i<(v->n)-1; i++)
		for (int j=i+1; j<v->n; j++){
			x=*(int*)v->a[i];
			y=*(int*)v->a[j];
			if (x>y){
				*(int*)v->a[i]=y;
				*(int*)v->a[j]=x;
			}
		}
}


void sortP(Vector &v){
	Product *t,*t2;
	TElem aux;
	for(int i=0;i<(v->n)-1;i++)
		for(int j=i+1;j<v->n;j++)
		{
			t=(Product *)v->a[i];
			t2=(Product *)v->a[j];
			if(strcmp(t->name,t2->name)==1)
			{
				aux=v->a[i];
				v->a[i]=v->a[j];
				v->a[j]=aux;
			}
		}
}

void VecProdFinal(Vector v, Vector &w){
	Product *t1,*t2;
	int i=0;
	int j=0;
	while (i<getcard(v)) { 
			t1=(Product *)v->a[i];
			t2=(Product *)v->a[i+1];
			if(strcmp(t1->name,t2->name)==0)
				i=i+1;
			else{
				if (j==0)
					w->a[j]=t1;
				else{
					j=j+1;
					w->a[j]=t1;
				}
			}
	}
}

int find(Vector v, TElem x){
	int i,nr;
	nr=0;
	for (int i=0;i<getcard(v);i++)
		if (v->cmp(getElem(v,i),x)==0)
			nr=nr+1;
	if(nr==1)
		return 0;
	else
		return 1;
}

Iterator Create(Vector m){
	Iterator it=new _Iterator;
	it->m=m;
	it->crt=0;
	return it;
}

void Next(Iterator it){
	it->crt++;
}

TElem Elem(Iterator it){
	return it->m->a[it->crt];
}

int Valid(Iterator it)
{
	return it->crt<it->m->n;
}

void DelIt(Iterator &it)
{
	delete it;
}