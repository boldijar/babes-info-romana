#ifndef STUDENTSCRUD_H
#define STUDENTSCRUD_H

#include <QMainWindow>
#include "Controller/StudentController.h"

namespace Ui {
class StudentsCRUD;
}

class StudentsCRUD : public QMainWindow
{
    Q_OBJECT
    
public:
    StudentsCRUD(StudentController* studCtrl, QWidget *parent = 0);
    ~StudentsCRUD();
    
private:
    StudentController* _studCtrl;
    Ui::StudentsCRUD *ui;
    void connectSignalsToSlots();
    void reloadList();
    void init();

private slots:
    void addStudent();
    void updateStudent();
    void deleteStudent();
    void studentSelected();
};

#endif // STUDENTSCRUD_H
