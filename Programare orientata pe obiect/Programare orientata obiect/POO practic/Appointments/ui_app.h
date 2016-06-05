/********************************************************************************
** Form generated from reading UI file 'app.ui'
**
** Created: Tue Jun 26 23:28:33 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_H
#define UI_APP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_app
{
public:
    QTableView *tableView;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *lblText;
    QLineEdit *leText;
    QLabel *lblDate;
    QLineEdit *leDate;
    QPushButton *btnAdd;
    QPushButton *btnRemove;

    void setupUi(QWidget *app)
    {
        if (app->objectName().isEmpty())
            app->setObjectName(QString::fromUtf8("app"));
        app->resize(414, 267);
        tableView = new QTableView(app);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 206, 246));
        layoutWidget = new QWidget(app);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(230, 80, 168, 106));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lblText = new QLabel(layoutWidget);
        lblText->setObjectName(QString::fromUtf8("lblText"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblText);

        leText = new QLineEdit(layoutWidget);
        leText->setObjectName(QString::fromUtf8("leText"));

        formLayout->setWidget(0, QFormLayout::FieldRole, leText);

        lblDate = new QLabel(layoutWidget);
        lblDate->setObjectName(QString::fromUtf8("lblDate"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblDate);

        leDate = new QLineEdit(layoutWidget);
        leDate->setObjectName(QString::fromUtf8("leDate"));

        formLayout->setWidget(1, QFormLayout::FieldRole, leDate);

        btnAdd = new QPushButton(layoutWidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        formLayout->setWidget(2, QFormLayout::FieldRole, btnAdd);

        btnRemove = new QPushButton(layoutWidget);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));

        formLayout->setWidget(3, QFormLayout::FieldRole, btnRemove);


        retranslateUi(app);

        QMetaObject::connectSlotsByName(app);
    } // setupUi

    void retranslateUi(QWidget *app)
    {
        app->setWindowTitle(QApplication::translate("app", "app", 0, QApplication::UnicodeUTF8));
        lblText->setText(QApplication::translate("app", "Text:", 0, QApplication::UnicodeUTF8));
        lblDate->setText(QApplication::translate("app", "Date:", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("app", "Add", 0, QApplication::UnicodeUTF8));
        btnRemove->setText(QApplication::translate("app", "Remove", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class app: public Ui_app {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
