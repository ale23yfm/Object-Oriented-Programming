#include "shop.h"
#include <QMessageBox>

shop::shop(Service& serv, QWidget *parent)
    : QMainWindow(parent), serv(serv)
{
    ui.setupUi(this);
    populateList();

    connect(ui.pushButtonTotal, &QPushButton::clicked, this, [this]()
        {
            std::string s = ui.lineEditCategory->text().toStdString();
            ui.listNew->clear();
            try {
                for (auto i : this->serv.getFiltered(s))
                {
                    QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(i->getName()) + "  |  " + QString::number(i->getQuantity()));
                    if (i->getQuantity() < 3)
                        item->setBackground(QColor("red"));
                    else
                        item->setBackground(QColor("green"));
                    ui.listNew->addItem(item);
                }
                int total = this->serv.getFilteredQuantity(s);
                ui.labelTotal->setText("Total: " + QString::number(total));
            }
            catch (std::runtime_error & e)
            {
                QMessageBox::warning(this, "Error", e.what());
            }
        });

    connect(ui.listShop, &QListWidget::itemClicked, this, [this](QListWidgetItem* item) {
        std::string s = item->text().toStdString();
        ui.listNew->clear();
        for(auto i : this->serv.getFiltered(s))
        ui.listNew->addItem(QString::fromStdString(i->getName()) + "  |  " + QString::number(i->getQuantity()));
        });

    connect(ui.checkBoxHeavy, &QCheckBox::stateChanged, this, [this](int state)
        {
            ui.listShop->clear();
            populateList(state == Qt::Checked);
        });
    
    connect(ui.lineCategoryCom, &QLineEdit::textChanged, this, [this](const QString& line) {
        int t = line.toInt();
        ui.listNew->clear();
        for(auto i : this->serv.getFilteredByMin(t))
            ui.listNew->addItem(QString::fromStdString(i->getName()) + "  |  " + QString::number(i->getQuantity()));
        });
}

shop::~shop()
{}

void shop::populateList(int state)
{
    ui.listShop->clear();
    for (auto i : this->serv.getAllOnce())
    {
        if (state == true)
        {
            if (i == "Fruit" || i == "Veg")
            {
                QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(i));
                ui.listShop->addItem(item);
            }
        }
        else 
        {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(i));
            ui.listShop->addItem(item);
        }
    }
}

