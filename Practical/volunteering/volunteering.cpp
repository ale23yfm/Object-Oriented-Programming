#include <qmessagebox>
#include "volunteering.h"

volunteering::volunteering(Serv& serv, Department* d, QWidget* parent)
    : QMainWindow(parent), serv(serv), d(d)
{
    ui.setupUi(this);
    this->serv.addObserver(this);
    setWindowTitle(QString::fromStdString(d->getName()));
    ui.label_4->setText(QString::fromStdString(d->getDesc()));
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

    connect(ui.assignPushButton, &QPushButton::clicked, this, [this]()
        {
            auto item =  ui.unassignedListWidget->currentItem();

            if (item == nullptr)
            {
                QMessageBox::warning(this, "Error", "Select a volunteer");
                return;
            }
            std::string name = item->text().toStdString();
            name = name.substr(0, name.find(" - "));
            try {
                this->serv.assignVolunteers(name, this->d->getName());
            }
            catch (std::exception& e)
            {
                QMessageBox::warning(this, "Error", e.what());
            }
        });
}

volunteering::~volunteering()
{}

void volunteering::update()
{
    populateList();
}

void volunteering::populateList()
{
    ui.unassignedListWidget->clear();
    for (auto i : this->serv.getUnassignedVolunteers())
        ui.unassignedListWidget->addItem(QString::fromStdString(i->getName()) + " - " + QString::fromStdString(i->getEmail()) + " - " + QString::fromStdString(i->getInterests()));

    ui.depVolListWidget->clear();
    for (auto i : this->serv.getAssignedVolunteers(this->d->getName()))
        ui.depVolListWidget->addItem(QString::fromStdString(i->getName()) + " - " + QString::fromStdString(i->getEmail()) + " - " + QString::fromStdString(i->getInterests()));
}

