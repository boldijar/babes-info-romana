#include "Bag.h"
#include <iostream>
using namespace std;

void cpyIntegers(Telem & dest,Telem sour)
{
	dest=new int;
	*(int*)dest=*(int*)sour;
}
int cmpIntegers(Telem x,Telem y)
{
	int a1=*(int*)x;
	int b1=*(int*)y;
	if(a1<b1)
		return -1;
	if(a1>b1)
		return 1;
	return 0;
}
void delIntegers(Telem &e)
{
	delete (int*)e;
}

void readBag(Bag &b)
{
	init(b,cpyIntegers,cmpIntegers,delIntegers,20);
	cout<<"Give the numbers of elements ";
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		Telem e=new int;
		cin>>*(int*)e;
		add(b,e);
		delIntegers(e);
	}
}

void print(Bag b,int c)
{
	Iterator it;
	create(b,it);
	while(valid(it))
	{
		cout<<*(int*)elem(it);
		if(c==1)
			cout<<" appears "<< freqs(it)<< " times"<<endl;
		next(it);
	}
	destroy(it);
}

/*void main()
{
	Bag a,uniBag,intBag,intBag2;
	int no=1;
	readBag(a);
	init(uniBag,cpyIntegers,cmpIntegers,delIntegers,20);
	init(intBag,cpyIntegers,cmpIntegers,delIntegers,20);
	while(!empty(a))
	{
		uni(uniBag,a,uniBag);
		if(no==1)
		{
			inter(uniBag,a,intBag);
			no++;
		}
		else
		if(no>=2)
		{
			init(intBag2,cpyIntegers,cmpIntegers,delIntegers,20);
			inter(intBag,a,intBag2);
			intBag=intBag2;
		}
		destroy(a);
		readBag(a);
	}
	destroy(a);
	cout<<"The union is "<<endl;
	print(uniBag,1);
    cout<<"The intersection is "<<endl;
	if(empty(intBag)==0)
		print(intBag,0);
	else	
		cout<<"the empty bag";
	system("pause");
}
*/
	
