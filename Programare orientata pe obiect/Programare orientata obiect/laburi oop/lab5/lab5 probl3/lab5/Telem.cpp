#include "Telem.h"
void copy(Telem & dest,Telem sour)
{
	dest=sour;
}
int cmp(Telem e1,Telem e2)
{
	if(e1==e2)
		return 0;
	else
		if(e1<e2)
			return -1;
	return 1;
}

