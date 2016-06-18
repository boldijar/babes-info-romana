#include "examen.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include <assert.h>
#include "FereastraProfesor.h"

void runTest();
int main(int argc, char *argv[])
{
	runTest();
	QApplication a(argc, argv);

	Repository repo;
	repo.incarca();


	vector<examen*> exams;
	vector<examen*> actualizabili;

	exams.push_back(new examen(repo));
	vector<string> profi = repo.profesori();
	for (string prof : profi)
	{
		examen * ex = new examen(repo, true, prof);
		ex->setWindowTitle(QString::fromStdString(prof));
		exams.push_back(ex);
		actualizabili.push_back(ex);
	}
	exams[0]->setAct(actualizabili);
	for (examen *ex : exams)
	{
		ex->show();
	}
	
	
	return a.exec();
}

void runTest() {
	Repository r1;
	assert(r1.addNote("nume", 5, "prof"));
	assert(!r1.addNote("sal", -1, "prof"));
	assert(!r1.addNote("", 5, "prof"));
	assert(!r1.addNote("nume", 5, "prof"));

	Repository r2;
	r2.addNote("Dan", 5, "Istvan");
	r2.addNote("Danut", 5, "Istvan");
	r2.addNote("Vata", 5, "Istvan");
	assert(r2.cauta("").size() == 3);
	assert(r2.cauta("nicolae guta ft susanu").size() == 0);
	assert(r2.cauta("an").size() == 2);
	assert(r2.cauta("at").size() == 1);

	Repository r3;
	r3.addNote("Dan", 5, "Istvan");
	r3.addNote("Danut", 1, "Istvan");
	r3.addNote("Vata", 10, "Istvan");
	assert(r3.sortate()[0].nota == 1);
	assert(r3.sortate()[1].nota == 5);
	assert(r3.sortate()[2].nota == 10);

	Repository r4;
	r4.addNote("Paul", 5, "Istvan");
	r4.addNote("Dan", 6, "Istvan");
	r4.addNote("Alex", 7, "Juj");
	assert(r4.profesori().size() == 2);
	assert(r4.profesori()[0].compare("Istvan") == 0);
	assert(r4.profesori()[1].compare("Juj") ==0);
	assert(r4.cautaNoteleProfesorului("Istvan").size() == 2);
	assert(r4.cautaNoteleProfesorului("Istvan")[0].nota == 5);
	assert(r4.cautaNoteleProfesorului("Juj").size() == 1);
	assert(r4.cautaNoteleProfesorului("Florin Salam Unicu Idol").size()==0);

}
