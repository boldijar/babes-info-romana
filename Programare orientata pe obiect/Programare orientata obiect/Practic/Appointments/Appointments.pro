#-------------------------------------------------
#
# Project created by QtCreator 2012-06-25T12:53:25
#
#-------------------------------------------------

QT       += core gui

TARGET = Appointments
TEMPLATE = app


SOURCES += main.cpp\
        app.cpp \
    appointmentRepository.cpp \
    calendarController.cpp \
    myCalendar.cpp \
    appointment.cpp

HEADERS  += app.h \
    errors.h \
    appointment.h \
    appointmentRepository.h \
    calendarController.h \
    myCalendar.h

FORMS    += app.ui
