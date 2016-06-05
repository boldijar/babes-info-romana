#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H
#include "ExpenseRepository.h"
#include "errors.h"

class ExpenseManager {
public:
    ExpenseManager(ExpenseRepository* r);
    QList<Expense> getList();
    void add(QString t, int a);
    int getTotalAmount();
private:
    ExpenseRepository* repo;
};
#endif // EXPENSEMANAGER_H
