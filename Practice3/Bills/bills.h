#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_bills.h"
#include "service.h"

class bills : public QMainWindow
{
    Q_OBJECT

public:
    bills(Service& serv, QWidget *parent = nullptr);
    ~bills();

private:
    Service& serv;
    Ui::billsClass ui;
    void populateList(bool unpaid = false);

};

