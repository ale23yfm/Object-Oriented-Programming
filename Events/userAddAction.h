#pragma once
#include "action.h"
#include "adminService.h"
#include "event.h"

class AddActionUser : public Action
{
private:
	ServiceAdmin& adminServ;
	ServiceUser& userServ;
	Event e;

public:
	AddActionUser(ServiceAdmin& adminServ, ServiceUser& userServ, Event e) :adminServ(adminServ), userServ(userServ), e(e) {};

	void executeUndo() override
	{
		userServ.removeNoRecord(e.getTitle(), e.getDay(), e.getMonth(), e.getYear(), e.getHour(), e.getMinute());
	};

	void executeRedo() override
	{
		userServ.addNoRecord(e);
	};
};