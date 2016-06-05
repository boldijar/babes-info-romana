/*
 * ui.cpp
 *
 *  Created on: 07.06.2012
 *      Author: Emilian
 */

#include "ui.h"

Ui::Ui(Hotel *hotel){
	repo = hotel;
}

/*destructor, elibereaza memoria folosita*/
Ui::~Ui(){
	//repo->~Hotel();
	delete (repo);
}

/*afiseaza meniul si preia comanda*/
void Ui::showMenu(){
	char cmd;
	do{
		cout << "receptie hotel\n";
		cout << "1. Gazduire client nou;\n";
		cout << "2. Plecare client;\n";
		cout << "3. Clientii dintr-o camera;\n";
		cout << "4. Camerele pline\n";
		cout << "5. vezi dictionarul reprezentat pe tabela\n";
		cout << "0. Iesire";
		cin >> cmd;

		this->execMenu(cmd);
		cin.ignore(3,'\n');
	}while(cmd != '0');
}

/*executa comanda primita de la meniu*/
void Ui::execMenu(char cmd){
	int camera;
	string nume;
	int nr;
	int camere[M];
	string clienti[M];

	switch (cmd){

		case '1':{ //gazduire client nou

			cout << "alegeti o camera in care va fi cazat clientul ";
			nr = repo->pline(camere);
			if (nr){
				cout << "(camerele ";
				for (int i = 0; i < nr; i++){
					cout << camere[i] << " ";
				}
				cout << " sunt pline) \n";
			}
			cin >> camera;

			cout << "dati numele clientului ";
			cin >> nume;
			if ( repo->exist(camera, nume) ){
				cout << "acest client a fost inregistrat anterior \n\n";
				break;
			}
			if ( repo->add(camera, nume) )
				cout << " adaugare reusita \n\n";
			else cout << "adaugarea nu s-a efectuat ( probabil camera plina ) \n\n";

			break;
		}

		case '2':{// plecare client

			cout << "dati camera in care e cazat clientul care va pleca ";
			cin >> camera;

			cout << "dati numele clientului care va pleca ";
			cin >> nume;

			if ( repo->exist(camera,nume) == false ){
				cout << " nu exista acest client in acea camera \n\n";
				break;
			}

			repo->leave(camera,nume);
			cout << " clientul a mers in drumul lui, parasind hotelul nostru :) \n\n";
			break;
		}

		case '3':{//clientii dintr-o camera
			cout << "dati camera: ";
			cin >> camera;
			if ( repo->cameraOcupata(camera) ){
				nr = repo->oameniCamera(camera,clienti);
			}
			else {
				cout << "nu sunt clienti gazduiti in aceasta camera \n\n";
				break;
			}
			cout << " clientii gazduiti din camera " << camera << " : ";
			for (int i = 0;i < nr; i++)
				cout << clienti[i] << "  ";
			cout << endl << endl;

			break;
		}

		case '4':{//camerele pline
			cout << " ( numarul de locuri intr-o camera e " << K << " ) \n";
			nr = repo->pline(camere);
			if ( nr == 0 ){
				cout << "nu exista camere pline \n\n";
				break;
			}
			cout << " camerele pline: ";
			for ( int i = 0; i < nr; i++){
				cout << camere[i] << "  ";
			}
			cout << endl << endl;

			break;
		}

		case '5':{//vezi tabela
			int i;
			repo->it->prim();
			if(repo->it->valid())
				while (repo->it->valid()){
					i = repo->it->getCurent();
					cout << "pozitia " << i << " : ";
					cout << "  " << repo->it->getCheie(i) << "  " << repo->it->getValoare(i) << "  " << repo->it->getUrm(i) << endl;
					repo->it->urmator();
				}
			else cout << "dict si tabela sunt vide ";
			break;
		}
		case '0':{//exit
			return;
			break;
		}
		default:{
			cout << "introduceti o comanda existenta! \n\n";
			break;
		}
	}
}


