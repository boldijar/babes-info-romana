#ifndef VECTOR_H
#define VECTOR_H
#include "TElem.h"

struct Product{
	int price;
	char* name;
};

struct _Vector;
typedef _Vector* Vector;

struct _Iterator;
typedef _Iterator *Iterator;



void newVector(Vector &v,cpyFun cpy,cmpFun cmp,delFun del); 
void add(Vector &v, TElem x);      
int getcard(Vector v);                 
TElem getElem(Vector v, int i);
void printVector(Vector v);
void dealocate(Vector&);   
int find(Vector v, TElem x);
int cmp(TElem e1, TElem e2);
void sort(Vector &v);
void sortP(Vector &v);

Iterator Create(Vector v);
void Next(Iterator it);
TElem Elem(Iterator it);
int Valid(Iterator it);
void DelIt(Iterator &it);
#endif;


