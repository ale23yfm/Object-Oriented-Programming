#pragma once
#include <string>
#include "hospital.h"

class NeonatalUnit : public HospitalDepartment
{
private:
	int numberOfMothers;
	int numberOfNewBorns;
	double averageGrade;

public:
	NeonatalUnit(int numberOfMothers, int numberOfNewBorns, double averageGrade, std::string hospitalName, int numberOfDoctors) : numberOfMothers(numberOfMothers), numberOfNewBorns(numberOfNewBorns), averageGrade(averageGrade), HospitalDepartment(hospitalName, numberOfDoctors) {};
	bool isEfficient() const override;
	std::string toString() const override;
};