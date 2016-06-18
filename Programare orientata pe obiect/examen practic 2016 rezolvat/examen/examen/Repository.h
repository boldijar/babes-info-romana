#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Nota.h"
class Repository
{
private :
	vector<Nota> note;
public:
	Repository();
	~Repository();

	/* adauga o nota in lista, daca nu a mai fost deja studentul,
	si daca datele sunt valide*/
	bool addNote(string nume, float nota, string profesor);

	/* cauta toti studentii ce contin in numele caracterele din parametru
	daca e gol, returneaza tot*/
	vector<Nota> cauta(string nume);

	/* incarca notele din fisier */
	void incarca();

	/* returneaza toate notele sortate dupa valoare*/
	vector<Nota> sortate();

	/* salveaza repo in fisier */
	void salveaza();

	/* returneaza toti profesorii*/
	vector<string> profesori();

	/* returneaza notele pt profesorul cerut*/
	vector<Nota> cautaNoteleProfesorului(string profesor);
};

