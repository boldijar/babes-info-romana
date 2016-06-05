#ifndef MYCALENDAR_H
#define MYCALENDAR_H

#include <QAbstractTableModel>
#include "calendarController.h"

 class MyCalendar : public QAbstractTableModel
 {
     Q_OBJECT
 public:
     MyCalendar(CalendarController *c, QObject *parent);
     int rowCount(const QModelIndex &parent = QModelIndex()) const ;
     int columnCount(const QModelIndex &parent = QModelIndex()) const;
     QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
     QVariant headerData(int section, Qt::Orientation orientation, int role) const;
     void addAppointment (QString t, QString d);
     void remRow(int row);
 private:
     CalendarController *ctrl;

 };
#endif // MYCALENDAR_H
