#include "Bag.h"
#include <iostream>
using namespace std;
struct _Bag
{
    int card,cap;
    Telem *elem;
	int *freq;
	cpyFun cpy;
	cmpFun cmp;
	delFun del;
};
struct _Iterator
{
    _Bag *s;
    int crt;
};



void init(Bag &s,cpyFun cpy, cmpFun cmp, delFun del,int c)
{
    s=new _Bag;
    s->cap=c;
    s->card=0;
    s->elem=new Telem[c];
	s->freq=new int[c];
	s->cpy=cpy;
	s->cmp=cmp;
	s->del=del;
	for(int i=0; i<19; i++)
		s->freq[i]=0;
}
void realoc(Bag &s)
{
    Telem *temp=new Telem[2*s->cap];
	int *tempFreq=new int[2*s->cap];
    for(int i=0; i<s->card; i++)
	{
        s->cpy(temp[i],s->elem[i]);
        tempFreq[i]=s->freq[i];
	
	}
    delete[]s->elem;
	delete[]s->freq;
    s->elem=temp;
	s->freq=tempFreq;
    s->cap*=2;
}
int card(Bag s)
{
    return s->card;
}
int belongs(Bag s,Telem e)
{
    for(int i=0; i<s->card; i++)
        if(s->cmp(s->elem[i],e)==0)
            return i;
    return -1;
}
void add(Bag s,Telem e)
{
    if(belongs(s,e)!=-1)
		s->freq[belongs(s,e)]++;
	else
	{
       if(s->card==s->cap)
           realoc(s);

       s->cpy(s->elem[s->card++],e);
	   s->freq[s->card-1]=1;
    }
}

void destroy(Bag &s) 
{
	for(int i=0; i<s->card; i++)
		s->del(s->elem[i]);
    delete []s->elem;
	delete []s->freq;
    delete s;
}

void create(Bag s,Iterator &it)
{
    it=new _Iterator; 
    it->s=s;
    it->crt=0;
}

void next(Iterator &it)
{
    it->crt++;
}

Telem elem(Iterator it)
{
    return it->s->elem[it->crt]; // current element
}

int valid(Iterator it)
{
    return it->crt<it->s->card;
}

void destroy(Iterator & it)
{
	delete []it->s;
	delete it;
}

void uni(Bag m,Bag n,Bag &rez)
{  
  
	rez=m;
	for(int i=0; i<n->card; i++)
	{
		if(belongs(rez,n->elem[i])!=-1) //daca apartine
			rez->freq[belongs(rez,n->elem[i])]+=n->freq[i];
		else 
			add(rez,n->elem[i]);
	}

		
}

void inter(Bag m,Bag n,Bag &rez)
{
	for(int i=0; i<m->card; i++)
		if(belongs(n,m->elem[i])!=-1) 
			add(rez,m->elem[i]);
}

int empty(Bag b) //if void then return 1
{
    if(b->card==0)
        return 1;
    return 0;
}

int freqs(Iterator it)
{
	return it->s->freq[it->crt];
}




