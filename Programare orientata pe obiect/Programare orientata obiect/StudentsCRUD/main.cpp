#include <QtGui/QApplication>
#include "studentscrud.h"
#include "Controller/StudentController.h"
#include "Repository/StudentRepositoryFile.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentRepository* studRepo = new StudentRepositoryFile();
    StudentValidator* studVal = new StudentValidator();
    StudentController* studCtrl = new StudentController(studRepo, studVal);
    StudentsCRUD studentsCrud(studCtrl);
    studentsCrud.show();
    
    return a.exec();
}
