#ifndef EXPENSE_H
#define EXPENSE_H
#include <QString>
#include <exception>
#include "errors.h"

class Expense {
public:
    Expense(int i, QString t, int a):
        id(i), type(t), amount(a) {}
    void setId(int i);
    const int getId() const;
    void setType(QString t);
    const QString getType() const;
    void setAmount(int a);
    const int getAmount() const;
    bool isValid() throw (Error);
    bool operator <(const Expense &other) const;
private:
    int id;
    QString type;
    int amount;
};
#endif // EXPENSE_H
