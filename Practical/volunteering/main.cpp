#include "volunteering.h"
#include "allDeps.h"
#include "repo.h"
#include "serv.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Repo repo("vol.txt", "dep.txt");
    Serv serv(repo);

    for (auto v : repo.getVolunteers())
        qDebug() << QString::fromStdString(v->getName()) << " dept: '" << QString::fromStdString(v->getDepart()) << "'";

    QVector<volunteering*> windows;
    for (auto i : serv.getDepartments())
    {
        volunteering* window = new volunteering(serv, i);
        window->show();
        windows.push_back(window);
    }

    allDeps* all = new allDeps(serv);
    all->show();
    return app.exec();
}
