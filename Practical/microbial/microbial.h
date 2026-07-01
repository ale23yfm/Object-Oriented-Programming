#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_microbial.h"
#include "service.h"
#include "biologist.h"
#include "bacteriaModel.h"

class microbial : public QMainWindow
{
    Q_OBJECT

public:
    microbial(Service& serv, Biologist* b, QWidget *parent = nullptr);
    ~microbial();

private:
    Ui::microbialClass ui;
    Service& serv;
    Biologist* b;
    BacteriaModel* model;

    void populateList(Bacterium* bac);
};

