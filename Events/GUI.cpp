#include "GUI.h"
#include <QHBoxLayout>
#include <QLabel>

GUI::GUI(ServiceAdmin& servAdmin, ServiceUser& servUser) :servAdmin(servAdmin), servUser(servUser)
{
	this->buildGUI();

	QObject::connect(this->adminButton, &QPushButton::clicked,
		this, &GUI::onAdminClicked);
	QObject::connect(this->userButton, &QPushButton::clicked,
		this, &GUI::onUserClicked); 
	QObject::connect(this->exitButton, &QPushButton::clicked,
			qApp, &QApplication::quit);
}

void GUI::buildGUI()
{
	QVBoxLayout* mainLayout = new QVBoxLayout{ this };

	QLabel* label = new QLabel{ "Welcome to Life After School. Who are you?" };
	this->adminButton = new QPushButton{ "Admin" };
	this->userButton = new QPushButton{ "User" };
	this->exitButton = new QPushButton{ "Exit" };

	mainLayout->addWidget(label);
	mainLayout->addWidget(this->adminButton);
	mainLayout->addWidget(this->userButton);
	mainLayout->addWidget(this->exitButton);
}

void GUI::onAdminClicked()
{
	AdminWindow* w = new AdminWindow(this->servAdmin, this);
	w->show();
	this->hide();
}

void GUI::onUserClicked()
{
	UserWindow* w = new UserWindow(this->servUser, this->servAdmin, this);
	w->show();
	this->hide();
}