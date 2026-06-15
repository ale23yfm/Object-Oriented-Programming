#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_testtT.h"
#include "serv.h"

class testtT : public QMainWindow
{
    Q_OBJECT

public:
    testtT(Serv& serv, QWidget *parent = nullptr);
    ~testtT();

private:
    Ui::testtTClass ui;
    Serv& serv;
    void populateList();
};

