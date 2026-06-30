#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_event.h"
#include "Service.h"
#include "pers.h"

class event : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    event(Service& serv, Person* pers, QWidget *parent = nullptr);
    ~event();

    void update() override;

private:
    Ui::eventClass ui;
    Service& serv;
    Person* pers;

    void populateList();
};