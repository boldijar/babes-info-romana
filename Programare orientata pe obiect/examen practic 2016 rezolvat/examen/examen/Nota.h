#pragma once
using namespace std;
#include <iostream>
#include <string>
class Nota
{
public:
	Nota();
	Nota(string numeStudent, string numeProfesor, float nota) {
		this->numeStudent = numeStudent;
		this->numeProfesor = numeProfesor;
		this->nota = nota;
	}
	~Nota();
	string numeStudent;
	string numeProfesor;
	float nota;
};

