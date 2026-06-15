#include "weather.h"

std::string Weather::getSenzorsAsString()
{
	std::string result;
	for (int i = 0; i < senzors.size(); i++)
	{
		result += senzors[i];
		if (i < senzors.size() - 1)
			result += ", ";
	}
	return result;
}
