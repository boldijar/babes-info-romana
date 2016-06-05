#ifndef MYEXPENSE_H
#define MYEXPENSE_H
#include <QAbstractTableModel>
#include "ExpenseManager.h"

 class MyExpense : public QAbstractTableModel
 {
     Q_OBJECT
 public:
     MyExpense(ExpenseManager *c, QObject *parent);
     int rowCount(const QModelIndex &parent = QModelIndex()) const ;
     int columnCount(const QModelIndex &parent = QModelIndex()) const;
     QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
     QVariant headerData(int section, Qt::Orientation orientation, int role) const;
     void addExpense (QString t, int a);
 private:
     ExpenseManager *ctrl;
 signals:
     void updateTotal();

 };
#endif // MYEXPENSE_H
