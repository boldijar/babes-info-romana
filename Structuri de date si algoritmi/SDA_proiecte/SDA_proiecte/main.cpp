#include "Colectie.h"
#include <iostream>
#include <fstream>

using namespace std;

int read_collection(IColectie* a,char* path) {
	ifstream f(path);
	if (!f)
	{
		cout << "Cannot open input file!";
		return 1;
	}

	int n;
	IElem* Int = new Integer();

	while(!f.eof())
	{
		f >> n ;
		a->add(new Integer(n));
	}
	f.close();
	return 0;
}

int main()
{
	IColectie* a = new Colectie;
	read_collection(a,"D:\collection.txt");

	a->print();

	cout << endl;
	cout << "==========SEARCH TEST==========" << endl;
	cout << "Search test for 123 :" << a->search(new Integer(123)) << endl;
	cout << "Search test for  30 :" << a->search(new Integer( 30)) << endl;
	cout << "Search test for 222 :" << a->search(new Integer(222)) << endl;
	cout << "Search test for 666 :" << a->search(new Integer(999)) << endl;

	cout << endl;
	cout << "==========REMOVE TEST==========" << endl;
	cout << "Remove test for  30 :" << a->remove(new Integer( 30)) << endl;
	cout << "Remove test for  30 :" << a->remove(new Integer( 30)) << endl;
	cout << "Remove test for  30 :" << a->remove(new Integer( 30)) << endl;
	cout << "Remove test for 222 :" << a->remove(new Integer(222)) << endl;
	cout << "Remove test for 828 :" << a->remove(new Integer(828)) << endl;
	cout << "Remove test for 693 :" << a->remove(new Integer(693)) << endl;
	cout << "Remove test for 999 :" << a->remove(new Integer(999)) << endl;

	a->print();
	system("pause");
	return 0;
}