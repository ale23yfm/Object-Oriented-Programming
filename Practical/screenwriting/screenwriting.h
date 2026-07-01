#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_screenwriting.h"
#include "Service.h"
#include "Observer.h"
#include "model.h"
#include "writer.h"

class screenwriting : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    screenwriting(Service& serv, Writer* w, QWidget *parent = nullptr);
    ~screenwriting();

    void update() override;

private:
    Ui::screenwritingClass ui;
    Service& serv;
    Writer* w;
    Model* m;
};

