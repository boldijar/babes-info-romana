#pragma once
#include "IElem.h"
class IColectie
{
public:
	virtual void add(IElem*)=0;
	virtual void print()=0;
	virtual int hash(IElem*)=0;
	virtual int remove(IElem*)=0;
	virtual int search(IElem*)=0;
	virtual int getNr_elem()=0;
	virtual ~IColectie(){};
};

