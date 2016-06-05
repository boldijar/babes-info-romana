#include "app.h"
#include "ui_app.h"

app::app(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::app)
{
    ui->setupUi(this);
    try {
        ctrl = new CalendarController(new AppointmentRepository);
    } catch (Error e) {
        QMessageBox::critical(this, "Error", e.getMessage());
        exit(1);
    }

    model = new MyCalendar(ctrl, this);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 30);
    ui->tableView->setColumnWidth(1, 100);
    ui->tableView->setColumnWidth(2, 70);
}

app::~app()
{
    delete ctrl;
    delete ui;
}

void app::on_btnAdd_clicked()
{
    try {
        model->addAppointment(ui->leText->text(), ui->leDate->text());
        ui->leText->clear();
        ui->leDate->clear();
    } catch (Error e) {
        QMessageBox::warning(this, "Warning", e.getMessage());
    }
}

void app::on_tableView_clicked(const QModelIndex &index){
       selectedRow = index.row();
}

void app::on_btnRemove_clicked()
{
    int id = model->data(model->index(selectedRow, 0), Qt::DisplayRole).toInt();
    ctrl->removeById(id);
    model->removeRow(selectedRow);
}
