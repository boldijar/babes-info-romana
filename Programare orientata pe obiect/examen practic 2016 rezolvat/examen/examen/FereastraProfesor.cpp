#include "FereastraProfesor.h"


#include "examen.h"
#include <qmessagebox.h>

FereastraProfesor::FereastraProfesor(string profesor,Repository repository,QWidget *parent)
	: QMainWindow(parent)
{
	this->profesor = profesor;
	this->repository = repository;
	ui.setupUi(this);
	design();
	events();
	startup();
}

FereastraProfesor::~FereastraProfesor()
{

}


void FereastraProfesor::design() {
	mRootLayout = new QVBoxLayout(centralWidget());
	setLayout(mRootLayout);
	 
	mListWidget = new QListWidget();
	mRootLayout->addWidget(mListWidget);

}

void FereastraProfesor::events()
{
}

void FereastraProfesor::actualizeazaLista()
{
	this->mListWidget->clear();
	vector<Nota> note = this->repository.cautaNoteleProfesorului(profesor);
	for (Nota nota : note)
	{
		QString nume = QString::fromStdString(nota.numeStudent);
		QString profesor = QString::fromStdString(nota.numeProfesor);

		QString text = QString("Student: %1, Profesor: %2, Nota %3").arg(nume).arg(profesor).arg(nota.nota);
		mListWidget->addItem(text);
	}

}

void FereastraProfesor::startup()
{
	repository.incarca();
	actualizeazaLista();
}
 