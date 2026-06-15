#include "vegetables.h"
#include <QMessageBox>

vegetables::vegetables(Service& serv, QWidget* parent) : QMainWindow(parent), serv(serv)
{
    ui.setupUi(this);
    populateList();
    connect(ui.familyList, &QListWidget::itemClicked, this, [this](QListWidgetItem* item)
        {
            std::string fname = item->text().toStdString();
            ui.partsList->clear();
            for (auto i : this->serv.getVegByFamily(fname))
                ui.partsList->addItem(QString::fromStdString(i->getName() + " - " + i->getParts()));
        });
    connect(ui.searchButton, &QPushButton::clicked, this, [this]()
        {
            std::string name = ui.searchList->text().toStdString();
            for (auto i : this->serv.getAll())
                if (i->getName() == name)
                {
                    auto items = ui.familyList->findItems(QString::fromStdString(i->getFamily()), Qt::MatchExactly);
                    if (!items.isEmpty())
                        ui.familyList->setCurrentItem(items[0]);
                    ui.partsList->clear();
                    ui.partsList->addItem(QString::fromStdString(i->getParts()));
                    return;
                }
            QMessageBox::warning(this,"Error","Not found");
        });
}


vegetables::~vegetables()
{}

void vegetables::populateList()
{
    ui.familyList->clear();
    for (auto i : serv.getUniqueFamilies())
        ui.familyList->addItem(QString::fromStdString(i));
}

