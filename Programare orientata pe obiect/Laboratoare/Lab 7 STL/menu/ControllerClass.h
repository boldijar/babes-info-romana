#pragma once

#include "DomainClass.h"
#include <vector>

class ControllerClass
{
public:
	ControllerClass(void);
	void add(int,int,float,char*);
	void updateController(int id,int number,float amount,char* type);
	void deleteController(int nr);
	void filterAmountController(float suma);
	void filterTypeController(char* tip);
	void sortAmountController(std::vector<DomainClass>  &);
	void sortAmountControllerDesc(std::vector<DomainClass>  &);
	void sortTypeController(std::vector<DomainClass>  &);
	void sortTypeControllerDesc(std::vector<DomainClass>  &);
	int findById(int id);
	int findByType(char* tip);
	~ControllerClass(void);
};

