#pragma once
#include "action.h"
#include "adminService.h"
#include "event.h"

class AddAction : public Action
{
private:
	ServiceAdmin& serv;
	Event e;

public:
	AddAction(ServiceAdmin& serv, Event e) :serv(serv), e(e) {};
	
	void executeUndo() override 
	{
		serv.removeNoRecord(e.getTitle(), e.getDay(), e.getMonth(), e.getYear(), e.getHour(), e.getMinute());
	};

	void executeRedo() override
	{
		serv.addNoRecord(e);
	};
};