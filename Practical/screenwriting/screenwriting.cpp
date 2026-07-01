#include "screenwriting.h"
#include <QMessageBox>

screenwriting::screenwriting(Service& serv, Writer* w, QWidget* parent)
    : QMainWindow(parent), serv(serv), w(w)
{
    ui.setupUi(this);
    setWindowTitle(QString::fromStdString(this->w->getName()));
    m = new Model(serv, this);
    ui.tableView->setModel(m);

    this->serv.addObserver(this);


    if (this->w->getExpertise() != "Senior")
        ui.acceptPushButton->hide();

    connect(ui.acceptPushButton, &QPushButton::clicked, this, [this]()
        {
            auto selected = ui.tableView->selectionModel()->currentIndex();
            if (!selected.isValid())
                QMessageBox::warning(this, "Error", "Choose an idea");

            Idea* idea = this->serv.getIdeas()[selected.row()];
            if(idea->getStatus() != "proposed")
                QMessageBox::warning(this, "Error", "The idea should have status proposed");

            this->serv.acceptIdea(idea);
        });

    connect(ui.addPushButton, &QPushButton::clicked, this, [this]()
        {
            std::string desc = ui.descLineEdit->text().toStdString();
            int act = ui.actLineEdit->text().toInt();
            if (desc.empty())
            {
                QMessageBox::warning(this, "Error", "Description is empty");
                return;
            }
            if (act > 3 || act < 1)
            {
                QMessageBox::warning(this, "Error", "Act must be 1,2 or 3");
                return;
            }
            try
            {
                this->serv.addIdea(desc, this->w->getName(), act);
                QMessageBox::information(this, "information", "Added succesfully");
            }
            catch (std::exception& e)
            {
                QMessageBox::warning(this, "Error", e.what());
            }
            ui.descLineEdit->clear();
            ui.actLineEdit->clear();
        });
}

screenwriting::~screenwriting()
{}

void screenwriting::update()
{
    m->update();
}

