#ifndef TASKCONTROLLER_H
#define TASKCONTROLLER_H

#include "taskRepository.h"
#include "errors.h"

class TaskController {
public:
    TaskController(TaskRepository* r);
    QList<Task> getList();
    void add(QString n, int h);
    int getTotalHours();
private:
    TaskRepository* repo;
};

#endif // TASKCONTROLLER_H
