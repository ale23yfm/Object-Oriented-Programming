#pragma once
#include "eventList.h"
class FileEventList : public EventList
{
protected:
	std::string filename;

public:
	FileEventList(const std::string& filename) : filename(filename) {}
	virtual void writeToFile() const = 0;
	virtual void display() const = 0;
	virtual ~FileEventList () = default;
};

