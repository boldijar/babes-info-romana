#include "Bag.h"
#include "TELem.h"
#include <iostream>

using namespace std;
void init(Set & s, int c)
{
	s.capacity=c;
	s.elem=new TElem[c];
	s.occ=new int[c];
	s.card=0;
}


void destroy (Set & s)
{
	delete[] s.elem;
	delete[] s.occ;
	s.card=-1;
}

int belongs(Set s, TElem e)
{
	for(int i=0;i<s.card;i++)
		if (s.elem[i]==e) return 1;
	return 0;
}

void realoc(Set & s)
{
	TElem * temp = new TElem[2*s.capacity];
	for(int i=0;i<s.card;i++)
			copy(temp[i],s.elem[i]);
	delete [] s.elem;
	s.elem=temp;
	s.capacity*=2;
}

void add(Set &s, TElem e)
{
    if (s.card==s.capacity) realoc(s);
    bool found=false;
    int i=0;
    while ((found==false)&&(i<s.card))
    {
        if (s.elem[i]==e) found=true;
        else i++;
    }
    if (found==true) s.occ[i]++;
    else
    {
        s.card++;  // !! chiar adaug elementul - tu nu il adaugai niciodata, daca era element nou
        s.elem[i] = e;
    }
}


int card (Set s)
{ return s.card;}

Set Union1 (Set m, Set n)
{
	Set rez;
	init(rez, m.card+n.card);
	rez=m;
	for (int i=0;i<m.card;i++)
		for (int j=0;j<m.occ[i];j++)
			copy(rez.elem[i],m.elem[i]);
	rez.card=m.card;
	for(int i=0;i<n.card;i++)
		for (int j=0;j<n.occ[i];j++)
			add(rez,n.elem[i]);
	return rez;
}

Set Intersection(Set m,Set n)
{
	Set rez;
	if (m.card<n.card) init(rez,m.card);
	else init(rez,n.card);
	for (int i=0;i<n.card;i++)
		if(belongs(m,n.elem[i])) add(rez,n.elem[i]);
	return rez;
}

Set MostElem(Set m,Set n)
{
	if (m.card>n.card) return m;
	else return n;
}

TElem * to_array(Set s)
{
	TElem * rez = new TElem[s.card];
	for (int i=0;i<s.card;i++)
			copy(rez[i], s.elem[i]);
	return rez;
}

Iterator create( Set s)
{
	Iterator it;
	it.s=&s;
	it.crt=0;
	return it;
}

void next (Iterator & it)
{ it.crt++ ;}

TElem elem(Iterator it)
{
	return it.s->elem[it.crt];
}

int valid (Iterator it)
{
	return it.crt<it.s->card;
}
