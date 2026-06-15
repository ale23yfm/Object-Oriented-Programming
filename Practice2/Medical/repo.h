#pragma once
#include <string>
#include <vector>
#include "analysis.h"

class Repo
{
private:
	std::string name;
	std::vector<MedicalAnalysis*> analysis;

public:
	Repo() = default;
	Repo(std::string name, std::vector<MedicalAnalysis*> analysis) : name(name), analysis(analysis){};
	void repoAdd(MedicalAnalysis* a);
	void repoRemove(MedicalAnalysis* a);
	std::vector<MedicalAnalysis*> repoShowAll();
};