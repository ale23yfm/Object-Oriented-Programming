#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_allBact.h"

class allBact : public QMainWindow
{
    Q_OBJECT

public:
    allBact(QWidget* parent = nullptr);
    ~allBact();

private:
    Ui::Form ui;
};

