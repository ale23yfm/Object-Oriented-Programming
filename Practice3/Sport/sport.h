#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_sport.h"
#include "serv.h"

class sport : public QMainWindow
{
    Q_OBJECT

public:
    sport(Service& serv, QWidget *parent = nullptr);
    ~sport();

private:
    Service& serv;
    Ui::sportClass ui;
    void populateList();
};

