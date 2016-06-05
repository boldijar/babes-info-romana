#ifndef SORTMAP_H
#define SORTMAP_H
#include "TElem.h"
struct _map;
typedef _map* map;

struct _Iterator;
typedef _Iterator* Iterator;

void init(map&,copyFun,cmpFun,delFun,int=20);
bool isEmpty(map);
int getSize(map);
void addElem(map&,TElem);
bool belongs(map,TElem);

Iterator create(map);
void  next(Iterator&);
int valid(Iterator);
TElem elem(Iterator);//crt pair

void destroy(map&);
void destroyIt(Iterator&);

#endif