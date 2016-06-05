#include "Nod.h"

Nod::Nod()
{
	st=0;
	dr=0;
	info=0;
	dad=0;
}
int Nod::getInfo()
{
	return info;
}
int Nod::vid()
{
	if((info==0)&&(st==0)&&(dr==0)&&(dad==0))
		return 1;
	else 
		return 0;
}
void Nod::vidare()
{
	info=0;
	st=0;
	dr=0;
	dad=0;
}
void Nod::setInfo(int k)
{
	info=k;
}
int Nod::getSt()
{
	return st;
}
void Nod::setSt(int k)
{
	st=k;	
}
int Nod::getDr()
{
	return dr;
}
void Nod::setDr(int k)
{
	dr=k;
}
int Nod::getDad()
{
	return dad;
}
void Nod::setDad(int i)
{
	dad=i;
}