#include "stdafx.h"
#include "string.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include "MenuClass.h"
#include "ControllerClass.h"
#include "RepositoryClass.h"
#include "DomainClass.h"
#include "Except.h"
#include "ValidatorClass.h"
using namespace std;

MenuClass::MenuClass(void)
{
}
//char types[] = {"water"};//, "heating", "lighting", "gas", "others"};

void MenuClass::addUi() {
	char idd[10];
	int id;
	char numberr[10];
	int  number ;
	char amountt[10];
	float amount;
	char type[10];
	ValidatorClass val;
	
	cout<< "Introduceti id-ul: ";  cin >> idd; cout<<endl;
	id = std::atoi(idd);
	val.validareId(id);
	
	cout<< "Introduceti numarul: ";  cin >> numberr; cout<<endl;
	number = std::atoi(numberr);
	val.validareNumar(number);
	
	cout<< "Introduceti suma: ";  cin >> amountt; cout<<endl;
	amount = std::atof(amountt);
	val.validareSuma(amount);

	cout<< "Introduceti tipul cheltuielii: ";  cin >> type; cout<<endl;
	while(strcmp(type,"water") != 0 && strcmp(type,"heating") != 0 && strcmp(type,"lighting") != 0 && strcmp(type,"gas") != 0 && strcmp(type,"others") != 0 ) {
		cout << "Tipul cheltuielii nu este corspunzator.Repetati introducerea tipului:" << endl;
		cin >> type; cout<<endl;
	}
	ControllerClass ctr;
	ctr.add(id,number,amount,type);
}

void MenuClass::updateUi() {
	char idd[10];
	int id;
	char numberr[10];
	int  number ;
	char amountt[10];
	float amount;
	char type[10];
	ValidatorClass val;
	
	cout<< "Introduceti id-ul: ";  cin >> idd; cout<<endl;
	id = std::atoi(idd);
	val.validareId(id);
	
	cout<< "Introduceti numarul: ";  cin >> numberr; cout<<endl;
	number = std::atoi(numberr);
	val.validareNumar(number);
	
	cout<< "Introduceti suma: ";  cin >> amountt; cout<<endl;
	amount = std::atof(amountt);
	val.validareSuma(amount);

	cout<< "Introduceti tipul cheltuielii: ";  cin >> type; cout<<endl;
	while(strcmp(type,"water") != 0 && strcmp(type,"heating") != 0 && strcmp(type,"lighting") != 0 && strcmp(type,"gas") != 0 && strcmp(type,"others") != 0 ) {
		cout << "Tipul cheltuielii nu este corspunzator.Repetati introducerea tipului:" << endl;
		cin >> type; cout<<endl;
	}
	ControllerClass ctr;
	ctr.updateController(id,number,amount,type);
}

void MenuClass::deleteUi() {
	ValidatorClass val;
	int  id ;
	char idd[10];
	cout<< "Introduceti id-ul: ";  cin >> idd; cout<<endl;
	id = std::atoi(idd);
	val.validareId(id);
	
	ControllerClass ctr;
	ctr.deleteController(id);
}

void MenuClass::filterAmountUi() {
	int  amount ;
	char amountt[10];
	ValidatorClass val;
	cout<< "Introduceti suma: ";  cin >> amountt; cout<<endl;
	amount = std::atoi(amountt);
	val.validareSuma(amount);
	
	ControllerClass ctr;
	ctr.filterAmountController(amount);
}

void MenuClass::filterTypeUi(){
	char type[10];
	
	cout << "Introduceti tipul: "; cin >> type; cout << endl;
	
	ControllerClass ctr;
	ctr.filterTypeController(type);
}

void MenuClass::sortAmountUi() {
	DynamicList lista;
	
	ControllerClass ctr;
	ctr.sortAmountController(lista);
	for (int i = 0; i < lista.getLength(); ++i) {
		lista[i].print() ;
		cout << endl;
	}
}

void MenuClass::sortAmountUiDesc() {
	DynamicList lista;
	
	ControllerClass ctr;
	ctr.sortAmountControllerDesc(lista);
	for (int i = 0; i < lista.getLength(); ++i) {
		lista[i].print() ;
		cout << endl;
	}
}
void MenuClass::sortTypeUi() {
	DynamicList lista;
	ControllerClass ctr;
	ctr.sortTypeController(lista);
	for (int i = 0; i < lista.getLength(); ++i) {
		lista[i].print();
		cout << endl;
	}
}

void MenuClass::sortTypeUiDesc() {
	DynamicList lista;
	
	ControllerClass ctr;
	ctr.sortTypeControllerDesc(lista);
	for (int i = 0; i < lista.getLength(); ++i) {
		lista[i].print() ;
		cout << endl;
	}
}

void MenuClass::afisareMeniu() {
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
int MenuClass::validareOptiune(char option[]){
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

void MenuClass::ruleazaMeniu(){
	char option[30] = "-1";
	DynamicList ll;
	
	ll.testDelete();
	ll.testUpdate();
	ll.testAppend();
	ValidatorClass v;
	v.testValidatori();
	while(strcmp(option,ExitCode()) != 0){ 
		afisareMeniu();
		cin >> option;
		try {
			if (validareOptiune(option) == 0)
				cout<<"data introdusa e invalida"<<endl;	
			if (strcmp(option,"1") == 0)
				addUi();
			if (strcmp(option,"2") == 0)
				updateUi();
			if (strcmp(option,"3") == 0)
				deleteUi();
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
					if (validareOptiune(option) == 0)
						cout<<"data introdusa e invalida"<<endl;
					if (strcmp(option,"A") == 0)
						sortAmountUi();
					if (strcmp(option,"B") == 0)
						sortTypeUi();
					if (strcmp(option,"C") == 0)
						sortTypeUiDesc();
					if (strcmp(option,"D") == 0)
						sortAmountUiDesc();
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
					if (validareOptiune(option) == 0)
						cout<<"data introdusa e invalida"<<endl;
					if (strcmp(option,"a") == 0)
						filterAmountUi();
					if (strcmp(option,"b") == 0)
						filterTypeUi();
				}
			}
		}
		catch(Except& e){
			cout << e.what() << endl;
			std::ofstream outfile;
			outfile.open("Erori.txt", std::ios_base::app);
			outfile << e.what() <<endl; 
		}
	}
}


MenuClass::~MenuClass(void)
{
}
