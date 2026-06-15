#pragma once
#include <string>

class HospitalDepartment
{
protected:
	std::string hospitalName;
	int numberOfDoctors;

public:
	HospitalDepartment(std::string hospitalName, int numberOfDoctors) : hospitalName(hospitalName), numberOfDoctors(numberOfDoctors) {};
	virtual bool isEfficient() const =0;
	virtual std::string toString() const =0;
	virtual ~HospitalDepartment() = default;
};