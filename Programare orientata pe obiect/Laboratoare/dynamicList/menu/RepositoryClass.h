#pragma once
#include "DomainClass.h"
#include "DynamicList.h"
class RepositoryClass
{
public:
	RepositoryClass(void);

	void loadFromFlie(DynamicList & lista);
	void saveInFile(DynamicList & lista);
	
	~RepositoryClass(void);
};

