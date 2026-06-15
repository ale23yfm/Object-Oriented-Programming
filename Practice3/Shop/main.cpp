#include "shop.h"
#include "serv.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>
#include <iostream>

void testTotal()
{
    Repo repo;
    repo.add("a", "b", 12);
    repo.add("a", "c", 3);
    repo.add("d", "b", 5);

    Service serv(repo);

    assert(serv.getFilteredQuantity("a") == 15);
    assert(serv.getFilteredQuantity("d") == 5);
    assert(serv.getFiltered("a").size() == 2);  
    
    QMessageBox::information(nullptr, "Information", "Test passed");
}

//int main()
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    testTotal();
    Repo repo;
    repo.loadFromFile();
    Service serv(repo);
    //for (auto i : serv.getAll())
    //    std::cout << i->getCategory() << ' ' << i->getName() << '\n';
    shop window(serv);
    window.show();
    return app.exec();
    //return 0;
}
