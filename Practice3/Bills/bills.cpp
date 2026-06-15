#include "bills.h"
#include <QMessageBox>

bills::bills(Service& serv, QWidget *parent)
    : QMainWindow(parent), serv(serv)
{
    ui.setupUi(this);
    connect(ui.isPaid, &QCheckBox::stateChanged, this, [this](int state) {populateList(state == Qt::Checked); });
    connect(ui.CalculateTotal, &QPushButton::clicked, this, [this] (){
        std::string name = ui.inputName->text().toStdString();
        name = name.substr(name.find_first_not_of(" \t\r\n"));

        try
        {
            double total = this->serv.UnpaidBills(name);
            ui.resultLabel->setText("Total: " + QString::number(total));
        }
        catch (std::runtime_error& e)
        {
            QMessageBox::warning(this, "Error", e.what());
        }
        });
    populateList();
}

bills::~bills()
{}

void bills::populateList(bool unpaid)
{
    ui.BillsList->clear();
    for (auto bill : serv.getAllSorted()) {
        if (unpaid && bill->getIsPaid())
            continue;
        QString text = QString::fromStdString(bill->getCompanyName())
            + " - " + QString::number(bill->getSum());
        QListWidgetItem* item = new QListWidgetItem(text);
        if (!bill->getIsPaid())
            item->setBackground(Qt::red);
        ui.BillsList->addItem(item);
    }
}
