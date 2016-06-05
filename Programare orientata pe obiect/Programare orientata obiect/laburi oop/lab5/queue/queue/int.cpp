/*
#include "queue.h"
#include <iostream>
using namespace std;

struct Order{
	int number;
	int content;
};
void cpyOrder(Telem &cont1,Telem cont2)
{
	cont1=(Telem)(new Order);
	Order* c1=(Order*)cont1;
	Order* c2=(Order*)cont2;
	c1->content=c2->content;
	c1->number=c2->number;
}
int cmpOrder(Telem cont1,Telem cont2)
{
	
	Order* c1=(Order*)cont1;
	Order* c2=(Order*)cont2;
	if(c1->number<c2->number)
		return -1;
	else
		if(c1->number==c2->number)
			return 0;
	return 1;
}

void delOrder(Telem cont)
{
	delete (Order*)cont;
}

void createOrder(Order *curOrder)
{
	cout<<"Give the number";
	cin>>curOrder->number;
	cout<<"Give the content";
	cin>>curOrder->content;
}

void printOrder(Order* curr)
{
	cout<<curr->number<<' ' <<curr->content;
	cout<<endl;
}

void main()
{
	Queue q;
	cout<<"Give the number of elements (not smaller than 3)";
	int n;
	cin>>n;
	init(q,cpyOrder,cmpOrder,delOrder,20);
	Telem e;
	Order *curOrder=new Order;
	for(int i=0; i<n; i++)
	{
		createOrder(curOrder);
		e=(Telem)curOrder;
		push(q,e);
	}
	for(int i=0; i<=2; i++)
	{
		Order* curr;
		curr=(Order*)pop(q);
		printOrder(curr);
		delOrder((Telem)curr);
	}
	destroy(q);
	system("pause");

}
*/