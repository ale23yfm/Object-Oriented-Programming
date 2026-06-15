#include "repo.h"
#include <fstream>
#include <qDebug>

void Repo::loadFromFile()
{
	std::ifstream fin("bills.txt");
	if (!fin.is_open()) {
		//qDebug() << "FILE NOT OPENED";
		throw std::runtime_error("Not opened");
	}
	std::vector<Bill*> res;
	std::string companyNameStr, serialNumberStr, sumStr, isPaidStr;
	while (
		std::getline(fin, companyNameStr, ';') &&
		std::getline(fin, serialNumberStr, ';') &&
		std::getline(fin, sumStr, ';') &&
		std::getline(fin, isPaidStr)
		)
	{
		companyNameStr = companyNameStr.substr(companyNameStr.find_first_not_of(" \t"));
		serialNumberStr = serialNumberStr.substr(serialNumberStr.find_first_not_of(" \t"));
		sumStr = sumStr.substr(sumStr.find_first_not_of(" \t"));
		isPaidStr = isPaidStr.substr(isPaidStr.find_first_not_of(" \t"));

		double sum = std::stod(sumStr);
		bool isPaid = (isPaidStr == "true");

		this->bills.push_back(new Bill(companyNameStr, serialNumberStr, sum, isPaid));
	}
	//qDebug() << "Bills count:" << this->bills.size();

}

std::vector<Bill*> Repo::getAll()
{
	return this->bills;
}
