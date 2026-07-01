#include "screenwriting.h"
#include "Repo.h"
#include "Service.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Repo repo("writer.txt", "idea.txt");
    //QMessageBox::information(nullptr, "info", "People:" + QString::number(repo.getWriters().size()) + "Idea:" + QString::number(repo.getIdeas().size()));
    Service serv(repo);
    QVector<screenwriting*> windows;
    for (auto i : serv.getWriters())
    {
        screenwriting* w = new screenwriting(serv, i);
        w->show();
        windows.push_back(w);
    }

    return app.exec();
}
