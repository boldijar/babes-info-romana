/*
 8. Let A and B two sets of integer numbers. Compute the reunion set of A and B (A U B).
 */
#include <iostream>
using namespace std;
#include "lab2.h"
#include <conio.h>

int main(){
    set a,b,c;
	int i;
	read(a);
	read(b);
	c=a;
	for(i=1;i<=b.n;i++)
		if (search(b.v[i],a)==0)
			add(b.v[i],c);
	     print(c);
	getch();
	return 0; 
}