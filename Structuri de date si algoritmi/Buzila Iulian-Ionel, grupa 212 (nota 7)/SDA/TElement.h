#pragma once
class TElement
{
private:
	int linie;
	int coloana;
	int valoare;

public:
	TElement(void);
	TElement(int,int,int);
	
	bool operator!=(TElement& p){
		return this->valoare != p.getValoare() || this->linie != p.getLinie() || this->coloana != p.getColoana();
	}
	bool operator==(TElement& p){
		return !(this->valoare != p.getValoare() || this->linie != p.getLinie() || this->coloana != p.getColoana());
	}

	int getLinie();
	int getColoana();
	int getValoare();
	void setLinie(int val);
	void setColoana(int val);
	void setValoare(int val);
	void print();

	~TElement(void);
};

