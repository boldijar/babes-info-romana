#include "appointment.h"
void Appointment::setText(QString n) {
    text = n;
}

const QString Appointment::getText() const {
    return text;
}

void Appointment::setId(int i) {
    id = i;
}

const int Appointment::getId() const {
    return id;
}

void Appointment::setDate(QString d) {
    date = d;
}

const QString Appointment::getDate() const {
    return date;
}

bool Appointment::operator <(const Appointment &other) const {
    return this->date < other.date;
}

bool Appointment::isValid() {
    if (text == "") {
        throw Error("Textul nu a fost completat!");
    }
    if (date == "") {
        throw Error("Data nu a fost completata!");
    }
    return true;
}

