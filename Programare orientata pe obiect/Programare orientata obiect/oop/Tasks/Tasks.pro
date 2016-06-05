#-------------------------------------------------
#
# Project created by QtCreator 2012-06-23T10:01:39
#
#-------------------------------------------------

QT       += core gui

TARGET = Tasks
TEMPLATE = app


SOURCES += main.cpp\
        app.cpp \
    task.cpp \
    taskRepository.cpp \
    taskController.cpp \
    myTasks.cpp

HEADERS  += app.h \
    task.h \
    errors.h \
    taskRepository.h \
    taskController.h \
    myTasks.h

FORMS    += app.ui
