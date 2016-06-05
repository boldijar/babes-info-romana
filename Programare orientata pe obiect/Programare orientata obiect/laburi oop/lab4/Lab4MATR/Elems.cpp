#include "Elems.h"
#include <cstring>
#include <cstdlib>
using namespace std;

Elems create(char* c) {
	Elems e;
	e=0;
	int l=strlen(c);
	for(int i=0;i<l;i++) 
		e=e*10+int(c[i])-'0';
	return e;
}
