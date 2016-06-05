#include "Set.h"
#include <iostream>
using namespace std;
#include "freq.h"
void read(Set &s,Freq f)
{
    cout<<"Give the number of elements ";
    int n;
    cin>>n;
    init(s,n);
    for(int i=0; i<n; i++)
    {
        Telem e; 
        cin>>e;
		addFreq(f,e);
        add(s,e);
    }
}
void print(Set s)
{
    Iterator it;
	create(s,it);
    while(valid(it))
    {
        cout<<elem(it)<<' ';
        next(it);
    }
	destroy(it);
	
}
void main()
{
    Set unions,a; //the set of union
	Freq f;
	init(unions,30);
	initFreq(f);
    read(a,f);
    while(!empty(a))
	{
		unions=uni(unions,a);
		if(!empty(a))
		{
			destroy(a);
			read(a,f);
		}
	}	
	destroy(a);
	cout<<"The union of the sets is ";
	print(unions);
	cout<<endl<<"The frequency vector is  ";
	printFreq(f);
	destroyFreq(f);
	system("pause");

}




