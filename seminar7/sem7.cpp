#include "sem7.h"

sem7::sem7(std::string user, ChatSession& cs, QWidget *parent)
    : QMainWindow(parent), cs(cs), user(user)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(user));

    connect(ui.pushButtonSend, &QPushButton::clicked, this, [this]()
        {
            std::string text = ui.lineEdit->text().toStdString();
            this->cs.add(this->user, text);
            this->update();
            ui.lineEdit->clear();
        });
}

sem7::~sem7()
{}

void sem7::update() 
{
    ui.listWidgetMess->clear();
    for (auto i : this->cs.get())
        ui.listWidgetMess->addItem(QString::fromStdString(i.getUser())+ "\n" + QString::fromStdString(i.getMessage()));
}