#include "cars.h"
#include "serv.h"
#include <iostream>
#include <QMessageBox>
#include <QtWidgets/QApplication>
#include <cassert>

void testTotalByManufacturer()
{
    Repo repo;
    repo.add("fiat","punto", 2000, "red");
    repo.add("fiat","punto", 2000, "red");
    repo.add("audi","a3", 2000, "red");
    Service serv(repo);
    assert(serv.getNumberByManufacturer("fiat") == 2);
    QMessageBox::information(nullptr, "Tests", "All tests passed!");
}

int main(int argc, char *argv[])
//int main()
{
    QApplication app(argc, argv);
    testTotalByManufacturer();
    Repo repo;
    repo.loadFromFile();
    //for (auto i : repo.getAll())
    //    std::cout << i->getName() << ' ' << i->getModel() << '\n';
    Service serv(repo);
    
    cars window(serv);
    window.show();
    return app.exec();
    //return 0;
}
