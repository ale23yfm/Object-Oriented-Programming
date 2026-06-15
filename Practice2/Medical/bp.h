#pragma once
#include "analysis.h"

class BP : public MedicalAnalysis
{
private:
	int systolicValue;
	int diastolicValue;

public:
	BP(std::string data, int systolicValue, int diastolicValue) : MedicalAnalysis(data), systolicValue(systolicValue), diastolicValue(diastolicValue) {};
	bool isResultOK() const;
	std::string toString() const;
	std::string getData() const { return this->data; };
};