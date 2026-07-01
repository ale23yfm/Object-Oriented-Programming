#pragma once
#include <string>

class Idea
{
private:
	std::string desc, status, creator;
	int act;

public:
	Idea(std::string desc, std::string status, std::string creator, int act) :desc(desc), status(status), creator(creator), act(act) {};
	std::string getDesc() { return this->desc; }; 
	std::string getStatus() { return this->status; };
	std::string getCreator() { return this->creator; };
	
	void setStatus(std::string s) { this->status = s; };
	int getAct() { return this->act; };
};