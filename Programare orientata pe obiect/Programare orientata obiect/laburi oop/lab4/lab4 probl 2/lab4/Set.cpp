
#include "Set.h"
struct _Set
{
    int card,cap;
    Telem *elem;
};
struct _Iterator
{
    _Set *s;
    int crt;
};
void init(Set &s,int c)
{
    s=new _Set;
    s->cap=c;
    s->card=0;
    s->elem=new Telem[c];
}
void realoc(Set &s)
{
    Telem *temp=new Telem[2*s->cap];
    for(int i=0; i<s->card; i++)
        copy(temp[i],s->elem[i]);
    delete[]s->elem;
    s->elem=temp;
    s->cap*=2;
}
int card(Set s)
{
    return s->card;
}
int belongs(Set s,Telem e)
{
    for(int i=0; i<s->card; i++)
        if(cmp(s->elem[i],e)==0)
            return 1;
    return 0;
}
void add(Set s,Telem e)
{
    if(!belongs(s,e))
    {
       if(s->card==s->cap)
           realoc(s);
       copy(s->elem[s->card++],e);
    }
}

void destroy(Set &s)
{
    delete []s->elem;
    delete s;
}

void create(Set s,Iterator &it)
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

Set uni(Set m,Set n)
{
    Set rez;
    init(rez,m->card+n->card);
    rez=m;
    for(int i=0; i<m->card; i++)
        copy(rez->elem[i],m->elem[i]);
    rez->card=m->card;
    for(int i=0; i<n->card; i++)
        add(rez,n->elem[i]);
    return rez;
} 

int empty(Set s) //if void then return 1
{
    if(s->card==0)
        return 1;
    return 0;
}




