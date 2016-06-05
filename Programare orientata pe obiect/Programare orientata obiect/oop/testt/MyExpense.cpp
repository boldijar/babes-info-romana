#include "MyExpense.h"

MyExpense::MyExpense(ExpenseManager *c, QObject *parent)
    :QAbstractTableModel(parent) {
    ctrl = c;
}

int MyExpense::rowCount(const QModelIndex & /*parent*/) const {
   return ctrl->getList().size();
}

int MyExpense::columnCount(const QModelIndex & /*parent*/) const {
    return 3;
}

QVariant MyExpense::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0:
            return ctrl->getList().at(index.row()).getId();
        case 1:
            return ctrl->getList().at(index.row()).getType();
        case 2:
            return ctrl->getList().at(index.row()).getAmount();
        }
    }
    return QVariant();
}

QVariant MyExpense::headerData(int section, Qt::Orientation orientation, int role) const {
     if (role == Qt::DisplayRole)
     {
         if (orientation == Qt::Horizontal) {
             switch (section)
             {
             case 0:
                 return QString("Id");
             case 1:
                 return QString("Type");
             case 2:
                 return QString("Amount");
             }
         }
     }
     return QVariant();
}

void MyExpense::addExpense(QString t, int a) {
    beginInsertRows(QModelIndex(), ctrl->getList().size(), ctrl->getList().size());
    ctrl->add(t, a);
    endInsertRows();
    emit updateTotal();
}

