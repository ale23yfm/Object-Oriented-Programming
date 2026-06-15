#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;

public:
	Service(Repo& repo) : repo(repo) {};
	void servAdd(MedicalAnalysis* a);
	void servRemove(MedicalAnalysis* a);
	std::vector<MedicalAnalysis*> servShowAll();
	bool servShowIfIll(int month);
	void servSaveToFile(std::string filename, int month1, int month2);
};