#pragma once
#include "MatriceRara.h"

class Ui
{
public:
	Ui(void);

	MatriceRara mr;

	void afisareUi();
	void adaugaUi();
	void modificaUi();
	void stergeUi();
	void afisareMeniu();
	void ruleazaMeniu();
	~Ui(void);
};

