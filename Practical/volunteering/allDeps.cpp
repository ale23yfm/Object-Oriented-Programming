#include "allDeps.h"
#include <QMessageBox>

allDeps::allDeps(Serv& serv, QWidget* parent)
    : QMainWindow(parent), serv(serv)
{
    ui.setupUi(this);
    this->serv.addObserver(this);
    populateList();

    connect(ui.addPushButton, &QPushButton::clicked, this, [this]()
        {
            std::string name = ui.nameLineEdit->text().toStdString();
            std::string email = ui.emailLineEdit->text().toStdString();
            std::string interests = ui.interestsLineEdit->text().toStdString();

            if (name.empty())
            {
                QMessageBox::warning(this, "Error", "Type a name first");
                return;
            }

            if (email.empty())
            {
                QMessageBox::warning(this, "Error", "Type an email first");
                return;
            }

            if (interests.empty())
            {
                QMessageBox::warning(this, "Error", "Type list of interests first");
                return;
            }
            try {
                this->serv.addVolunteer(name, email, interests);
                ui.nameLineEdit->clear();
                ui.emailLineEdit->clear();
                ui.interestsLineEdit->clear();
            }
            catch (std::exception& e)
            {
                QMessageBox::warning(this, "Error", e.what());
            }
        });
}

allDeps::~allDeps()
{
}

void allDeps::update()
{
    populateList();
}

void allDeps::populateList()
{
    ui.listWidget->clear();
    for (auto i : this->serv.getDepartmentsSorted())
        ui.listWidget->addItem(QString::fromStdString(i->getName()) + " - " + QString::fromStdString(i->getDesc()) + " - " + QString::number(this->serv.getNrVolunteers(i->getName())));
}