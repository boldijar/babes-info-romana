#pragma once
#include "DomainClass.h"
class DynamicList
{
public:
	DynamicList(void);
	~DynamicList(void);
	void testDelete();
	void testUpdate();
	void testAppend();
	void append(const DomainClass& element);
	void deletePosition(int p);
	void updatePosition(int p, const DomainClass& cheltuiala);
	int getLenght();
	int getCapacity();
	DomainClass& operator[](int k);
	void display(void) const;
	private:
	DomainClass** elements;
	int lenght;
	int capacity;
	void resize();
};

