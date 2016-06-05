#include "expense.h"

void Expense::setId(int i) {
    id = i;
}

const int Expense::getId() const {
    return id;
}

void Expense::setType(QString t) {
    type = t;
}

const QString Expense::getType() const {
    return type;
}

void Expense::setAmount(int a) {
    amount = a;
}

const int Expense::getAmount() const {
    return amount;
}

bool Expense::isValid() throw (Error) {
    if (type == "") {
        throw Error("Tipul nu a fost completat!");
    }
    if (amount <= 0) {
        throw Error("Cantitatea trebuie sa fie un intreg pozitiv!");
    }
    return true;
}

bool Expense::operator <(const Expense &other) const {
    return this->type < other.type;
}

