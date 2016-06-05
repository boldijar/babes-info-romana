#include "queue.h"
#include <string.h>
#include <iostream>
using namespace std;
struct Order{
	char *name;
	int price;
};
void cpyOrder(Telem &e1,Telem e2)
{
	e1=new Order;
	Order *o1=(Order*)e1;
	Order *o2=(Order*)e2;
	o1->name= new char[20];
	strcpy(o1->name,o2->name);
	o1->price=o2->price;
}
int cmpOrder(Telem e1,Telem e2)
{
	Order *o1=(Order*)e1;
	Order *o2=(Order*)e2;
	if(o1->price<o2->price)
		return -1;
	else 
		if(o1->price==o2->price)
			return 0;
	return 1;
}
void delOrder(Telem e1)
{
	Order *o=(Order*)e1;
	delete [] o->name;
	delete o;
}

void createOrder(Order * & e)
{
	e=new Order;
	e->name=new char[20];
	cout<<"Give the name";
	cin>>e->name;
	cout<<"Give the price";
	cin>>e->price;
}
void printQ(Order *o)
{
	cout<<o->name<<' '<<o->price;
	cout<<endl;
}


void main()
{
	Queue q;
	init(q,cpyOrder,cmpOrder,delOrder,20);
	cout<<"Give the number of Orders (not smaller than 3)";
	int n;
	cin>>n;
	Telem e;
	for(int i=0; i<n; i++)
	{
		Order *o;
		createOrder(o);
		e=(Telem)o;
		push(q,e);
	}
	for(int i=0; i<=2; i++)
	{
		Order *cur;
		cur=(Order*)pop(q);
		printQ(cur);
		delOrder(cur);
	}
	system("pause");
}
	
    
