#include "app.h"
#include "ui_app.h"

app::app(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::app)
{
    ui->setupUi(this);
    try {
        ctrl = new TaskController(new TaskRepository);
    } catch (Error e) {
        QMessageBox::critical(this, "Eroare", e.getMessage());
        exit(1);
    }

    model = new MyTasks(ctrl, this);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 30);
    ui->tableView->setColumnWidth(1, 100);
    ui->tableView->setColumnWidth(2, 40);
    updateTotalHours();
    connect(model, SIGNAL(updateTotal()), this, SLOT(updateTotalHours()));
}

app::~app()
{
    delete ctrl;
    delete ui;
}

void app::updateTotalHours() {
    ui->lblHours->setText(QString::number(ctrl->getTotalHours()));
}

void app::on_btnAdd_clicked() {
    try {
        model->addTask(ui->leName->text(), ui->leHours->text().toInt());
        ui->leName->clear();
        ui->leHours->clear();
    } catch (Error e) {
        QMessageBox::warning(this, "Warning", e.getMessage());
    }
}

void app::on_leName_cursorPositionChanged(int arg1, int arg2)
{

}
