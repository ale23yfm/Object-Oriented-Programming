#pragma once
#include <string>

class Bill
{
private:
	std::string companyName;
	std::string serialNumber;
	double sum;
	bool isPaid;

public:
	Bill(std::string companyName, std::string serialNumber, double sum, bool isPaid) : companyName(companyName), serialNumber(serialNumber), sum(sum), isPaid(isPaid){};
	std::string getCompanyName() const { return this->companyName; };
	std::string getSerialNumber() const { return this->serialNumber; };
	double getSum() const { return this->sum; };
	bool getIsPaid() const { return this->isPaid; };
};