#include "testtT.h"
#include "repo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Repo repo;
    repo.loadFromFile();
    Serv serv(repo);
    testtT window(serv);
    window.show();
    return app.exec();
}
