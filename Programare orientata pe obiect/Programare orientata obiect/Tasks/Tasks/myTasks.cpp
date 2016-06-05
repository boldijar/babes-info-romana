#include "myTasks.h"

MyTasks::MyTasks(TaskController *c, QObject *parent)
    :QAbstractTableModel(parent) {
    ctrl = c;
}

int MyTasks::rowCount(const QModelIndex & /*parent*/) const {
   return ctrl->getList().size();
}

int MyTasks::columnCount(const QModelIndex & /*parent*/) const {
    return 3;
}

QVariant MyTasks::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0:
            return ctrl->getList().at(index.row()).getId();
        case 1:
            return ctrl->getList().at(index.row()).getName();
        case 2:
            return ctrl->getList().at(index.row()).getHours();
        }
    }
    return QVariant();
}

QVariant MyTasks::headerData(int section, Qt::Orientation orientation, int role) const {
     if (role == Qt::DisplayRole)
     {
         if (orientation == Qt::Horizontal) {
             switch (section)
             {
             case 0:
                 return QString("Id");
             case 1:
                 return QString("Name");
             case 2:
                 return QString("Hours");
             }
         }
     }
     return QVariant();
}

void MyTasks::addTask(QString n, int h) {
    beginInsertRows(QModelIndex(), ctrl->getList().size(), ctrl->getList().size());
    ctrl->add(n, h);
    endInsertRows();
    emit updateTotal();
}


