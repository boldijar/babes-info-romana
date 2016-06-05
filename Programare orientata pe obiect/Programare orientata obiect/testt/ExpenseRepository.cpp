#include "ExpenseRepository.h"

ExpenseRepository::ExpenseRepository(){
    lastId = 0;
    totalAmount = 0;
    QFile f("expense.txt");

    if (!f.open(QIODevice::ReadOnly)) {
        throw Error("Nu s-a putut deschide fisierul.");
    }

    QTextStream in(&f);
    int id, amount;
    QString type;

    while (!in.atEnd()) {
        id = in.readLine().toInt();
        if (id > lastId)
            lastId = id;
        type = in.readLine();
        amount = in.readLine().toInt();

        Expense eX = Expense(id, type, amount);
        if (eX.isValid()) {
            eList.append(eX);
            totalAmount += eX.getAmount();
        }
    }
}

void ExpenseRepository::add(Expense e) {
    e.setId(++lastId);
    eList.append(e);
    totalAmount += e.getAmount();

    QFile f("expense.txt");
    if (!f.open(QIODevice::WriteOnly)) {
        throw Error("Nu s-a putut deschide fisierul.");
    }

    QTextStream out(&f);
    for (int i = 0; i < eList.size(); i++) {
        out << eList.at(i).getId() << endl;
        out << eList.at(i).getType() << endl;
        out << eList.at(i).getAmount() << endl;
    }
}

QList<Expense> ExpenseRepository::getList() {
    qSort(eList);
    return eList;
}

int ExpenseRepository::getTotalAmount() {
    return totalAmount;
}

