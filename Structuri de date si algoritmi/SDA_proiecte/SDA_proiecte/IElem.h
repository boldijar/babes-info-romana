#pragma once
class IElem
{
public:
	virtual char* toString()=0;
	virtual int comparesTo(IElem*)=0;
	virtual void print()=0;
	virtual ~IElem(){};
};

