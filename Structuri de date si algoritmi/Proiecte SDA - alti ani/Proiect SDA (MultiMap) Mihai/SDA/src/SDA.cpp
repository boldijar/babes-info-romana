//============================================================================
// Name        : SDA.cpp
// Author      : mihai
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include "TElement.h"
#include "MultiDictionar.h"
using namespace std;

class App{
public:
	MultiDictionar *dict;
	MultiDictionarIterator *i;
	App(){
		this->dict = new MultiDictionar(10);
	}
	virtual ~App(){
		delete[]this->dict;
		delete[]this->i;
	}
	void teste(){
		/*TElement *a = new TElement("Alfabet","toate literele");
		TElement *b = new TElement("B","b");
		TElement *mic = a->cmp(b);
		cout <<a;
		cout<<this->dict->tabela[1].chei<<endl;;
		cout<<this->i->element();
		cout<<this->i->iterator<<endl;
		cout<<"ajunge aici";
		this->i->urmator();
		char *da[30];
		this->dict->chei(da);
		int dim=this->dict->dimensiune();
		for(int j=0;j<dim;j++)
			cout<<j<<" "<<da[j]<<"\n";
		cout<<"ajunge aici";
		MultiDictionar *md = new MultiDictionar;
		this->dict->perechi(md);
		for(int j=0;j<dim;j++)
			cout<<&md->tabela[j];*/

		TElement *a = new TElement("plfabet","toate literele");
		TElement *b = new TElement("Alfabet","toate literele din nou");
		string c1="pope";
		string c2="popea";
		string v1="m";
		string v2="b";
		cout<<a;
		dict->adauga(c1,v1);
		dict->adauga(c1,v2);
		dict->adauga(c2,v1);
		dict->adauga(c2,v2);
		dict->sterge(c1);
		/*cout<<j<<" ";
		cout<<&dict->tabela[j];
		//dict->adauga(b,j);
		cout<<j<<" ";
		cout<<&dict->tabela[j];*/


		MultiDictionar *md = new MultiDictionar(10);
		dict->perechi(md);
		int dim=this->dict->dimensiune();
		for(int k=0;k<dim;k++)
			cout<<&md->tabela[k];

		if(dict->cauta("popea"))
			cout<<"AM GASIT\n";
		else
			cout<<"NU AM GASIT\n";
	/*	string valorile[30];
		dict->valori(valorile);
		cout<<dim;
		for(int k=0;k<dim;k++)
			cout<<valorile[k]<<" ";*/


	}

	string validate(string cuv, string def)
	{
		string err;
		if(cuv.size()==0)
			err.append("Cuvantul introdus nu trebuie sa fie vid\n");
		if(def.size()==0)
			err.append("Definitia introdusa nu trebuie sa fie vida\n");
		return err;
	}
	void run()
	{
		cout<<"Dictionar de omonime. Puteti adauga noi cuvinte sau puteti cauta cuvinte.\n";
		while(1)
		{
			cout<<"Comenzi: adauga cauta afisare exit\n";
			string com;
			getline(cin,com);
			if(com.compare("adauga") == 0)
			{
				string cuv,def;
				cout<<"Introduceti cuvantul pe care doriti sa il adaugati in dictionar\n";
				getline(cin,cuv);
				cout<<"Introduceti definitia asociata acestui cuvant\n";
				getline(cin,def);
				if(this->validate(cuv,def).size() == 0)
					this->dict->adauga(cuv,def);
				else
					cout<<this->validate(cuv,def);

			}
			else
				if(com.compare("cauta") == 0)
				{
					string cuv;
					cout<<"Dati cuvantul pe care doriti sa-l cautati \n";
					getline(cin,cuv);
					if(this->dict->cauta(cuv)==0)
						cout<<"Cuvantul cautat nu exista in dictionar\n";
					else
					{
						cout<<"Definitii pentru "<<cuv<<" :\n";
						string val[30];
						int dim = 0;
						this->dict->valoriDupaCheie(val,cuv,dim);
						for(int j=0;j<dim;j++)
							cout<<val[j]<<"\n";
					}

				}
				else
					if(com.compare("afisare") == 0)
					{
						int dim=this->dict->dimensiune();
						MultiDictionar *md = new MultiDictionar(10);
						this->dict->perechi(md);
						for(int j=0;j<dim;j++)
							cout<<&md->tabela[j];
					}
					else
						if(com.compare("exit") == 0)
						{
							cout<<"Va multumim pentru utilizarea produsului nostru. O zi buna!\n";
							break;
						}
						else
							cout<<"Comanda introdusa nu este valida. Incercati din nou!\n";
		}
	}
};

int main() {
	App *console = new App();
	console->run();
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
