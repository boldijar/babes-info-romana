#include "StdAfx.h"
#include "Ui.h"
#include<iostream>

using namespace std;

Ui::Ui(void)
{
}

void Ui::afisareUi(){
	mr.afisareMatrice();
}


void Ui::adaugaUi(){
	int linie, coloana, valoare;
	cout << "linia: "; cin >> linie;
	cout << "coloana: "; cin >> coloana;
	cout << "valoare: "; cin >> valoare;
	mr.adaugaMatrice(TElement(linie,coloana,valoare));
	cout<<"Casa adaugata cu succes spre vanzare"<<endl;
}

void Ui::modificaUi(){
	int linieVeche, coloanaVeche, valoareVeche, valoareNoua;
	cout << "linia veche: "; cin >> linieVeche;
	cout << "coloana veche: "; cin >> coloanaVeche;
	cout << "valoarea veche: "; cin >> valoareVeche;
	cout << "valoarea noua: "; cin >> valoareNoua;
	TElement element(linieVeche, coloanaVeche, valoareVeche);
	mr.modificareMatrice(element, valoareNoua);
	cout << "Valoarea casei a fost modificata" << endl;
}

void Ui::stergeUi(){
	int linie, coloana, valoare;
	cout << "linia: "; cin >> linie;
	cout << "coloana: "; cin >> coloana;
	cout << "valoarea: "; cin >> valoare;
	TElement element(linie,coloana,valoare);
	mr.stergeMatrice(element);
	cout<<"Casa a fost vanduta"<<endl;
}

void Ui::afisareMeniu(){
	cout<<"-------Cartier rezidential-------"<<endl;
	cout<<"1. Afisare case de vanzare"<<endl;
	cout<<"2. Adauga o casa spre vanzare"<<endl;
	cout<<"3. Modifica pretul unei case"<<endl;
	cout<<"4. Vinde o casa"<<endl;
	cout<<"0. Iesire"<<endl;
}

void Ui::ruleazaMeniu(){
	char optiune[5] = "-1";
	while(1){
		afisareMeniu();
		cin>>optiune;
		if (strcmp(optiune,"1") == 0)
			afisareUi();
		else if (strcmp(optiune,"2") == 0)
			adaugaUi();
		else if (strcmp(optiune,"3") == 0)
			modificaUi();
		else if (strcmp(optiune,"4") == 0)
			stergeUi();
		else if (strcmp(optiune,"0") == 0)
			break;
		else cout<<"Optiunea nu exista"<<endl;
	}
}


Ui::~Ui(void)
{
}
