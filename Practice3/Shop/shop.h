#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_shop.h"
#include "serv.h"

class shop : public QMainWindow
{
    Q_OBJECT

public:
    shop(Service& serv, QWidget *parent = nullptr);
    ~shop();

private:
    Ui::shopClass ui;
    Service& serv;
    void populateList(int state = false);
};

