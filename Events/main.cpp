#include "lab8.h"
#include "GUI.h"
#include <QtWidgets/QApplication>
#define _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    RepoAdmin repoAdmin("admin.txt");
    RepoUser repoUser("user.txt");
    ServiceAdmin servAdmin(repoAdmin);
    ServiceUser servUser(servAdmin,repoAdmin, repoUser);
    GUI gui(servAdmin, servUser);
    gui.show();
    return app.exec();
}