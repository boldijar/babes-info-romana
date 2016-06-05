#ifndef VECTOR_H
#define VECTOR_H
#include "Telem.h"

struct _vect;
typedef _vect* vect;

void Create(vect &, cpyfct,cmpfct,delfct);
void Add(vect &, Telem);
int Belongs(vect, Telem);
int Card(vect);
Telem getElem(vect, int);
int getPoz(vect, Telem);
int Empty(vect);
void Dealloc(vect &);

#endif

