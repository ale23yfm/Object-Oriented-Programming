#pragma once
#include "analysis.h"

class BMI : public MedicalAnalysis
{
private:
	double value;

public:
	BMI(std::string data, double value) : MedicalAnalysis(data), value(value) {};
	bool isResultOK() const;
	std::string toString() const;
	std::string getData() const { return this->data; };
};