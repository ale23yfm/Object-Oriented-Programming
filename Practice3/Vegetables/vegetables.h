#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_vegetables.h"
#include "service.h"

class vegetables : public QMainWindow
{
    Q_OBJECT

private:
    Service& serv;

public:
    vegetables(Service& serv, QWidget *parent = nullptr);
    ~vegetables();

private:
    Ui::vegetablesClass ui;
    void populateList();
};

