#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets\QPushButton>
#include <QVBoxLayout>
#include <qlistwidget.h>
#include "ui_examen.h"
#include "Repository.h"
#include <QtWidgets\qtextedit.h>

class FereastraProfesor : public QMainWindow
{
	Q_OBJECT
private:
	string profesor;
	Repository repository;
public:
	FereastraProfesor(string profesor,Repository repository,QWidget *parent = 0);
	~FereastraProfesor();

	/* pregateste designul aplicatiei*/
	void design();
	/* pregateste eventele aplicatiei*/
	void events();
	/* adauga notele sortate in lista*/
	void actualizeazaLista();
	/* pregateste logica aplicatiei 8| */
	void startup();
	
private:
	Ui::examenClass ui;
	QVBoxLayout *mRootLayout;
	QListWidget *mListWidget;
};
