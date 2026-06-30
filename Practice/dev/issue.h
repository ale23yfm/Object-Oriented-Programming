#pragma once
#include <string>

class Issue
{
private:
	std::string desc;
	std::string status;
	std::string reporter;
	std::string solver;

public:
	Issue(std::string desc, std::string status,	std::string reporter, std::string solver) : desc(desc), status(status), reporter(reporter), solver(solver) {};

	std::string getDesc() const { return this->desc; };
	std::string getStatus() const { return this->status; };
	std::string getReporter() const { return this->reporter; };
	std::string getSolver() const { return this->solver; };

	void setStatus(std::string newStatus){ this->status = newStatus; };
	void setSolver(std::string newSolver){ this->solver = newSolver; };
};