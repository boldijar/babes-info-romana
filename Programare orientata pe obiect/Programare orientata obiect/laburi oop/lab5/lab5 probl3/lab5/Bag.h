#ifndef SET_H
#define SET_H
#include "Telem.h"
struct _Bag;
typedef _Bag* Bag; //Set is pointer to _Set
struct _Iterator;
typedef _Iterator* Iterator;
void init(Bag &,cpyFun,cmpFun,delFun,int=20);
void add(Bag,Telem);
int belongs(Bag,Telem);
int card(Bag);
void uni(Bag,Bag,Bag&);
void inter(Bag,Bag,Bag&);
int empty(Bag);
void create(Bag s,Iterator &it);
void next(Iterator&);
int valid(Iterator);
Telem elem(Iterator);
int freqs(Iterator);
void destroy(Bag &);
void destroy(Iterator &);
#endif