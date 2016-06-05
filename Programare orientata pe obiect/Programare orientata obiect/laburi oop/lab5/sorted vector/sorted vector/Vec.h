#ifndef VEC_H
#define VEC_H

#include "TElem.h"

struct _Vec;
typedef _Vec* Vec;

struct _Iterator;
typedef _Iterator* Iterator;


void create(Vec & v, cpyFun , cmpFun , delFun , int);
bool belongs(Vec v, TElem e); 
void add(Vec & v, TElem e);
int card(Vec v);
TElem getelem(Vec v, int i);
int constvec(Vec v);
void destroy(Vec & v);
bool verify(Vec v);

#endif