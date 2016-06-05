
#include"Vector.h"
#include "TElem.h"
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include<sstream>
#include<iostream>
using namespace std;

//////////Product////////////////


void ReadProd(Product *&p){
	p=new Product;
	p->name=new char[20];
	cout<<"Give the name of the product:";
	cin>>p->name;
	cout<<"Give the price of the product:";
	cin>>p->price;
	cout<<endl;
}

void cpyProd(TElem &a,TElem b){
	a=new Product;
	Product *p2=(Product *)b;
	Product *p1=(Product *)a;
	p1->name=new char[strlen(p2->name)+1];
	strcpy(p1->name,p2->name);
	p1->price=p2->price;
}

int cmpProd(TElem a,TElem b)
{
	Product a1=*(Product *)a;
	Product b1=*(Product *)b;
	if(strcmp(a1.name,b1.name)==0)
		return 0;
	else 
		if(strcmp(a1.name,b1.name)>0)
			return 1;
		else
			return -1;
}


void delProd(TElem &x){
	Product *x1 =(Product*) x;
	delete[] x1->name;
	delete x1;
}

void ReadVectProd(Vector &v){
	newVector(v,cpyProd,cmpProd,delProd);
	int n;
	cout<<"Enter the number of products:";
	cin>>n;
	TElem x;
	Product *t;
	for(int i=0;i<n;i++){
		ReadProd(t);
		x=t;
		add(v,x);
	}
	sortP(v);
}

void printVectProd(Vector v){
	Iterator it;
	it=Create(v);
	while(Valid(it)){
		Product *x=(Product *)Elem(it);
		cout<<x->name<<"---"<<x->price<<endl;
		Next(it);
	}
	DelIt(it);
}

void VecFinalP(Vector v){
	Iterator it;
	it=Create(v);
	while(Valid(it)){
		if (find(v, Elem(it))==0){
			Product *x=(Product *)Elem(it);
			cout<<x->name<<"---"<<x->price<<endl;
			Next(it);
		}
		else 
			Next(it);
	}
	DelIt(it);
}

////////////////////Integer////////////////////////
int cmpInt(TElem e1, TElem e2){
	int x1=*(int*)e1;
	int x2=*(int*)e2;
	if (x1==x2) return 0;
	if (x1<x2) return -1;
	return 1;
}
void cpyInt(TElem& e1, TElem e2){
	e1=new int(*(int*)e2);
}

void delInt(TElem& e){
	delete (int*) e;
}

void ReadVectInt(Vector &v){
	newVector(v,cpyInt,cmpInt,delInt);
	TElem x;
	int n;
	cout<<"Enter the number of elements:";
	cin>>n;
	cout<<"Give the numbers:"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Number"<<i+1<<":";
		x = new int;		
		cin>>*(int*)x;	
		add(v,x);
	}
	sort(v);
}

void printVectInt(Vector v){
	Iterator it;
	it=Create(v);
	while(Valid(it)){
		cout<<*(int*)Elem(it)<<" ";
		Next(it);
	}
	DelIt(it);
}

void VecFinal(Vector v){
	Iterator it;
	it=Create(v);
	while(Valid(it)){
		if (find(v, Elem(it))==0){
			cout<<*(int*)Elem(it)<<" ";
			Next(it);
		}
		else 
			Next(it);
	}
	DelIt(it);
}

////////////// Main ///////////////////

int main(){
    Vector v;
	int r;
	cout<<"1.Integer"<<endl<<"2.Product"<<endl;
	cout<<"Enter:";
	cin>>r;
	if (r==1){
		ReadVectInt(v);
		while ((getcard(v))!=0){
			cout<<endl;
			cout<<"The sorted vector is:";
			VecFinal(v);
			dealocate(v);
			cout<<endl;
			ReadVectInt(v);
		}
	}
	else{
	    ReadVectProd(v);
		while ((getcard(v))!=0){
			cout<<endl;
			cout<<"The sorted vector is:";
			VecFinalP(v);
			dealocate(v);
			cout<<endl;
			ReadVectProd(v);
		}
	}

	_getch();

	return 0;
}