#include "ExpenseManager.h"

ExpenseManager::ExpenseManager(ExpenseRepository *r) {
    repo = r;
}

QList<Expense> ExpenseManager::getList() {
    return repo->getList();
}

void ExpenseManager::add(QString t, int a) {
    Expense eX(0, t, a);
    if (eX.isValid()) {
        repo->add(eX);
    }
}

int ExpenseManager::getTotalAmount() {
    return repo->getTotalAmount();
}



