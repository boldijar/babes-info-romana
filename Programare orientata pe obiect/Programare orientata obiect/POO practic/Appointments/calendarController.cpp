#include "calendarController.h"
#include <exception>

CalendarController::CalendarController(AppointmentRepository *r) {
    repo = r;
}

QList<Appointment> CalendarController::getList() {
    return repo->getList();
}

void CalendarController::add(QString t, QString d) {
    Appointment aX(0, t, d);
    if (aX.isValid()) {
        repo->add(aX);
    }
}

void CalendarController::removeById(int id) {
    repo->removeById(id);
}

