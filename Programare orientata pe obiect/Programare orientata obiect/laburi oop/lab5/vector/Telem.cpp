#include "Telem.h"

void copy(Telem & dest, Telem source)
{
	dest=source;
}

int comp(Telem a, Telem b)
{
	if(a>b)
		return 1;
	if(a<b)
		return -1;
	return 0;
}
