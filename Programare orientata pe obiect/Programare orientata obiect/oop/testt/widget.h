#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ExpenseManager.h"
#include "MyExpense.h"
#include "QMessageBox"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_btnAdd_clicked();
    void updateTotalAmount();

    void on_leType_cursorPositionChanged(int arg1, int arg2);
    
private:
    Ui::Widget *ui;
    ExpenseManager* ctrl;
    MyExpense* model;
};

#endif // WIDGET_H
