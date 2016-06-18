/********************************************************************************
** Form generated from reading UI file 'examen.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMEN_H
#define UI_EXAMEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_examenClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *examenClass)
    {
        if (examenClass->objectName().isEmpty())
            examenClass->setObjectName(QStringLiteral("examenClass"));
        examenClass->resize(600, 400);
        menuBar = new QMenuBar(examenClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        examenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(examenClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        examenClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(examenClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        examenClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(examenClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        examenClass->setStatusBar(statusBar);

        retranslateUi(examenClass);

        QMetaObject::connectSlotsByName(examenClass);
    } // setupUi

    void retranslateUi(QMainWindow *examenClass)
    {
        examenClass->setWindowTitle(QApplication::translate("examenClass", "examen", 0));
    } // retranslateUi

};

namespace Ui {
    class examenClass: public Ui_examenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMEN_H
