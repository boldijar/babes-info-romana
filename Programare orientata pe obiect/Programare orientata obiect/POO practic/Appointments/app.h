#ifndef APP_H
#define APP_H

#include <QWidget>
#include "calendarController.h"
#include "myCalendar.h"
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

    void on_tableView_clicked(const QModelIndex &index);

    void on_btnRemove_clicked();

private:
    Ui::app *ui;
    CalendarController* ctrl;
    MyCalendar* model;
    int selectedRow;

};

#endif // APP_H
