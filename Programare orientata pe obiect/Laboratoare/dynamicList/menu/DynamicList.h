#pragma once
#include "DomainClass.h"
class DynamicList
{
public:
	DynamicList(void);
	
	void testDelete();
	void testUpdate();
	void testAppend();
	void append(const DomainClass& element);
	void deletePosition(int p);
	void updatePosition(int p, const DomainClass& cheltuiala);
	int getLength();
	int getCapacity();
	DomainClass& operator[](int k);
	void display(void) const;
	~DynamicList(void);

private:
	DomainClass** elements;
	int lenght;
	int capacity;
	void resize();
};

