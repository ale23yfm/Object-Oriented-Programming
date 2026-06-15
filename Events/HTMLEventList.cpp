#include "HTMLEventList.h"
#include <fstream>
#include <Windows.h>
#include <shellapi.h>
#include <filesystem>
#include <iostream>

void HTMLEventList::writeToFile() const
{
	std::ofstream fout(this->filename);
	if (!fout.is_open()) {
		return;
	}
	fout << "<!DOCTYPE html> \n";
	fout << "<html> \n";
	fout << "<head> \n";
	fout << "<title>Eventlist</title> \n";
	fout << "</head> \n";
	fout << "<body> \n";
	fout << "<table border = \"1\">\n";
	fout << "<tr>\n"
		<< "<th>Title</th>\n"
		<< "<th>Description</th>\n"
		<< "<th>Date</th>\n"
		<< "<th>Time</th>\n"
		<< "<th>People</th>\n"
		<< "<th>Link</th>\n"
		<< "</tr>\n";
	for (const auto& e : this->events) 
		fout << e.toHTML();
	fout << "</table> \n" << "</body> \n" << "</html> \n";
	fout.close();
}

void HTMLEventList::display() const
{
	std::string fullPath = std::filesystem::absolute(this->filename).string();
	ShellExecuteA(NULL, "open", this->filename.c_str(), NULL, NULL, SW_SHOWMAXIMIZED); 
}