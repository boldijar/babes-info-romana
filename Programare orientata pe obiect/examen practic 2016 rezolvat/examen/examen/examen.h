#ifndef EXAMEN_H
#define EXAMEN_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets\QPushButton>
#include <QVBoxLayout>
#include <qlistwidget.h>
#include "ui_examen.h"
#include "Repository.h"
#include <QtWidgets\qtextedit.h>
#include "Actualizabil.h"
class examen : public QMainWindow, Actualizabil
{
	Q_OBJECT

private:
	bool profesor = false;
	string numeProf;
	vector<examen*> actualizabili;
public:
	void setAct(vector<examen*> act) {
		this->actualizabili = act;
	}
	examen(Repository repo,bool profesor = false,string numeProf = "",QWidget *parent = 0);
	~examen();

	/* pregateste designul aplicatiei*/
	void design();
	/* pregateste eventele aplicatiei*/
	void events();
	/* adauga notele sortate in lista*/
	void actualizeazaLista(vector<Nota> note);
	/* pregateste logica aplicatiei 8| */
	void startup();
	/*  add clicked*/
	void onButtonClick();
	/* search text s a schimbat*/
	void schimbareSearch();

	void actualizare();

private:
	Repository repository;
	Ui::examenClass ui;
	QVBoxLayout *mRootLayout;
	QTextEdit *mSearch;
	QPushButton *mSearchButton;
	QListWidget *mListWidget;
	QTextEdit *mStudent;
	QTextEdit *mProfesor;
	QTextEdit *mNota;
	QPushButton *mButton;

};

#endif // EXAMEN_H
