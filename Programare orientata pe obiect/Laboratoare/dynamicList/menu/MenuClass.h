#pragma once

class MenuClass
{
public:
	MenuClass(void);
	void addUi();
	void updateUi();
	void deleteUi();
	void filterAmountUi();
	void filterTypeUi();
	void sortAmountUi();
	void sortAmountUiDesc();
	void sortTypeUi();
	void sortTypeUiDesc();
	void ruleazaMeniu();
	~MenuClass(void);

private:
	void afisareMeniu();
	int validareOptiune(char option[]);
	char * ExitCode() {
		return "0";
	}
	char * ExitCode1() {
		return "x";
	}
};
