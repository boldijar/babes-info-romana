#pragma once

#include "DomainClass.h"
#include "DynamicList.h"
class ControllerClass
{
public:
	ControllerClass(void);
	void Add(int,int,float,char*);
	void UpdateController(int id,int number,float amount,char* type);
	void DeleteController(int nr);
	void FilterAmountController(float suma);
	void FilterTypeController(char* tip);
	void SortAmountController(DynamicList &);
	void SortAmountControllerDesc(DynamicList &);
	void SortTypeController(DynamicList &);
	void SortTypeControllerDesc(DynamicList &);
	int FindById(int id);
	int FindByType(char* tip);
	~ControllerClass(void);
};

