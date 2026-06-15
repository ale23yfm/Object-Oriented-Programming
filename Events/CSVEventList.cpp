#include "CSVEventList.h"
#include <fstream>
#include <Windows.h>
#include <shellapi.h>

void CSVEventList::writeToFile() const
{
	std::ofstream fout(this->filename);
	if (!fout.is_open())
		return;
	for (const Event& e : this->events)
		fout << e.toCSV();
	fout.close();
}

void CSVEventList::display() const
{
	ShellExecuteA(NULL, "open", this->filename.c_str(), NULL, NULL, SW_SHOWMAXIMIZED);
}