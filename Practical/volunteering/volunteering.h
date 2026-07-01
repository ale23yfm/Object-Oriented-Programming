#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_volunteering.h"
#include "serv.h"
#include "dep.h"
#include "observer.h"

class volunteering : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    volunteering(Serv& serv, Department* d, QWidget *parent = nullptr);
    ~volunteering();

    void update() override;

private:
    Ui::volunteeringClass ui;
    Serv& serv;
    Department* d;

    void populateList();
};

