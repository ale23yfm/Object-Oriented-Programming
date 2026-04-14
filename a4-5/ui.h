#pragma once
#include "adminService.h"
#include "userService.h"

class UI
{
private:
	ServiceAdmin& servAdmin;
	ServiceUser& servUser;

public:
	UI(ServiceAdmin& servAdmin, ServiceUser& servUser) : servAdmin{ servAdmin }, servUser{ servUser } {}

	void run();

	void printMenuAdmin();
	void uiAddAdmin();
	void uiPrintAdmin();
	void uiRemoveAdmin();
	void uiUpdateAdmin();

	void printMenuUser();
	void uiAddUser();
	void uiPrintUser();
	void uiRemoveUser();
	void uiPrintByMonth();
	void browseEvents();
};