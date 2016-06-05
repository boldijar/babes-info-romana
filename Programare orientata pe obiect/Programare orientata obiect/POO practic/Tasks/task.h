#ifndef TASK_H
#define TASK_H

#include <QString>
#include <exception>
#include "errors.h"

class Task {
public:
    Task(int i, QString n, int h):
        id(i), name(n), hours(h) {}
    void setId(int i);
    const int getId() const;
    void setName(QString n);
    const QString getName() const;
    void setHours(int h);
    const int getHours() const;
    bool isValid() throw (Error);
    bool operator <(const Task &other) const;
private:
    int id;
    QString name;
    int hours;
};

#endif // TASK_H
