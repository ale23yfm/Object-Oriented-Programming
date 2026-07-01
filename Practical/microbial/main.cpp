#include "microbial.h"
#include "service.h"
#include "repo.h"
#include "bacteriaModel.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Repo repo("biologists.txt","bacteria.txt");
    Service serv(repo);
    BacteriaModel* model = new BacteriaModel(serv);

    QVector<microbial*> bios;
    for (auto i : serv.getBiologists())
    {
        microbial* b = new microbial(serv, i);
        b->show();
        bios.push_back(b);
    }
    return app.exec();
}
