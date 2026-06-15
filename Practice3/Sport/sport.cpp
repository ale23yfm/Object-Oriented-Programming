
#include "sport.h"
#include <QMessageBox>

sport::sport(Service& serv, QWidget* parent)
    : QMainWindow(parent), serv(serv)
{
    ui.setupUi(this);
    populateList();
    connect(ui.lineFilter, &QLineEdit::textChanged, this, [this](const QString& text) {
        if (text.isEmpty())
        {
            populateList();
            return;
        }
        int minInt = text.toInt();
        ui.listSport->clear();
        for (auto i : this->serv.filterByIntensity(minInt))
            ui.listSport->addItem(QString::number(i->getStart()) + "->" +
                QString::number(i->getEnd()) + "  |  " +
                QString::fromStdString(i->getType()) + "  |  " +
                QString::number(i->getIntensity()) + "  |  " +
                QString::fromStdString(i->getDescription())
            );
        });

    connect(ui.totalButton, &QPushButton::clicked, this, [this]() {
        int s = ui.lineStart->text().toInt();
        std::string d = ui.lineDesc->text().toStdString();
        try
        {
            ui.listFiltered->clear();
            for (auto i : this->serv.filterByDesc(d, s))
                ui.listFiltered->addItem(QString::number(i->getStart()) + "->" +
                    QString::number(i->getEnd()) + "  |  " +
                    QString::fromStdString(i->getType()) + "  |  " +
                    QString::number(i->getIntensity()) + "  |  " +
                    QString::fromStdString(i->getDescription())
                );
            int total = this->serv.totalHours(d, s);            
            ui.totalHours->setText("Total: " + QString::number(total));
        }
        catch (std::runtime_error& e) {
            QMessageBox::warning(this, "Error", e.what());
        }
        }); 
}

sport::~sport()
{}

void sport::populateList()
{
    ui.listSport->clear();
    for (auto i : serv.getAll())
        ui.listSport->addItem(QString::number(i->getStart()) + "->" + 
            QString::number(i->getEnd()) + "  |  " + 
            QString::fromStdString(i->getType()) + "  |  " +
            QString::number(i->getIntensity()) + "  |  " + 
            QString::fromStdString(i->getDescription())
        );
}


