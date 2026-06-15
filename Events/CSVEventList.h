	#pragma once 
#include "fileEventList.h"

class CSVEventList: public FileEventList
{ 
public:
	CSVEventList(const std::string& filename) : FileEventList(filename) {}
	void writeToFile() const override;
	void display() const override;
};