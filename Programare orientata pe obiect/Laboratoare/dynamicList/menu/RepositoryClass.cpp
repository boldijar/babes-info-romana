#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include "string.h"
#include "RepositoryClass.h"
#include "DomainClass.h"
using namespace std;

DomainClass lista[100] ;

RepositoryClass::RepositoryClass(void)
{
}

/*
	Iau elementele de tip cheltuiala din fisier si le pun in
	lista 
*/
void RepositoryClass::loadFromFlie(DynamicList & lista) {
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
		lista.append(DomainClass::DomainClass(id,number,amount,type));			
	}while(c2 == '\n');

	//imi pune tot timpul un caracter in plus asa ca il fac gol si scad iter
	lista.deletePosition(lista.getLength()-1);			
	fin.close();
}
	
void RepositoryClass::saveInFile(DynamicList & lista) {
	ofstream fout("expenses.txt");
	for (int i = 0;i < lista.getLength()  ;++i)
		fout<<lista[i].getId()<<" "<<lista[i].getNumber()<<" "<<lista[i].getAmount()<<" "<< lista[i].getType()<<'\n';
	fout.close();
}

RepositoryClass::~RepositoryClass(void)
{	
}
