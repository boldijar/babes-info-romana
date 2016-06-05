#ifndef APP_H
#define APP_H

#include <QWidget>
#include "taskController.h"
#include "myTasks.h"
#include "QMessageBox"

namespace Ui {
class app;
}

class app : public QWidget
{
    Q_OBJECT
    
public:
    explicit app(QWidget *parent = 0);
    ~app();

    
private slots:
    void on_btnAdd_clicked();
    void updateTotalHours();

    void on_leName_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::app *ui;
    TaskController* ctrl;
    MyTasks* model;

};

#endif // APP_H
