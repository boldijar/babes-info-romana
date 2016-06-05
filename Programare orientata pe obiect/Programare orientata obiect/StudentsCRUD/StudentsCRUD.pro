#-------------------------------------------------
#
# Project created by QtCreator 2012-05-21T18:54:42
#
#-------------------------------------------------

QT       += core gui

TARGET = StudentsCRUD
TEMPLATE = app


SOURCES += main.cpp\
        studentscrud.cpp \
    Controller/StudentController.cpp \
    Domain/Validators.cpp \
    Repository/StudentRepositoryInMemory.cpp \
    Repository/StudentRepositoryFile.cpp

HEADERS  += studentscrud.h \
    Controller/StudentController.h \
    Domain/Validators.h \
    Domain/Student.h \
    Domain/Errors.h \
    Repository/StudentRepositoryInMemory.h \
    Repository/StudentRepositoryFile.h \
    Repository/StudentRepository.h \
    Utils/DynamicArray.h

FORMS    += studentscrud.ui

OTHER_FILES += \
    Data/students.dat
