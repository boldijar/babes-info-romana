#pragma once
//#include<TElement.h>

class Iterator
{

public:
	int curent;
	Multime *m ;
	Iterator(Multime *);
	
	Iterator(void);
	bool urmator();
	TElement element();
	bool valid();
	
	~Iterator(void);
};

