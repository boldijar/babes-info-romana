#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <QString>
#include <exception>
#include "errors.h"

class Appointment {
public:
    Appointment(int i, QString t, QString d) : id(i), text(t), date(d) {}

    void setId(int i);
    const int getId() const;

    void setText(QString n);
    const QString getText() const;

    void setDate(QString date);
    const QString getDate() const;

    bool operator <(const Appointment &other) const;
    bool isValid();
private:
    int id;
    QString text, date;
};
#endif // APPOINTMENT_H
