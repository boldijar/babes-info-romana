#pragma once
class DomainClass
{
public:
	
	DomainClass(int nr,int number,float amount,char* type);
	DomainClass(void);
	~DomainClass(void);

	void setBlock(int nr,float amount, char* type);
	int GetId();
	int GetNumber();
	float GetAmount();
	char* GetType();
	void Print();
	int Equal(DomainClass,DomainClass);
	
	
private:
		int id;
		int number;
        float amount;
        char type[10];

};

