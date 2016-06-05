#include <iostream>
#include "Vec.h"
#include "Iterator.h"
#include "TElem.h"


using namespace std;

struct _Vec
	{
		int n;
		TElem * elem;
		cpyFun cpy;
		cmpFun cmp;
		delFun del;
	} ;

void create(Vec & v, cpyFun cpy, cmpFun cmp, delFun del, int c)
{
	v = new _Vec;
	v->elem = new TElem[c];
	v->n = 0;
	v->cpy = cpy;
	v->cmp = cmp;
	v->del = del;
}

bool belongs(Vec v, TElem e) {
	int i;
	for(i=0;i<card(v);i++){
		if(v->elem[i]==e) 
			return true;
	}
	return false;
}

void add(Vec& v,TElem e) {
	v->elem[v->n] = e;
	v->n++;
}
int card(Vec v)
{
	return v->n;
}

TElem getelem(Vec v, int i)
{
	return v->elem[i];
}

int constvec(Vec v)
{
	int ok=1;
	for(int i=0; i<card(v)-1; i++){
		for (int j=i; j<card(v); j++)
			if (getelem(v,i)!=getelem(v,j)) 
				ok=0;
	}
	return ok;
}
bool verify(Vec v)
{
	bool ok=true;
	for (int i=0;i<card(v)-1;i++)
		if (getelem(v,i)==getelem(v,i+1))
			ok=false;
	return ok;
}

void destroy(Vec & v)
{
	for (int i=0; i<v->n; i++)
		v->del(v->elem[i]);
	delete [] v->elem;
	delete v;
}
