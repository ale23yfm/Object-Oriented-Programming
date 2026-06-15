#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab8.h"

class lab8 : public QMainWindow
{
    Q_OBJECT

public:
    lab8(QWidget *parent = nullptr);
    ~lab8();
    
private slots:
    void onAdminClicked();
    void onUserClicked();

private:
    Ui::lab8Class ui;
};

