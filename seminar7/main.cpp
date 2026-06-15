#include "sem7.h"
#include "chatSession.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ChatSession subject{};
    sem7 window1("Maria", subject);
    sem7 window2("Andrei", subject);

    subject.reg(&window1);
    subject.reg(&window2);

    window1.show();
    window2.show();
    return app.exec();
}
