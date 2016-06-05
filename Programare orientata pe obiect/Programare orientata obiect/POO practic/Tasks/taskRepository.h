#ifndef TASKREPOSITORY_H
#define TASKREPOSITORY_H
#include "task.h"
#include <QList>
#include <QFile>
#include <QTextStream>

class TaskRepository {
public:
    TaskRepository();
    void add(Task t);
    QList<Task> getList();
    int getTotalHours();

private:
    QList<Task> tList;
    int lastId, totalHours;
};
#endif // TASKREPOSITORY_H
