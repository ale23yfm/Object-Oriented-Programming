#include "microbial.h"

microbial::microbial(Service& serv, Biologist* b, QWidget* parent)
    : QMainWindow(parent), serv(serv), b(b)
{
    ui.setupUi(this);

    model = new BacteriaModel(serv, this);
    model->filterBySpecies("");
    ui.tableView->setModel(model);

    connect(ui.viewPushButton, &QPushButton::clicked, this, [this]()
        {

        });
}

microbial::~microbial()
{}

void microbial::populateList(Bacterium * bac)
{
}