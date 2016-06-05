#include "taskController.h"

TaskController::TaskController(TaskRepository *r) {
    repo = r;
}

QList<Task> TaskController::getList() {
    return repo->getList();
}

void TaskController::add(QString n, int h) {
    Task tX(0, n, h);
    if (tX.isValid()) {
        repo->add(tX);
    }
}

int TaskController::getTotalHours() {
    return repo->getTotalHours();
}

