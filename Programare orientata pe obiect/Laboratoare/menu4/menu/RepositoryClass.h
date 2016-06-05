#pragma once
#include "DomainClass.h"
class RepositoryClass
{
public:
	RepositoryClass(void);
	~RepositoryClass(void);

	void LoadFromFlie(DomainClass lista[100],int &iter);
	
	void SaveInFile(DomainClass lista[100],int iter);
	

	
};

