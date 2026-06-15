#pragma once 
#include "fileEventList.h"

class HTMLEventList : public FileEventList
{
public:
	HTMLEventList(const std::string& filename) : FileEventList(filename) { }
	void writeToFile() const override;
	void display() const override; 
};