#include "StdAfx.h"

#include <iostream>
#include <fstream>
#include "string.h"
//#include "DomainClass.h"

using namespace std;
#include "RepositoryClass.h"
#include "DomainClass.h"
DomainClass lista[100] ;

//DomainClass lista[100];


RepositoryClass::RepositoryClass(void)
{

}




void RepositoryClass::LoadFromFlie(DynamicList & lista) {
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
						lista.append(DomainClass::DomainClass(id,number,amount,type));
						
						//lista[i].Print();
					
	}while(c2 == '\n');
				//imi pune tot timpul un caracter in plus asa ca il fac gol si scad iter
				lista.deletePosition(lista.getLenght()-1);
				
		fin.close();
		
}


	
void RepositoryClass::SaveInFile(DynamicList & lista) {
	ofstream fout("expenses.txt");

	
	for (int i = 0;i < lista.getLenght()  ;++i)
		fout<<lista[i].GetId()<<" "<<lista[i].GetNumber()<<" "<<lista[i].GetAmount()<<" "<< lista[i].GetType()<<'\n';

	fout.close();
}





RepositoryClass::~RepositoryClass(void)
{
	
}
