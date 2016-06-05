#include "StdAfx.h"
#include "Controller.h"


Controller::Controller(void)
{
		
    it = mu.Itr();
	
}

void Controller::afisareTot() {
	//afiseaza toti clientii folosind un iterator
	bool  gasit=false;
	it = mu.Itr();
	do{
	
		if(it.valid() == true){
			it.element().print();
			gasit = true;
		}
	}while(it.urmator() == true);

	if(gasit == false ) cout << "Lista este goala" <<endl<<endl;	
}

void Controller::afisareDupaSex(char s[1]) {
	//sexul unei persoane este reprezentat de prima cifra din CNP
	//care este 1-barbati si 2-pentru femei
	it = mu.Itr();
	bool gasit=false;
	do{
	
		if(it.valid() == true && it.element().getCNP()[0] == s[0]) 
		{
			
			it.element().print();
			gasit = true;
		}
	}while(it.urmator() == true);
	if(gasit == false ) cout << "Nu s-au gasit persoane cu sexul cerut" <<endl<<endl;	
}
void Controller::afisareDupaJudet(char jud[2]) { 
	/*pre: functia primeste un string format din 2 cifre
	  post: stringul primit se compara cu a7-a si a8-a cifra dun CNP
			si daca sunt identice inseamna ca persona s-a nascut in judetul cerut*/
	it = mu.Itr();
	bool gasit=false;
	do{
		if(it.element().getCNP().length()>8)
			if(it.valid() == true && it.element().getCNP()[7] == jud[0] && it.element().getCNP()[8] == jud[1]) 
			{
			
				it.element().print();
				gasit=true;
			}
	}while(it.urmator() == true);

	if(gasit == false ) cout << "Nu s-au gasit persoane din judetul cerut" <<endl<<endl;	

}

void Controller::adaugaController(string cnp,string nume,string prenume) {
	//functia adaugaController apeleaza adaugarea din Multime
	TElement elem = TElement(cnp,nume,prenume);
	this->mu.adauga(elem);
	
}

int Controller::cautaController(string cnp){
	//functia cautaController apeleaza cautarea din Multime
	return this->mu.cauta(cnp);
}

void Controller::stergeController(string cnp){
	//functia cautaController apeleaza cautarea din Multime
	this->mu.sterge(cnp);
}



Controller::~Controller(void)
{
	
}
