#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_allDeps.h"
#include "serv.h"
#include "observer.h"

class allDeps : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    allDeps(Serv& serv, QWidget* parent = nullptr);
    ~allDeps();

    void update() override;

private:
    Ui::Form ui;
    Serv& serv;

    void populateList();
};