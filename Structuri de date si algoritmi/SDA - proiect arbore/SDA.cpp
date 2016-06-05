#include "Arbore.h"
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

void main()
{
	ARBORE Arb;
	int a,n;
	fstream f("in.txt",ios::in);
	while(!f.eof())
	{
		f>>a;
		Arb.Adauga(a);
	}
	cout<<"Ce numar sa fie eliminat? ";
	cin>>n;
	Arb.Eliminare(n);
	Arb.Preordine(1);
	Arb.Inordine(1);
	Arb.Postordine(1);

	_getch();
}
