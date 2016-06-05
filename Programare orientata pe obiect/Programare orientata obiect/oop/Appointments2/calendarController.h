#ifndef APPOINTMENTCONTROLLER_H
#define APPOINTMENTCONTROLLER_H
#include "appointmentRepository.h"

class CalendarController {
public:
    CalendarController(AppointmentRepository* r);
    QList<Appointment> getList();
    void add(QString t, QString d);
    void removeById(int id);
private:
    AppointmentRepository* repo;
};
#endif // APPOINTMENTCONTROLLER_H
