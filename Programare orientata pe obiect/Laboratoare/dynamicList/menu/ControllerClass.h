#pragma once

#include "DomainClass.h"
#include "DynamicList.h"
class ControllerClass
{
public:
	ControllerClass(void);
	void add(int,int,float,char*);
	void updateController(int id,int number,float amount,char* type);
	void deleteController(int nr);
	void filterAmountController(float suma);
	void filterTypeController(char* tip);
	void sortAmountController(DynamicList &);
	void sortAmountControllerDesc(DynamicList &);
	void sortTypeController(DynamicList &);
	void sortTypeControllerDesc(DynamicList &);
	int findById(int id);
	int findByType(char* tip);
	~ControllerClass(void);
};

