#pragma once
#include "action.h"
#include "adminService.h"
#include "event.h"

class UpdateAction : public Action
{
private:
	ServiceAdmin& serv;
	Event oldE;
	Event newE;

public:
	UpdateAction(ServiceAdmin& serv, Event oldE, Event newE) :serv(serv), oldE(oldE), newE(newE) {};

	void executeUndo() override
	{
		serv.updateNoRecord(newE.getTitle(), newE.getDay(), newE.getMonth(), newE.getYear(), newE.getHour(), newE.getMinute(), oldE);
	};

	void executeRedo() override
	{
		serv.updateNoRecord(oldE.getTitle(), oldE.getDay(), oldE.getMonth(), oldE.getYear(), oldE.getHour(), oldE.getMinute(), newE);
	};
};