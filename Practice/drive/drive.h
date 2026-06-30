#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_drive.h"

class drive : public QMainWindow
{
    Q_OBJECT

public:
    drive(QWidget *parent = nullptr);
    ~drive();

private:
    Ui::driveClass ui;
};

