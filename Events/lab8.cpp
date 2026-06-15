#include "lab8.h"
#include <QPushButton>

lab8::lab8(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.adminButton, &QPushButton::clicked, this, &lab8::onAdminClicked);
    connect(ui.userButton, &QPushButton::clicked, this, &lab8::onUserClicked);
}

lab8::~lab8()
{}

void lab8::onAdminClicked()
{

}

void lab8::onUserClicked()
{
}
