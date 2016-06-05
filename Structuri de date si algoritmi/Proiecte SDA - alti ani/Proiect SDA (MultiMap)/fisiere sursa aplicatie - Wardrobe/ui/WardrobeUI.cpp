/*
 * WardrobeUI.cpp
 *
 *  Created on: 28.06.2012
 *      Author: Cristian Mihok
 */

#include "WardrobeUI.h"

WardrobeUI::WardrobeUI(Wardrobe *wardrobe){
	wRepository = wardrobe;
}


WardrobeUI::~WardrobeUI(){
	delete (wRepository);
}


void WardrobeUI::showMenu(){
	char enter;
	do{
		cout << "** Garderoba **\n";
		cout << "1. Adauga obiect\n";
		cout << "2. Returnare obiect;\n";
		cout << "3. Obiecte pe cheie;\n";
		cout << "4. OBIECT x CHEIE pe TAD MULTIMAP\n";
		cout << "0. Exit\n\n";
		cout << "enter: ";
		cin >> enter;

		this->run(enter);
		cin.ignore(3,'\n');
	}while(enter != '0');
}


void WardrobeUI::run(char enter){
	int cheie;
	string obiect;
	int nr;
	int chei[MAX];
	string obiecte[MAX];

	switch (enter){

		case '1':{

			cout << "cheie:  ";
			nr = wRepository->pline(chei);

			cin >> cheie;

			cout << "obiect:  ";
			cin >> obiect;

			if ( wRepository->adauga(cheie, obiect) )
				cout << "!! obiect adaugat !!\n\n";
			else cout << "adaugarea nu s-a efectuat ( probabil cheie plina ) \n\n";

			break;
		}

		case '2':{

			cout << "cheia: ";
			cin >> cheie;

			cout << "obiect cerut: ";
			cin >> obiect;

			if ( wRepository->exista(cheie,obiect) == false ){
				cout << "!! obiect inexistent !!\n\n";
				break;
			}

			wRepository->returneaza(cheie,obiect);
			cout << "!! obiect returnat !!\n\n";
			break;
		}

		case '3':{
			cout << "cheie: ";
			cin >> cheie;
			if ( wRepository->cheieOcup(cheie) ){
				nr = wRepository->nrObiectePeCheie(cheie,obiecte);
			}
			else {
				cout << "!! cheie goala !!\n\n";
				break;
			}
			cout << " obiecte de pe cheia " << cheie << " : ";
			for (int i = 0;i < nr; i++)
				cout << obiecte[i] << "  ";
			cout << endl << endl;

			break;
		}



		case '4':{
			int i;
			wRepository->it->first();
			if(wRepository->it->valid())
				while (wRepository->it->valid()){
					i = wRepository->it->getCurent();
					cout << "index " << i << " : ";
					cout << "  " << wRepository->it->getKey(i) << "  " << wRepository->it->getValue(i) << "  " << wRepository->it->getNext(i) << endl;
					wRepository->it->next();
				}
			else cout << "!! vid !!";
			break;
		}
		case '0':{//exit
			return;
			break;
		}
		default:{
			cout << "!! comanda inexistenta !!\n\n";
			break;
		}
	}
}


