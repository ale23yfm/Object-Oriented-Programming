#include "bills.h"
#include "service.h"
#include <QtWidgets/QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Repo repo;
    repo.loadFromFile();
    Service serv(repo);
    bills window(serv);
    window.show();
    return app.exec();
}
