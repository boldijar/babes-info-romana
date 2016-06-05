#ifndef MYTASKS_H
#define MYTASKS_H

#include <QAbstractTableModel>
#include "taskController.h"

 class MyTasks : public QAbstractTableModel
 {
     Q_OBJECT
 public:
     MyTasks(TaskController *c, QObject *parent);
     int rowCount(const QModelIndex &parent = QModelIndex()) const ;
     int columnCount(const QModelIndex &parent = QModelIndex()) const;
     QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
     QVariant headerData(int section, Qt::Orientation orientation, int role) const;
     void addTask (QString n, int h);
 private:
     TaskController *ctrl;
 signals:
     void updateTotal();

 };
#endif // MYTASKS_H
