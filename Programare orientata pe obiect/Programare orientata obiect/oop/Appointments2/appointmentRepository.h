#ifndef APPOINTMENTREPOSITORY_H
#define APPOINTMENTREPOSITORY_H
#include "appointment.h"
#include <QList>
#include <QFile>
#include <exception>
#include <QTextStream>

class AppointmentRepository {
public:
    AppointmentRepository();
    void add(Appointment a);
    QList<Appointment> getList();
    void removeById(int id);

private:
    QList<Appointment> aList;
    int lastId;
};
#endif // APPOINTMENTREPOSITORY_H
