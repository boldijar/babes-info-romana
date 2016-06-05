// meniu.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "string.h"
#include <iostream>
#include "MenuClass.h"
#include "DomainClass.h"
#include "RepositoryClass.h"
#include "ControllerClass.h"
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{	
	MenuClass* meniu = new MenuClass();
	meniu->RuleazaMeniu();
	/*
	DomainClass* alor = new DomainClass();
	char a[] = "abcd";
	alor->DomainClass::DomainClass(4,78.45,a);
	alor->Print();
	*/
	//DomainClass* bb = new DomainClass();
	//bb->DomainClass::DomainClass(100,20.45,"zz");
	//bb->Print();
	//cout << bb->GetType();


	//RepositoryClass c ;
	//c.RepositoryClass::LoadFromFlie();
	//c.RepositoryClass::SaveInFile();

	//AddUi();
	
	//int p;
	//cin>>p;
	//meniu->AfisareMeniu(); - o sa dea cannot acces private member
	return 0;
}
