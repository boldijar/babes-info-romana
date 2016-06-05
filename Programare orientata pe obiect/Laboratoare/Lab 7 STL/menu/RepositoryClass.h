#pragma once
#include "DomainClass.h"
#include <vector>

class RepositoryClass
{
public:
	RepositoryClass(void);
	~RepositoryClass(void);

	void loadFromFlie(std::vector<DomainClass>  & lista);
	
	void saveInFile(std::vector<DomainClass>  & lista);
	

	
};

