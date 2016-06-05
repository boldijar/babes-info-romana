#pragma once

class MenuClass
{
public:
	MenuClass(void);
	~MenuClass(void);
	void AddUi();
	void UpdateUi();
	void DeleteUi();
	void FilterAmountUi();
	void FilterTypeUi();
	void SortAmountUi();
	void SortAmountUiDesc();
	void SortTypeUi();
	void SortTypeUiDesc();
	void RuleazaMeniu();
	
private:
	void AfisareMeniu();
	int ValidareOptiune(char option[]);
	char * ExitCode() {
		return "0";
	}
	char * ExitCode1() {
		return "x";
	}
	
};
