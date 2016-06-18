
#include "examen.h"
#include <qmessagebox.h>
#include "FereastraProfesor.h"
examen::examen(Repository repo,bool profesor,string numeProf,QWidget *parent)
	: QMainWindow(parent)
{
	this->repository = repo;
	this->profesor = profesor;
	this->numeProf = numeProf;
	ui.setupUi(this);
	design();
	events();
	startup();
}

examen::~examen()
{

}


void examen::design() {
	if (!profesor)
	{
		mRootLayout = new QVBoxLayout(centralWidget());
		setLayout(mRootLayout);

		mSearch = new QTextEdit();
		mRootLayout->addWidget(mSearch);

		mListWidget = new QListWidget();
		mRootLayout->addWidget(mListWidget);

		mStudent = new QTextEdit();
		mRootLayout->addWidget(mStudent);
		mProfesor = new QTextEdit();
		mRootLayout->addWidget(mProfesor);
		mNota = new QTextEdit();
		mRootLayout->addWidget(mNota);

		mButton = new QPushButton("Adauga");
		mRootLayout->addWidget(mButton);
	}else{
		mRootLayout = new QVBoxLayout(centralWidget());
		setLayout(mRootLayout);

		mListWidget = new QListWidget();
		mRootLayout->addWidget(mListWidget);
	}
}

void examen::events()
{
	if (!profesor)
	{
		QObject::connect(mButton, &QPushButton::pressed, this, &examen::onButtonClick);
		QObject::connect(mSearch, &QTextEdit::textChanged, this, &examen::schimbareSearch);
	}
}

void examen::actualizeazaLista(vector<Nota> note)
{
	this->mListWidget->clear();
	for (Nota nota : note)
	{
		QString nume = QString::fromStdString(nota.numeStudent);
		QString profesor = QString::fromStdString(nota.numeProfesor);

		QString text = QString("Student: %1, Profesor: %2, Nota %3").arg(nume).arg(profesor).arg(nota.nota);
		mListWidget->addItem(text);
	}

}

void examen::startup()
{
	if(!profesor)
	actualizeazaLista(repository.sortate());
	else
	{
		actualizeazaLista(repository.cautaNoteleProfesorului(numeProf));
	}
}
void examen::onButtonClick()
{
	 
	string name = mStudent->toPlainText().toStdString();
	string profesor = mProfesor->toPlainText().toStdString();
	float nota=mNota->toPlainText().toFloat();
	bool adaugat = repository.addNote(name, nota, profesor);
	if (adaugat)
	{
		QMessageBox *messageBox = new QMessageBox;
		messageBox->setText("Am adaugat boss!");
		messageBox->exec();
		actualizeazaLista(repository.sortate());
		repository.salveaza();
		for (examen* ex : actualizabili) {
			ex->actualizare();
		}
	}
	else {
		QMessageBox *messageBox = new QMessageBox;
		messageBox->setText("Boss din pacate datele introduse sunt invalide.");
		messageBox->exec();
	}
}

void examen::schimbareSearch()
{
	actualizeazaLista(repository.cauta(mSearch->toPlainText().toStdString()));
}

void examen::actualizare()
{
	repository.incarca();
	actualizeazaLista(repository.cautaNoteleProfesorului(numeProf));
}


