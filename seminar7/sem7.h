#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_sem7.h"
#include "chatSession.h"

class sem7 : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    sem7(std::string user, ChatSession& cs, QWidget *parent = nullptr);
    ~sem7();

private:
    Ui::sem7Class ui;
    ChatSession& cs;
    std::string user;

    void update();
};

