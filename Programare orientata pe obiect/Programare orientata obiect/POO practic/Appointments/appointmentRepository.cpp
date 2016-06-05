#include "appointmentRepository.h"

AppointmentRepository::AppointmentRepository(){
    lastId = 0;
    QFile f("appointments.txt");

    if (!f.open(QIODevice::ReadOnly)) {
        throw Error("Eroare la deschiderea fisierului");
    }

    QTextStream in(&f);
    int id;
    QString text, date;

    while (!in.atEnd()) {
        id = in.readLine().toInt();
        if (id > lastId)
            lastId = id;
        text = in.readLine();
        date = in.readLine();

        Appointment aX = Appointment(id, text, date);
        if (aX.isValid()) {
            aList.append(aX);
        }
    }
}

void AppointmentRepository::add(Appointment a) {
    a.setId(++lastId);
    aList.append(a);

    QFile f("appointments.txt");
    if (!f.open(QIODevice::WriteOnly)) {
        throw Error("Eroare la deschiderea fisierului");
    }

    QTextStream out(&f);
    for (int i = 0; i < aList.size(); i++) {
        out << aList.at(i).getId() << endl;
        out << aList.at(i).getText() << endl;
        out << aList.at(i).getDate() << endl;
    }
}

QList<Appointment> AppointmentRepository::getList() {
    qSort(aList);
    return aList;
}

void AppointmentRepository::removeById(int id) {
    int i = 0;
    while (id != aList.at(i).getId() && i < aList.size()) {
        i++;
    }

    if (id == aList.at(i).getId()) {
        aList.removeAt(i);
        QFile f("appointments.txt");
        if (!f.open(QIODevice::WriteOnly)) {
            throw Error("Eroare la deschiderea fisierului");
        }

        QTextStream out(&f);
        for (int i = 0; i < aList.size(); i++) {
            out << aList.at(i).getId() << endl;
            out << aList.at(i).getText() << endl;
            out << aList.at(i).getDate() << endl;
        }
    }
}

