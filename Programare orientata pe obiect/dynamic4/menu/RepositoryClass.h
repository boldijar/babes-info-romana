#pragma once
#include "DomainClass.h"
#include "DynamicList.h"
class RepositoryClass
{
public:
	RepositoryClass(void);
	~RepositoryClass(void);

	void LoadFromFlie(DynamicList & lista);
	
	void SaveInFile(DynamicList & lista);
	

	
};

