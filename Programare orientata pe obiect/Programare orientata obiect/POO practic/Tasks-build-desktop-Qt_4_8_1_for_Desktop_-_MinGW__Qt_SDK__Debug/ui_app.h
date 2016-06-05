/********************************************************************************
** Form generated from reading UI file 'app.ui'
**
** Created: Tue Jun 26 19:44:29 2012
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_app
{
public:
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *lblName;
    QLineEdit *leName;
    QLabel *lblHours_2;
    QLineEdit *leHours;
    QPushButton *btnAdd;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QLabel *lblTotal;
    QLabel *lblHours;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *app)
    {
        if (app->objectName().isEmpty())
            app->setObjectName(QString::fromUtf8("app"));
        app->resize(400, 278);
        layoutWidget = new QWidget(app);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(215, 60, 173, 77));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lblName = new QLabel(layoutWidget);
        lblName->setObjectName(QString::fromUtf8("lblName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblName);

        leName = new QLineEdit(layoutWidget);
        leName->setObjectName(QString::fromUtf8("leName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, leName);

        lblHours_2 = new QLabel(layoutWidget);
        lblHours_2->setObjectName(QString::fromUtf8("lblHours_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblHours_2);

        leHours = new QLineEdit(layoutWidget);
        leHours->setObjectName(QString::fromUtf8("leHours"));

        formLayout->setWidget(1, QFormLayout::FieldRole, leHours);

        btnAdd = new QPushButton(layoutWidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        formLayout->setWidget(2, QFormLayout::FieldRole, btnAdd);

        widget = new QWidget(app);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 196, 256));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblTotal = new QLabel(widget);
        lblTotal->setObjectName(QString::fromUtf8("lblTotal"));

        gridLayout->addWidget(lblTotal, 0, 1, 1, 1);

        lblHours = new QLabel(widget);
        lblHours->setObjectName(QString::fromUtf8("lblHours"));

        gridLayout->addWidget(lblHours, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(app);

        QMetaObject::connectSlotsByName(app);
    } // setupUi

    void retranslateUi(QWidget *app)
    {
        app->setWindowTitle(QApplication::translate("app", "app", 0, QApplication::UnicodeUTF8));
        lblName->setText(QApplication::translate("app", "Name:", 0, QApplication::UnicodeUTF8));
        lblHours_2->setText(QApplication::translate("app", "Hours:", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("app", "Add", 0, QApplication::UnicodeUTF8));
        lblTotal->setText(QApplication::translate("app", "Total hours:", 0, QApplication::UnicodeUTF8));
        lblHours->setText(QApplication::translate("app", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class app: public Ui_app {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
