#include "TElem.h"
#include "Vec.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

struct _Iterator
	{
		Vec v2;
		int crt;
	};

Iterator allocate(Vec v)
{
	Iterator it = new _Iterator;
	it->v2 = v;
	it->crt = 0;
	return it;
}

void next(Iterator it)
{
	it->crt++;
}

bool valid(Iterator it)
{
	return it->crt < card(it->v2);
}

TElem elem(Iterator it)
{
	return getelem(it->v2,it->crt);
}
void deallocate(Iterator & it)
{
	delete it;
}