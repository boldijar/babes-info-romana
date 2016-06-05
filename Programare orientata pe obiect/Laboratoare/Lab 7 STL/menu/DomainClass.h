#pragma once
class DomainClass
{
public:
	
	DomainClass(int nr,int number,float amount,char* type);
	DomainClass(void);
	~DomainClass(void);
	
	void setBlock(int nr,float amount, char* type);
	int getId();
	int getNumber();
	float getAmount();
	char* getType();
	void setNumber(int );
	void setAmount(float);
	void setType(char* );
	void print();
	int equal(DomainClass,DomainClass);
	
	
private:
		int id;
		int number;
        float amount;
        char type[10];

};

