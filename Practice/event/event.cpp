#include "event.h"
#include <QMessageBox>

event::event(Service& serv, Person* pers, QWidget* parent)
   : QMainWindow(parent), serv(serv), pers(pers)
{
    ui.setupUi(this);
    setWindowTitle(QString::fromStdString(this->pers->getName()));
    ui.locationLabel->setText(QString::number(this->pers->getLatit()) + "-" + QString::number(this->pers->getLongit()));
    if (this->pers->getStatus() == false)
    {
        ui.persListWidget->hide();
        ui.nameLineEdit->hide();
        ui.descLineEdit_3->hide();
        ui.latLineEdit_4->hide();
        ui.longLineEdit_5->hide();
        ui.newDateLineEdit_2->hide();
        ui.newDescLineEdit->hide();
        ui.pushButton->hide();
        ui.pushButton_3->hide();
        ui.label->hide();
        ui.label_2->hide();
        ui.label_3->hide();
        ui.label_4->hide();
        ui.label_5->hide();
        ui.label_6->hide();
        ui.label_7->hide();
    }
    populateList();

    connect(ui.pushButton, &QPushButton::clicked, this, [this]()
        {
            std::string name = ui.nameLineEdit->text().toStdString();
            std::string desc = ui.descLineEdit_3->text().toStdString();
            std::string l = ui.latLineEdit_4->text().toStdString();
            std::string ll = ui.longLineEdit_5->text().toStdString();
            float latit = ui.latLineEdit_4->text().toFloat();
            float longit = ui.longLineEdit_5->text().toFloat();
            std::string date = ui.dateline->text().toStdString();

            if (name.empty() || desc.empty() || l.empty() || ll.empty() || date.empty())
            {
                QMessageBox::warning(this, "Error", "Fill in all fields.");
                return;
            }
            try
            {
                this->serv.addEvent(this->pers->getName(), name, desc, date, latit, longit);
                QMessageBox::information(this, "information", "Event added successfullt!");
            }
            catch (std::exception& e)
            {
                QMessageBox::warning(this, "Error", e.what());
            }
            populateList();
            ui.nameLineEdit->clear();
            ui.descLineEdit_3->clear();
            ui.latLineEdit_4->clear();
            ui.longLineEdit_5->clear();
            ui.dateline->clear();
        });

    connect(ui.pushButton_3, &QPushButton::clicked, this, [this]()
        {
            std::string name = ui.nameLineEdit->text().toStdString();
            std::string desc = ui.descLineEdit_3->text().toStdString();
            std::string l = ui.latLineEdit_4->text().toStdString();
            std::string ll = ui.longLineEdit_5->text().toStdString();
            float latit = ui.latLineEdit_4->text().toFloat();
            float longit = ui.longLineEdit_5->text().toFloat();
            std::string date = ui.dateline->text().toStdString();

            if (name.empty() || desc.empty() || l.empty() || ll.empty() || date.empty())
            {
                QMessageBox::warning(this, "Error", "Fill in all fields.");
                return;
            }
            try
            {
                this->serv.addEvent(this->pers->getName(), name, desc, date, latit, longit);
                QMessageBox::information(this, "information", "Event added successfullt!");
            }
            catch (std::exception& e)
            {
                QMessageBox::warning(this, "Error", e.what());
            }
            populateList();
            ui.nameLineEdit->clear();
            ui.descLineEdit_3->clear();
            ui.latLineEdit_4->clear();
            ui.longLineEdit_5->clear();
            ui.dateline->clear();
        });
}

event::~event()
{}

void event::update()
{
    populateList();
}

void event::populateList()
{
    ui.eventsListWidget->clear();
    for (auto i : this->serv.getEvs())
    {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(i->getOrganiser()) + " - " + QString::fromStdString(i->getName()) + " - " + QString::fromStdString(i->getDate()) + " - " + QString::number(i->getLatit()) + " - " + QString::number(i->getLongit()));
        if (i->getOrganiser() == this->pers->getName())
            item->setBackground(Qt::green);
        ui.eventsListWidget->addItem(item);
    }
}
