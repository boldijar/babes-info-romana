/*5. SORTED_VECTOR 

Write a program that reads many sorted vectors. Reading ends with the empty vector. For each read vector, print the distinct elements.
The elements of vectors will be:

      - integer numbers

      - products (name, price) (the products will be sorted based on their names)


*/
#include <iostream>
using namespace std;
#include "Operations.h"
#include <conio.h>

int main(){
	vector v,s;
	int p1,p2;
	int nr;
	cout<<"Give the number of vectors:";
	cin>>nr;
	v.n=0;
	for (int i=1;i<=nr;i++){ 
		read(s);
		del_all_seq(s);
		merge(v,s,v);
	}
	sort(v);
	print(v);
	release(v);
	release(s);

	getch();
	return 0;
}