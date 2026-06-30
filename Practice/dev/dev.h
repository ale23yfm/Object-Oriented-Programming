#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_dev.h"
#include "observer.h"
#include "service.h"

class dev : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    dev(User* user, Service& serv, QWidget *parent = nullptr);
    ~dev();

    void update() override;

private:
    Ui::devClass ui;
    Service& serv;
    User* user;

    void populateList();
};

