#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_cars.h"
#include "serv.h"

class cars : public QMainWindow
{
    Q_OBJECT

public:
    cars(Service& serv, QWidget *parent = nullptr);
    ~cars();

private:
    Ui::carsClass ui;
    Service& serv;
    void populateList();
};

