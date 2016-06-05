#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    try {
        ctrl = new ExpenseManager(new ExpenseRepository);
    } catch (Error e) {
        QMessageBox::critical(this, "Eroare", e.getMessage());
        exit(1);
    }

    model = new MyExpense(ctrl, this);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 30);
    ui->tableView->setColumnWidth(1, 100);
    ui->tableView->setColumnWidth(2, 40);
    updateTotalAmount();
    connect(model, SIGNAL(updateTotal()), this, SLOT(updateTotalAmount()));
}

Widget::~Widget()
{
    delete ctrl;
    delete ui;
}
void Widget::updateTotalAmount() {
    ui->lblAmount->setText(QString::number(ctrl->getTotalAmount()));
}

void Widget::on_btnAdd_clicked() {
    try {
        model->addExpense(ui->leType->text(), ui->leAmount->text().toInt());
        ui->leType->clear();
        ui->leAmount->clear();
    } catch (Error e) {
        QMessageBox::warning(this, "Warning", e.getMessage());
    }
}

void Widget::on_leType_cursorPositionChanged(int arg1, int arg2)
{

}
