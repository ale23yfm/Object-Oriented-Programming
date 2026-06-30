#include "doctor.h"
#include "serv.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Repo repo("med.txt", "patient.txt");
    Service serv(repo);

    QVector<doctor*> windows;
    for (auto i : serv.getAllMedics())
    {
        doctor* w = new doctor(serv, i);
        w->show();
        windows.push_back(w);
    }
    return app.exec();
}
