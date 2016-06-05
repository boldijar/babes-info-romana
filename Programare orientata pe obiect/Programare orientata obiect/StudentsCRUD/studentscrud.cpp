#include "studentscrud.h"
#include "ui_studentscrud.h"
#include <QMessageBox>
#include <qlistwidget.h>
StudentsCRUD::StudentsCRUD(StudentController *studCtrl, QWidget *parent) :
   QMainWindow(parent),
    ui(new Ui::StudentsCRUD)
{
    ui->setupUi(this);
    _studCtrl = studCtrl;
    reloadList();
    connectSignalsToSlots();
    init();
}

StudentsCRUD::~StudentsCRUD()
{
    delete ui;
}

void StudentsCRUD::connectSignalsToSlots() {
    QObject::connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(addStudent()));
    QObject::connect(ui->listStudents, SIGNAL(itemSelectionChanged()), this, SLOT(studentSelected()));
    QObject::connect(ui->btnUpdate, SIGNAL(clicked()), this, SLOT(updateStudent()));
    QObject::connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(deleteStudent()));
}

void StudentsCRUD::reloadList()
{
    ui->listStudents->clear();
    DynamicArray<Student>* studList = _studCtrl->getStudList();
    DynamicArrayIterator<Student> it = studList->begin();
    DynamicArrayIterator<Student> end = studList->end();
    Student* studX;

    while (it <= end) {
        studX = it.getElement();
        QListWidgetItem* studItem =
                new QListWidgetItem(QString::fromStdString(studX->name), ui->listStudents);
        studItem->setData(Qt::UserRole, QVariant::fromValue(studX->getId()));
        ++it;
    }
    ui->lblSizeVal->setText(QString::number(_studCtrl->size()));
}

void StudentsCRUD::init()
{

}

void StudentsCRUD::addStudent()
{
    string name = ui->lineEditName->text().toStdString();
    string group = ui->lineEditGroup->text().toStdString();
    try {
        _studCtrl->addStudent(name, group);
        reloadList();
    } catch(ValidationError& e) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
    }
}

void StudentsCRUD::updateStudent()
{
    int id = ui->lineEditId->text().toInt();
    string newName = ui->lineEditName->text().toStdString();
    string newGroup = ui->lineEditGroup->text().toStdString();
    _studCtrl->updateStudent(id, newName, newGroup);
    reloadList();
}

void StudentsCRUD::deleteStudent()
{
    int id = ui->lineEditId->text().toInt();
    _studCtrl->removeStudent(id);
    ui->lineEditId->clear();
    ui->lineEditName->clear();
    ui->lineEditGroup->clear();
    reloadList();
}

void StudentsCRUD::studentSelected()
{
    QList<QListWidgetItem*> sel = ui->listStudents->selectedItems();
    if (sel.size() == 0) {
        return;
    }
    QVariant idV = sel.first()->data(Qt::UserRole);
    int id = idV.toInt();
    Student* stud = _studCtrl->getById(id);
    ui->lineEditId->setText(QString::number(stud->getId()));
    ui->lineEditName->setText(QString::fromStdString(stud->name));
    ui->lineEditGroup->setText(QString::fromStdString(stud->group));
}
