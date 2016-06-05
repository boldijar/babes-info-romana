#pragma once

#include "DomainClass.h"
class ControllerClass
{
public:
	ControllerClass(void);
	void Add(int,int,float,char*);
	void UpdateController(int id,int number,float amount,char* type);
	void DeleteController(int nr);
	void FilterAmountController(float suma);
	void FilterTypeController(char* tip);
	void SortAmountController(DomainClass lista[100],int &iter);
	void SortAmountControllerDesc(DomainClass lista[100],int &iter);
	void SortTypeController(DomainClass lista[100],int &iter);
	void SortTypeControllerDesc(DomainClass lista[100],int &iter);
	int FindById(int id);
	int FindByType(char* tip);
	~ControllerClass(void);
};

