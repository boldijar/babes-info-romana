#ifndef ITERATOR_H
#define ITERATOR_H
#include "Vec.h"



Iterator allocate(Vec v);
void next(Iterator it);
bool valid(Iterator it);
TElem elem(Iterator it);
void deallocate(Iterator & it);

#endif
