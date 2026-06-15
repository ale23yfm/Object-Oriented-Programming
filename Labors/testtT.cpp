#include "testtT.h"
#include <QMessageBox>

testtT::testtT(Serv& serv, QWidget *parent)
    : QMainWindow(parent), serv(serv)
{
    ui.setupUi(this);
    populateList();

    connect(ui.lineEdit, &QLineEdit::textChanged, this, [this](const QString& line) {
        int t = line.toInt();
        ui.listWidget->clear();
        for (auto i : this->serv.getAllbyWage(t))
            ui.listWidget->addItem(QString::number(i->getStart()) + "  :  " + QString::number(i->getEnd()) + "  |  " + QString::fromStdString(i->getType()) + "  |  " + QString::fromStdString(i->getCountry()) + "  |  " + QString::number(i->getWage()));
        });

    connect(ui.pushButton, &QPushButton::clicked, this, [this]() {
        int t = ui.lineStart->text().toInt();
        std::string s = ui.lineEdit_3->text().toStdString();
        try {
            int total = this->serv.getTotal(t, s);
            ui.label_4->setText("Total: " + QString::number(total));
            ui.listWidget->clear();
            for (auto i : this->serv.getAllFilter(t, s))
                ui.listWidget->addItem(QString::number(i->getStart()) + "  :  " + QString::number(i->getEnd()) + "  |  " + QString::fromStdString(i->getType()) + "  |  " + QString::fromStdString(i->getCountry()) + "  |  " + QString::number(i->getWage()));
        }
        catch (std::runtime_error& e)
        {
            QMessageBox::warning(this, "Error", e.what());
        }});
}

testtT::~testtT()
{}

void testtT::populateList()
{
    ui.listLabor->clear();
    for (auto i : this->serv.getAll())
        ui.listLabor->addItem(QString::number(i->getStart()) + "  :  " + QString::number(i->getEnd()) + "  |  " + QString::fromStdString(i->getType()) + "  |  "+ QString::fromStdString(i->getCountry()) + "  |  " + QString::number(i->getWage()));
}

