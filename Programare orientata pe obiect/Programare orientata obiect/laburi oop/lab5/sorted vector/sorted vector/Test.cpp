#include <iostream>
#include "Vec.h"
#include "Iterator.h"
#include "TElem.h"
#include <string.h>
#include <conio.h>

using namespace std;

void copyInt(TElem& dest, TElem source)
{
	 dest=new int(*(int*)source);

}

int compInt(TElem x,TElem y)
{
	int a = *(int*)x;
	int b = *(int*)y;
	if (a<b) return -1;
	if (a>b) return 1;
	return 0;
}

void deleInt(TElem & e)
{
	delete(int * ) e ;
}

void readVecInt(Vec & v)
{
	cout<<"Give the number of elements: ";
	int n;
	cin>>n;
	create(v,copyInt, compInt, deleInt, n);
	for (int i=0; i<n; i++)
		{
			TElem e = new int;
			cout<<"elem "<<i+1<<" is: ";
			cin>>*(int*)e;
			add(v,e); 
			deleInt(e);
		}
}

void print(Vec v)
{
	Iterator it = allocate(v);
	while (valid(it))
		{
			if (verify(v))
			{
				cout<<*(int*)elem(it)<<" ";
				next(it);
			}
			else next(it);
		}
	deallocate(it);
}
//Product//
struct product
{
	char * name;
	int price;
};

void createProduct(product* &p)
{
	p = new product;
	cout<<"Give the name: ";
	p->name = new char[10];
	cin>>p->name;
	cout<<endl<<"Give the price: ";
	cin>>p->price;
}

int cmpProd(TElem e1, TElem e2)
{
	product p1=*(product*)e1;
	product p2=*(product*)e2;
    if ((strcmp(p1.name,p2.name)==0)&&(p1.price==p2.price)) return 0;
    return 1; 
}
void cpyProd(TElem& e1, TElem e2)
{
	 e1=new product;
	 product * p2=(product*) e2;
	 product * p1=(product*) e1;
	 p1->name=new char[strlen(p2->name)+1];
	 strcpy(p1->name,p2->name);
	 p1->price=p2->price;
}

void delProd(TElem& e){
	product * p =(product*) e;
	delete[] p->name;
	delete p;
}

void createVecProd(Vec& v)
{
	 cout<<"Give the number of products: ";
	 int n;
	 cin>>n;
	 create(v, cpyProd, cmpProd, delProd, n);
	 TElem x;
	 product* p;
	 for(int i=0;i<n;i++)
	 {
	  createProduct(p);
	  x=p;
	  add(v,x);
	  delProd(x);
	 }
}

void printProd(Vec v)
{
	Iterator it=allocate(v);
	while(valid(it))
	{
		product* p= (product*)elem(it);
		cout<<p->name<<" "<<p->price<<endl;
		next(it);
	}
	deallocate(it);
}
int main()
{
//Vec n;
Vec v;	
	readVecInt(v);
	print(v);
/*while (constvec(v) == 0)
	{
		readVecInt(v);
		print(v);
		
	}
				
	createVecProd(n);
	printProd(n);*/
	
	return 0;
	_getch();
}

