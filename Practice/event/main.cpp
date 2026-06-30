#include "event.h"
#include "Service.h"
#include "Repo.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Repo repo("events.txt", "pers.txt");
    Service serv(repo);
    QVector<event*> windows;
    for (auto i : serv.getPers())
    {
        event* w = new event(serv, i);
        w->show();
        windows.push_back(w);
    }

    return app.exec();
}
