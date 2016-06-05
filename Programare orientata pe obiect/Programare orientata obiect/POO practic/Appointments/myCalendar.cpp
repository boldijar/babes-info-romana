#include "myCalendar.h"

MyCalendar::MyCalendar(CalendarController *c, QObject *parent)
    :QAbstractTableModel(parent) {
    ctrl = c;
}

int MyCalendar::rowCount(const QModelIndex & /*parent*/) const {
   return ctrl->getList().size();
}

int MyCalendar::columnCount(const QModelIndex & /*parent*/) const {
    return 3;
}

QVariant MyCalendar::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0:
            return ctrl->getList().at(index.row()).getId();
        case 1:
            return ctrl->getList().at(index.row()).getText();
        case 2:
            return ctrl->getList().at(index.row()).getDate();
        }
    }
    return QVariant();
}

QVariant MyCalendar::headerData(int section, Qt::Orientation orientation, int role) const {
     if (role == Qt::DisplayRole)
     {
         if (orientation == Qt::Horizontal) {
             switch (section)
             {
             case 0:
                 return QString("Id");
             case 1:
                 return QString("Text");
             case 2:
                 return QString("Date");
             }
         }
     }
     return QVariant();
}

void MyCalendar::addAppointment(QString t, QString d) {
    beginInsertRows(QModelIndex(), ctrl->getList().size(), ctrl->getList().size());
    ctrl->add(t, d);
    endInsertRows();
}

void MyCalendar::remRow(int row) {
    removeRow(row, QModelIndex());
}

