#include "stdafx.h"
#include "string.h"
#include <iostream>

using namespace std;
#include "MenuClass.h"
#include "ControllerClass.h"

MenuClass::MenuClass(void)
{
}
//char types[] = {"water"};//, "heating", "illuminat", "gas", "others"};

void MenuClass::AddUi() {

	int id;
	int  number ;
	float amount;
	char type[10];
	cout<< "Introduceti id-ul: ";  cin >> id; cout<<endl;
	cout<< "Introduceti numarul: ";  cin >> number; cout<<endl;
	cout<< "Introduceti suma: ";  cin >> amount; cout<<endl;
	cout<< "Introduceti tipul cheltuielii: ";  cin >> type; cout<<endl;
	while(strcmp(type,"water") != 0 && strcmp(type,"heating") != 0 && strcmp(type,"illuminat") != 0 && strcmp(type,"gas") != 0 && strcmp(type,"others") != 0 ) {
		cout << "Tipul cheltuielii nu este corspunzator.Repetati introducerea tipului:" << endl;
		cin >> type; cout<<endl;
	}
	ControllerClass ctr;
	ctr.Add(id,number,amount,type);
}

void MenuClass::UpdateUi() {
	int id;
	int  number ;
	float amount;
	char type[10];
	cout<< "Introduceti id-ul: ";  cin >> id; cout<<endl;
	cout<< "Introduceti numarul: ";  cin >> number; cout<<endl;
	cout<< "Introduceti suma: ";  cin >> amount; cout<<endl;
	cout<< "Introduceti tipul cheltuielii: ";  cin >> type; cout<<endl;
	while(strcmp(type,"water") != 0 && strcmp(type,"heating") != 0 && strcmp(type,"illuminat") != 0 && strcmp(type,"gas") != 0 && strcmp(type,"others") != 0 ) {
		cout << "Tipul cheltuielii nu este corspunzator.Repetati introducerea tipului:" << endl;
		cin >> type; cout<<endl;
	}
	ControllerClass ctr;
	ctr.UpdateController(id,number,amount,type);
}

void MenuClass::DeleteUi() {

	int  id ;
	cout<< "Introduceti id-ul: ";  cin >> id; cout<<endl;
	ControllerClass ctr;
	ctr.DeleteController(id);
}

void MenuClass::FilterAmountUi() {

	float  amount ;
	cout<< "Introduceti suma: ";  cin >> amount; cout<<endl;
	ControllerClass ctr;
	ctr.FilterAmountController(amount);
}
void MenuClass::FilterTypeUi(){

	char type[10];
	
	cout << "Introduceti tipul: "; cin >> type; cout << endl;
	
	ControllerClass ctr;
	ctr.FilterTypeController(type);
	//cout<<type;
}
void MenuClass::SortAmountUi() {
	DomainClass lista[100];
	int iter;
	ControllerClass ctr;
	ctr.SortAmountController(lista,iter);
	for (int i = 1; i <= iter; ++i) {
		lista[i].Print() ;
		cout << endl;
	}
}

void MenuClass::SortAmountUiDesc() {
	DomainClass lista[100];
	int iter;
	ControllerClass ctr;
	ctr.SortAmountControllerDesc(lista,iter);
	for (int i = 1; i <= iter; ++i) {
		lista[i].Print() ;
		cout << endl;
	}
}
void MenuClass::SortTypeUi() {

	DomainClass lista[100];
	int iter;
	ControllerClass ctr;
	ctr.SortTypeController(lista,iter);
	for (int i = 1; i <= iter; ++i) {
		lista[i].Print() ;
		cout << endl;
	}
}
void MenuClass::SortTypeUiDesc() {

	DomainClass lista[100];
	int iter;
	ControllerClass ctr;
	ctr.SortTypeControllerDesc(lista,iter);
	for (int i = 1; i <= iter; ++i) {
		lista[i].Print() ;
		cout << endl;
	}
}

void MenuClass::AfisareMeniu() {
	cout << "    ___Block Administrator___   " << endl;
	cout << "1.New expense: ";
	cout << endl;
	cout << "2.Modify expense: ";
	cout << endl;
	cout << "3.Delete expense: ";
	cout << endl;
	cout << "4.Filter expenses: ";
	cout << endl;
	cout << "5.Sort expenses: ";
	cout << endl;
	cout << "0.Exit ";

}
int MenuClass::ValidareOptiune(char option[]){
	if (strcmp(option, "1") == 0)
		return 1;

	if (strcmp(option, "2") == 0)
		return 1;

	if (strcmp(option, "0") == 0)
		return 1;

	if (strcmp(option, "3") == 0)
		return 1;

	if (strcmp(option, "4") == 0)
		return 1;

	if (strcmp(option, "5") == 0)
		return 1;

	if (strcmp(option, "a") == 0)
		return 1;

	if (strcmp(option, "b") == 0)
		return 1;

	if (strcmp(option, "A") == 0)
		return 1;

	if (strcmp(option, "B") == 0)

		return 1;
	if (strcmp(option, "C") == 0)
		return 1;
	if (strcmp(option, "D") == 0)
		return 1;
	if (strcmp(option, "x") == 0)
		return 1;
	return 0;

}

void MenuClass::RuleazaMeniu(){
	char option[30] = "-1";
	while(strcmp(option,ExitCode()) != 0)
	{ 
		AfisareMeniu();
		cin >> option;
		if (ValidareOptiune(option) == 0)
			cout<<"data introdusa e invalida"<<endl;	
		if (strcmp(option,"1") == 0)
			AddUi();
		if (strcmp(option,"2") == 0)
			UpdateUi();
		if (strcmp(option,"3") == 0)
			DeleteUi();
		if(strcmp(option,"5") == 0) {
			while(strcmp(option,ExitCode1()) != 0) {
				cout << "A.Sort by amount ascendent: ";
				cout << endl;
				cout << "B.Sort by expense type ascendent: ";
				cout << endl;
				cout << "C.Sort by expense type descendent: ";
				cout << endl;
				cout << "D.Sort by amount descendent: ";
				cout << endl;
				cout << "x.Exit in principal menu: ";
				cout << endl;

				cin >> option;
				if (ValidareOptiune(option) == 0)
					cout<<"data introdusa e invalida"<<endl;
				if (strcmp(option,"A") == 0)
					SortAmountUi();
				if (strcmp(option,"B") == 0)
					SortTypeUi();
				if (strcmp(option,"C") == 0)
					SortTypeUiDesc();
				if (strcmp(option,"D") == 0)
					SortAmountUiDesc();
			}
			
		}
		if (strcmp(option,"4") == 0) {
			while(strcmp(option,ExitCode1()) != 0) {
				cout << "a.Filter by amount(grather than): ";
				cout << endl;
				cout << "b.Filter by expense type: ";
				cout << endl;
				cout << "x.Exit in principal menu: ";
				cout << endl;

				cin >> option;
				if (ValidareOptiune(option) == 0)
					cout<<"data introdusa e invalida"<<endl;
				if (strcmp(option,"a") == 0)
					FilterAmountUi();
				if (strcmp(option,"b") == 0)
					FilterTypeUi();
			}
		}
	}

}


MenuClass::~MenuClass(void)
{
}
