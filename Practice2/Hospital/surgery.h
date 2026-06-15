#pragma once
#include <string>
#include "hospital.h"

class Surgery : public HospitalDepartment
{
private: 
	int numberOfPatients;

public:
	Surgery(int numberOfPatients, std::string hospitalName, int numberOfDoctors) : numberOfPatients(numberOfPatients), HospitalDepartment(hospitalName, numberOfDoctors) {};
	bool isEfficient() const override;
	std::string toString() const override;
};