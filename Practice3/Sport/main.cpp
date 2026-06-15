#include "sport.h"
#include "serv.h"
#include <iostream>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
//int main()
{
    QApplication app(argc, argv);
    Repo repo;
    repo.loadFromFile();
    Service serv(repo);
    //for (auto i : serv.getAll())
    //    std::cout << i->getStart() << " " << i->getDescription() << '\n';
    sport window(serv);
    window.show();
    return app.exec();
    //return 0;
}
