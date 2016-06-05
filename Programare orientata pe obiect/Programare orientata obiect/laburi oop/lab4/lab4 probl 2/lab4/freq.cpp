#include "freq.h"
#include "Set.h"
#include <iostream>
using namespace std;
struct _Freq
{
	Telem *elem;
	int *time;
	int len;
};
void initFreq(Freq & f)
{
	f=new _Freq;
	f->len=0;
	f->elem=new Telem[20];
	f->time=new int[20];
	for(int i=0; i<19; i++)
		f->time[i]=0;
}

int belongsFreq(Freq f,Telem e)
{
	for(int i=0; i<f->len; i++)
		if(f->elem[i]==e)
			return i;
    return -1;
}
	
void addFreq(Freq & f,Telem e)
{
	if(belongsFreq(f,e)!=-1)
		f->time[belongsFreq(f,e)]++;   //add on the position of ocurrance
	else
	{
		f->elem[f->len]=e; //add the new element
		f->time[f->len]++; //increase occurance
		f->len++;     //increase lenght
	}
}

void printFreq(Freq f)
{
    cout<<endl;
	for(int i=0; i<f->len; i++)
		cout<<f->elem[i]<<" appears "<<f->time[i]<< " times"<<endl;
}

void destroyFreq(Freq &f)
{
		delete [] f->elem;
		delete [] f->time;
	delete f;
}
