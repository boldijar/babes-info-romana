#pragma once
#include "MatriceRara.h"

//class MatriceRara;
class Iterator
{
private:
	friend class MatriceRara;
	MatriceRara* m;
public:
	Iterator();
	Iterator(MatriceRara*);
	TElement element();
	int curent;
	void urmator();
	bool valid();

	~Iterator(void);
};

