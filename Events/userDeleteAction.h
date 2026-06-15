#pragma once
#include "action.h"
#include "adminService.h"
#include "event.h"

class DeleteActionUser : public Action
{
private:
	ServiceAdmin& adminServ;
	ServiceUser& userServ;
	Event e;

public:
	DeleteActionUser(ServiceAdmin& adminServ, ServiceUser& userServ, Event e) :adminServ(adminServ), userServ(userServ), e(e) {};

	void executeUndo() override
	{
		userServ.addNoRecord(e);
	};

	void executeRedo() override
	{
		userServ.removeNoRecord(e.getTitle(), e.getDay(), e.getMonth(), e.getYear(), e.getHour(), e.getMinute());
	};
};