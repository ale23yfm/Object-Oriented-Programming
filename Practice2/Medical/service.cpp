#include "service.h"
#include <fstream>

void Service::servAdd(MedicalAnalysis* a)
{
	this->repo.repoAdd(a);
}

void Service::servRemove(MedicalAnalysis* a)
{
	this->repo.repoRemove(a);
}

std::vector<MedicalAnalysis*> Service::servShowAll()
{
	return this->repo.repoShowAll();
}

bool Service::servShowIfIll(int month)
{
	std::vector<MedicalAnalysis*> all = this->servShowAll();
	for (auto a : all)
		if (a->isResultOK() == true && stoi(a->getData().substr(5, 2)) == month) return false;
	return true;
}

void Service::servSaveToFile(std::string filename, int month1, int month2)
{
	std::vector<MedicalAnalysis*> all = this->servShowAll();
	std::ofstream fout(filename);
	for (auto a : all)
		if (stoi(a->getData().substr(5, 2)) >= month1 && stoi(a->getData().substr(5, 2)) <= month2) fout << a->toString() << '\n';
	fout.close();
}