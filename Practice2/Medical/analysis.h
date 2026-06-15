#pragma once
#include <string>

class MedicalAnalysis
{
protected: 
	std::string data;

public:
	MedicalAnalysis(std::string data) : data(data) {};
	virtual bool isResultOK() const = 0;
	virtual std::string toString() const = 0;
	virtual std::string getData() const = 0;
	virtual ~MedicalAnalysis() = default;
};