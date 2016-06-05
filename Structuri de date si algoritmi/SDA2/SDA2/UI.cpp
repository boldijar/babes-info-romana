#include "StdAfx.h"
#include "UI.h"


UI::UI(void)
{
	//aici am incarcat manual cativa clienti(pentru ca multimea sa nu fie vida in momentul rularii)
	
	ctr.adaugaController("1941104463080","Andreescu","David"); //hashcode 41,cod judet 46, se va pozitiona in tabela pe pozitia 11 [41 mod 30]mod30 = 11
	ctr.adaugaController("2921018468619","Marinescu","Simona"); //hashcode 57, cod judet 46, se va pozitiona in tabela pe pozitia 27 [57 mod 30]mod30 = 57
	ctr.adaugaController("1890408065807","Ardelean","Mihai");//hascode 56,cod judet 06, se va pozitiona in tabela pe pozitia 26 [56 mod 30]mod30 = 26
	ctr.adaugaController("2950418335906","Vama","Monica"); //hascode 55 ,cod judet 33,se va pozitiona in tabela pe pozitia 25 [55 mod 30]mod30 = 25
	ctr.adaugaController("1950417335926","Muresan","Adrian");//hascode 55 ,cod judet 35,se va pozitiona in tabela pe pozitia 28 [55 mod 30]mod30 = 25(apoi merge pana gaseste o pozitie libera-ea este 28)
	system("cls");
}
void UI::afisareTotUi(){

	
	ctr.afisareTot();
}

void UI::afisareJud(){
	cout << "Introduceti cele doua cifre specifice judetului: "<<endl;
						char c[10];
						cin>>c;
						int i = atoi(c);
						while(i<1 || i> 99 || strlen(c) != 2){
								cout << "Introduceti un numar din 2 cifre pentru a afla judetul: ";
								cin>>c;
								i = atoi(c);
							}	
	
	ctr.afisareDupaJudet(c);
}
void UI::afisareS(){
	cout << "Introduceti cifra corespunzatoare sexului(1=Barbat,2=Femeie): "<<endl;
						char c[10];
						cin>>c;
						int i = atoi(c);
						while(i<1 || i> 2 || strlen(c) != 1){
								cout << "Introduceti 1 sau 2: ";
								cin>>c;
								i = atoi(c);
							}	
	
	ctr.afisareDupaSex(c);
}
void UI::adaugaUi() {
	string cnp;
	string nume;
	string prenume;
	
	
	cout<< "Introduceti CNP-ul: ";  cin >> cnp; cout<<endl;

	cout<< "Introduceti numele: ";  cin >> nume; cout<<endl;
	
	cout<< "Introduceti prenumele: ";  cin >> prenume; cout<<endl;
	
	
	ctr.adaugaController(cnp,nume,prenume);
	
	
}




void UI::stergeUi() {
	string cnp;

	cout<< "Introduceti CNP-ul persoanei de sters: ";  cin >> cnp; cout<<endl;
	if (ctr.cautaController(cnp)==-1) cout<<"Persoana cu CNP-ul cerut nu a fost gasita pentru sters" <<endl<<endl;
		else 
			cout<<"Persoana cu CNP-ul  "<<cnp <<" a fost stearsa"<<endl<<endl;
	ctr.stergeController(cnp);
	
}

void UI::cautaUi() {
	string cnp;

	cout<< "Introduceti CNP-ul pe care doriti sa-l cautati: ";  cin >> cnp; cout<<endl;
	
	if (ctr.cautaController(cnp)==-1) cout<<"Persoana cu CNP-ul cerut nu este in lista" <<endl<<endl;
		else 
			cout<<"Persoana cu CNP-ul cerut este in lista pe positia "<<ctr.cautaController(cnp) <<endl<<endl;
}


void UI::AfisareMeniu1() {
	cout << "    ___Baza date___   " << endl;
	cout << "1.Adauga un nou client: ";
	cout << endl;
	cout << "2.Sterge un client: ";
	cout << endl;
	cout << "3.Cauta un client: ";
	cout << endl;
	cout << "4.Afisari: ";
	cout << endl;
	cout << "0.Exit ";

}
void UI::AfisareMeniu2() {
	cout << "a.Afisare toti clientii: ";
		cout << endl;
	cout << "b.Afisare dupa sex: ";
		cout << endl;
	cout << "c.Afisare dupa judetul nasterii: ";
		cout << endl;
	cout << "x.Revenire in meniul principal: ";
		cout << endl;

}


void UI::RuleazaMeniu(){
	char option[30] = "-1";
	
	while(strcmp(option,ExitCode()) != 0)
	{ 
		AfisareMeniu1();
		cin >> option;

		if (strcmp(option,"1") == 0)
			adaugaUi();
		if (strcmp(option,"2") == 0)
			stergeUi();
		if (strcmp(option,"3") == 0)
			cautaUi();
		
		if (strcmp(option,"4") == 0) 
			while(strcmp(option,ExitCode1()) != 0) {
				AfisareMeniu2();

				cin >> option;
				
				if (strcmp(option,"a") == 0)
					afisareTotUi();
				if (strcmp(option,"b") == 0)
					afisareS();
				if (strcmp(option,"c") == 0) 
						afisareJud();
					
				
			}
		}

	}

UI::~UI(void)
{
}
