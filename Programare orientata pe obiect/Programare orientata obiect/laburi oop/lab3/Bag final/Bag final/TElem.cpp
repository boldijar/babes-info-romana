#include "TElem.h"

void copy(TElem & dest, TElem source)
{ dest=source; }

int comp (TElem e1, TElem e2)
{
	if (e1<e2) return -1;
	if (e1>e2) return 1;
	return 0;
}
