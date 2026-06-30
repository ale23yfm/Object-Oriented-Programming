#include "dev.h"
#include <QDebug>
#include <algorithm>

dev::dev(User* user, Service& serv, QWidget *parent)
    : QMainWindow(parent), user(user), serv(serv)
{
    ui.setupUi(this);
    setWindowTitle(QString::fromStdString(this->user->getName() + " --- " + this->user->getType())); 
    serv.addObserver(this);

    if (this->user->getType() == "tester")
        ui.resolvePushButton->setVisible(false);
    else
    {
        ui.addPushButton->setVisible(false);
        ui.descLineEdit->setVisible(false);
    }
    populateList();

    connect(ui.addPushButton, &QPushButton::clicked, this, [this]()
        {
            std::string desc = this->ui.descLineEdit->text().trimmed().toStdString();

            try {
                this->serv.addIssue(desc, this->user->getName());
                ui.descLineEdit->clear();
            }
            catch (std::exception& e)
            {
                QMessageBox::warning(this, "Error", e.what());
            }
        });

    connect(ui.removePushButton, &QPushButton::clicked, this, [this]() 
        {
            QListWidgetItem* item = ui.mainListWidget->currentItem();
            if (!item)
            {
                QMessageBox::warning(this, "Error", "Select an issue first!");
                return;
            }

            std::string text = item->text().toStdString();
            std::string desc = text.substr(0, text.find(" -- "));
            try
            {
                this->serv.removeIssue(desc);
            }
            catch (std::exception& e)
            {
                QMessageBox::warning(this, "Error", e.what());
            }
        });

    connect(ui.resolvePushButton, &QPushButton::clicked,this,[this]()
        {
            QListWidgetItem* item = ui.mainListWidget->currentItem();
            if (!item)
            {
                QMessageBox::warning(this, "Error", "Select an issue first!");
                return;
            }

            std::string text = item->text().toStdString();
            std::string desc = text.substr(0, text.find(" -- "));

            try
            {
                this->serv.resolveIssue(desc, this->user->getName());
            }
            catch (std::exception& e)
            {
                QMessageBox::warning(this, "Error", e.what());
            }
        });
}

dev::~dev()
{}

void dev::populateList()
{
    ui.mainListWidget->clear();
    auto& issues = this->serv.getIssues();

    std::sort(issues.begin(), issues.end(), [](Issue* a, Issue* b) 
        {
            if (a->getStatus() != b->getStatus())
                return a->getStatus() > b->getStatus();
            return a->getDesc() < b->getDesc();
        });

    for (auto i : issues)
    {
        QString text = QString::fromStdString(i->getDesc() + " -- " + i->getStatus() + " | " + i->getReporter() + " | " + i->getSolver());
        ui.mainListWidget->addItem(text);
    }
}

void dev::update()
{
    qDebug() << "Update called for" << user->getName();
    populateList();
}

