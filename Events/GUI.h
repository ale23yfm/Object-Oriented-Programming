#pragma once
#include <qwidget.h>
#include <qpushbutton.h>
#include "adminService.h"
#include "adminWindow.h"
#include "userService.h"
#include "userWindow.h"

class GUI : public QWidget
{
private:
	ServiceAdmin& servAdmin;
	ServiceUser& servUser;

	QListWidget* eventsList;

	QPushButton* adminButton;
	QPushButton* userButton;
	QPushButton* exitButton;

public:
	GUI(ServiceAdmin& servAdmin, ServiceUser& servUser);

	void buildGUI();

	void onAdminClicked();
	void onUserClicked();
};