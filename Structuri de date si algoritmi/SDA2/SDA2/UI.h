#pragma once
class UI
{
public:
	UI(void);
	~UI(void);
	void adaugaUi();
	void stergeUi();
	void cautaUi();
	void RuleazaMeniu();
	void afisareTotUi();
	void afisareJud();
	void afisareS();
private:
	Controller ctr;
	void AfisareMeniu1();
	void AfisareMeniu2();
	char * ExitCode() {
		return "0";
	}
	char * ExitCode1() {
		return "x";
	}
	
};

