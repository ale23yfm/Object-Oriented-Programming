#include "vegetables.h"
#include "service.h"
#include <iostream>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
//int main()
{
    QApplication app(argc, argv);
    Repo repo;
    repo.loadFromFile();
    Service serv(repo);
    vegetables window(serv);
    window.show();
    return app.exec();
    //return 0;
}
