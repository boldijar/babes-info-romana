#include "Repository.h"
#include <fstream>


Repository::Repository()
{
}


Repository::~Repository()
{
}

bool Repository::addNote(string nume, float nota, string profesor)
{
	{
		if (nume.length() == 0 || profesor.length() == 0 || nota < 0 || nota > 10)
		{
			return false;
		}
		for (Nota nota : note)
		{
			if (nota.numeStudent.compare(nume) == 0)
			{
				return false;
			}
		}
		note.push_back(Nota(nume, profesor, nota));
		return true;
	}
}

vector<Nota> Repository::cauta(string nume)
{
	vector<Nota> noteSortate = sortate();

	if (nume.length() == 0)
	{
		return noteSortate;
	}
	vector<Nota> newNote;

	for (Nota nota : noteSortate)
	{
		if (nota.numeStudent.find(nume) != string::npos)
		{
			newNote.push_back(nota);
		}
	}
	return newNote;
}

void Repository::incarca()
{
	ifstream f("note.txt");
	string nume, profesor;
	float nota;
	while (f >> nume)
	{
		f >> profesor;
		f >> nota;
		addNote(nume, nota, profesor);
	}
	f.close();
}

vector<Nota> Repository::sortate()
{
	vector<Nota> noteNoi(this->note);
	for(int i=0; i<noteNoi.size()-1; i++)
		for (int j = i + 1; j < noteNoi.size(); j++)
		{
			if (noteNoi[i].nota > noteNoi[j].nota)
			{
				Nota aux = noteNoi[i];
				noteNoi[i] = noteNoi[j];
				noteNoi[j] = aux;
			}
		}
	return noteNoi;
}

void Repository::salveaza()
{
	ofstream f("note.txt");
	for (Nota nota : this->note)
	{
		f << nota.numeStudent << endl << nota.numeProfesor <<endl<< nota.nota << endl;
	}
	f.close();
}

vector<string> Repository::profesori()
{
	vector<string> profi;
	for (Nota nota : this->note)
	{
		bool gasit = false;
		for (string prof : profi)
		{
			if (nota.numeProfesor.compare(prof) == 0)
			{
				gasit = true;
			}

		}
		if (!gasit)
		{
			profi.push_back(nota.numeProfesor);
		}
	}
	return profi;
}

vector<Nota> Repository::cautaNoteleProfesorului(string profesor)
{
	 vector<Nota> noteNoi;
	 for (Nota nota : this->note)
	 {
		 if (profesor.compare(nota.numeProfesor) == 0)
		 {
			 noteNoi.push_back(nota);
		 }
	 }
	 return noteNoi;
}
