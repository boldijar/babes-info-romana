#include "upoli.h"
#include <iostream>
#include <conio.h>

int main()
{
	poli p,s;
	monom m;

	readm(m);
	readp(p);
	addmonom(p,m,s);
	printp(s);
	getch();
	return 0;
}

