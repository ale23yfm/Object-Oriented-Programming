#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_doctor.h"
#include "serv.h"
#include "observer.h"

class doctor : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    doctor(Service& serv, Medic* m, QWidget *parent = nullptr);
    void update() override;
    ~doctor();

private:
    Ui::doctorClass ui;
    Service& serv;
    Medic* m;

    void populateList();
};

