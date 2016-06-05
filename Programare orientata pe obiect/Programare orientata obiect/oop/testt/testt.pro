#-------------------------------------------------
#
# Project created by QtCreator 2012-07-03T14:12:14
#
#-------------------------------------------------

QT       += core gui

TARGET = testt
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    Expense.cpp \
    ExpenseManager.cpp \
    ExpenseRepository.cpp \
    MyExpense.cpp

HEADERS  += widget.h \
    errors.h \
    Expense.h \
    ExpenseManager.h \
    ExpenseRepository.h \
    MyExpense.h

FORMS    += widget.ui
