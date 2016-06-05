#include "task.h"

void Task::setId(int i) {
    id = i;
}

const int Task::getId() const {
    return id;
}

void Task::setName(QString n) {
    name = n;
}

const QString Task::getName() const {
    return name;
}

void Task::setHours(int h) {
    hours = h;
}

const int Task::getHours() const {
    return hours;
}

bool Task::isValid() throw (Error) {
    if (name == "") {
        throw Error("Numele nu a fost completat!");
    }
    if (hours <= 0) {
        throw Error("Numarul de ore trebuie sa fie un intreg pozitiv!");
    }
    return true;
}

bool Task::operator <(const Task &other) const {
    return this->name < other.name;
}
