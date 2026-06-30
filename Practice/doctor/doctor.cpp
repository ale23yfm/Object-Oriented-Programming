#include "doctor.h"
#include <Qmessagebox>

doctor::doctor(Service& serv, Medic* m, QWidget* parent)
    : QMainWindow(parent), serv(serv), m(m)
{
    ui.setupUi(this);
    this->serv.addObserver(this);
    setWindowTitle(QString::fromStdString(this->m->getName()));
    populateList();

    connect(ui.addPushButton, &QPushButton::clicked, this, [this]()
        {
            std::string name = ui.nameLineEdit->text().toStdString();
            std::string spec = ui.specLineEdit->text().toStdString();
            std::string diag = ui.diagLineEdit->text().toStdString();
            std::string medic = ui.medicLineEdit->text().toStdString();
            std::string date = ui.dateLineEdit->text().toStdString();

            if (name.empty())
                QMessageBox::warning(this, "Error", "Name cannot be empty!");

            try
            {
                this->serv.addPatient(name, spec, medic, date, diag);
            }
            catch (std::exception&e)
            {
                QMessageBox::warning(this, "Error", e.what());
            }

            ui.nameLineEdit->clear();
            ui.specLineEdit->clear();
            ui.diagLineEdit->clear();
            ui.medicLineEdit->clear();
            ui.dateLineEdit->clear();
        });

    connect(ui.currentPatientsCheckBox, &QCheckBox::stateChanged, this, [this](int state)
        {
            if (state == Qt::Checked)
            {
                ui.listWidget->clear();
                for (auto i : this->serv.getPforM(this->m->getName()))
                    ui.listWidget->addItem(QString::fromStdString(i->getName()) + " - " + QString::fromStdString(i->getDiagnosis()) + " - " + QString::fromStdString(i->getDate()));
            }
            else
                populateList();
        });

    connect(ui.updatepushButton, &QPushButton::clicked, this, [this]()
        {
            auto item = ui.listWidget->currentItem();

            if (item == nullptr)
                QMessageBox::warning(this, "Error", "Select a patient first!");

            std::string text = item->text().toStdString();
            std::string name = text.substr(0, text.find(" - "));

            std::string newSpec = ui.newSpecLineEdit->text().toStdString();
            std::string newDiag = ui.newDiagLineEdit->text().toStdString();

            try
            {
                this->serv.updatePatient(name, newSpec, newDiag, this->m->getName());
            }
            catch (std::exception& e)
            {
                QMessageBox::warning(this, "Error", e.what());
            }

            ui.newDiagLineEdit->clear();
            ui.newSpecLineEdit->clear();
        });
}

void doctor::update()
{
    populateList();
}

void doctor::populateList()
{
    ui.listWidget->clear();

    for (auto i : this->serv.getPatients(this->m->getSpecialization()))
        ui.listWidget->addItem(QString::fromStdString(i->getName()) + " - " + QString::fromStdString(i->getDiagnosis()) + " - " + QString::fromStdString(i->getDate()));

}

doctor::~doctor()
{}

