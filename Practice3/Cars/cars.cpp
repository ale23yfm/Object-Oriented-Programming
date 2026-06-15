#include "cars.h"
#include <QMessageBox>

cars::cars(Service& serv, QWidget *parent)
    : QMainWindow(parent), serv(serv)
{
    ui.setupUi(this);
    populateList();

    connect(ui.pushButtonShow, &QPushButton::clicked, this, [this]()
        {
            try {
                std::string man = ui.lineManufacturer->text().toStdString();
                int total = this->serv.getNumberByManufacturer(man);
                ui.labelTotal->setText("Total cars: " + QString::number(total));
                ui.listFiltered->clear();
                for (auto i : this->serv.getByManufacturer(man))
                    ui.listFiltered->addItem(QString::fromStdString(i->getModel()) + "  |  " + QString::number(i->getYear()));
            }
            catch (std::runtime_error& e)
            {
                QMessageBox::warning(this, "Error", e.what());
            }
        });
}

cars::~cars()
{}

void cars::populateList()
{
    ui.listCars->clear();
    for (auto i : this->serv.getAll())
    {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(i->getName()) + "  |  " + QString::fromStdString(i->getModel()));
        item->setBackground(QColor(QString::fromStdString(i->getColor())));
        ui.listCars->addItem(item);
    }
}

