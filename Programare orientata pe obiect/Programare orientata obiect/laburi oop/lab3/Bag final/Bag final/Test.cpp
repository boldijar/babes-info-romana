#include "Bag.h"
#include "TElem.h"
#include <iostream>

using namespace std;

void read(Set & s)
{
	cout<<"Give the no of elem: ";
	int n;
	cin>>n;
	init(s,n);
	for (int i=0;i<n;i++)
	{
		TElem e;
		cout<<"elem "<<i<<"is: "<<'\n';
		cin>>e;
		add(s,e);
	}
}

void print(Set s)
{
	Iterator it=create(s);
	while (valid(it))
	{
		cout<<elem(it)<<" ";
		next(it);
	}
}

int main ()
{
	Set a,b,r,i,m;
	read(a);
	init(r,a.card);
	init(i,a.card);
	init(m,a.card);
	while (a.card!=0)
	{
		r=Union1(a,r);
		i=Intersection(a,i);
		//m=MostElem(a,m);
		read(a);
	}
	print(r);
	print(i);
	//print(m);
	destroy(a);
	destroy(b);
	destroy(r);
	destroy(i);
	//destroy(m);

	return 0;
}