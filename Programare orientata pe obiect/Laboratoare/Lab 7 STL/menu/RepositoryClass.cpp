#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include "string.h"
#include "RepositoryClass.h"
#include "DomainClass.h"

using namespace std;

RepositoryClass::RepositoryClass(void)
{
}

void RepositoryClass::loadFromFlie(vector<DomainClass> & lista) {
	/*
	Iau elementele de tip cheltuiala din fisier si le pun in
	lista 
	*/
	int id;
	int number;
	float amount;
	char type[10];
	ifstream fin("expenses.txt");
	
	char c2;
	int i = 1;
	do{
		fin >> id >> number >> amount >> type;
		c2 = fin.peek();
		lista.push_back (DomainClass::DomainClass(id,number,amount,type));
	}while(c2 == '\n');
	//imi pune tot timpul un caracter in plus asa ca il fac gol si scad iter
	lista.pop_back ();
				
	fin.close();	
}

void RepositoryClass::saveInFile(vector<DomainClass> & lista) {
	ofstream fout("expenses.txt");

	for (std::vector<DomainClass>::iterator i = lista.begin() ; i != lista.end(); ++i)
		fout<<(*i).getId()<<" "<<(*i).getNumber()<<" "<<(*i).getAmount()<<" "<< (*i).getType()<<'\n';
		
	fout.close();
}

RepositoryClass::~RepositoryClass(void)
{	
}
