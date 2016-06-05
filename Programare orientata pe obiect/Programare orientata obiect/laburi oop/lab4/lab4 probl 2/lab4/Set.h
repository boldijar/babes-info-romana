#ifndef SET_H
#define SET_H
#include "Telem.h"
struct _Set;
typedef _Set* Set; //Set is pointer to _Set
struct _Iterator;
typedef _Iterator* Iterator;
void init(Set &,int=20);
void add(Set,Telem);
int belongs(Set,Telem);
int card(Set);
Set uni(Set,Set);
int empty(Set);
void create(Set s,Iterator &it);
void next(Iterator&);
int valid(Iterator);
Telem elem(Iterator);
void destroy(Set &);
void destroy(Iterator &);
#endif