#ifndef EXPENSEREPOSITORY_H
#define EXPENSEREPOSITORY_H
#include "Expense.h"
#include <QList>
#include <QFile>
#include <QTextStream>

class ExpenseRepository {
public:
    ExpenseRepository();
    void add(Expense e);
    QList<Expense> getList();
    int getTotalAmount();

private:
    QList<Expense> eList;
    int lastId, totalAmount;
};
#endif // EXPENSEREPOSITORY_H
