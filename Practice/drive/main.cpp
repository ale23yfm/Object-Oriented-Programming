#include "drive.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    drive window;
    window.show();
    return app.exec();
}
