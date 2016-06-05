#include "taskRepository.h"

TaskRepository::TaskRepository(){
    lastId = 0;
    totalHours = 0;
    QFile f("tasks.txt");

    if (!f.open(QIODevice::ReadOnly)) {
        throw Error("Nu s-a putut deschide fisierul.");
    }

    QTextStream in(&f);
    int id, hours;
    QString name;

    while (!in.atEnd()) {
        id = in.readLine().toInt();
        if (id > lastId)
            lastId = id;
        name = in.readLine();
        hours = in.readLine().toInt();

        Task tX = Task(id, name, hours);
        if (tX.isValid()) {
            tList.append(tX);
            totalHours += tX.getHours();
        }
    }
}

void TaskRepository::add(Task t) {
    t.setId(++lastId);
    tList.append(t);
    totalHours += t.getHours();

    QFile f("tasks.txt");
    if (!f.open(QIODevice::WriteOnly)) {
        throw Error("Nu s-a putut deschide fisierul.");
    }

    QTextStream out(&f);
    for (int i = 0; i < tList.size(); i++) {
        out << tList.at(i).getId() << endl;
        out << tList.at(i).getName() << endl;
        out << tList.at(i).getHours() << endl;
    }
}

QList<Task> TaskRepository::getList() {
    qSort(tList);
    return tList;
}

int TaskRepository::getTotalHours() {
    return totalHours;
}
