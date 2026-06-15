#pragma once
#include "action.h"
#include "adminService.h"
#include "event.h"

class DeleteAction : public Action
{
private:
	ServiceAdmin& serv;
	Event e;

public:
	DeleteAction(ServiceAdmin& serv, Event e) :serv(serv), e(e) {};

	void executeUndo() override
	{
		serv.addNoRecord(e);
	};

	void executeRedo() override
	{
		serv.removeNoRecord(e.getTitle(), e.getDay(), e.getMonth(), e.getYear(), e.getHour(), e.getMinute());
	};
};