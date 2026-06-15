#include "validation.h"

void Validation::validate(const Event& e)
{
    std::string errors;

    if (e.getTitle().empty())
        errors += "Title cannot be empty.\n";

    if (e.getDescription().empty())
        errors += "Description cannot be empty.\n";

    if (e.getDay() < 1 || e.getDay() > 31)
        errors += "Day must be between 1 and 31.\n";

    if (e.getMonth() < 1 || e.getMonth() > 12)
        errors += "Month must be between 1 and 12.\n";

    if (e.getYear() < 2026 || e.getYear() > 2036)
        errors += "Year must be between 2026 and 2036.\n";

    if (e.getHour() < 0 || e.getHour() > 23)
        errors += "Hour must be between 0 and 23.\n";

    if (e.getMinute() < 0 || e.getMinute() > 59)
        errors += "Minute must be between 0 and 59.\n";

    if (e.getLink().empty())
        errors += "Link cannot be empty.\n";

    if (e.getNrPeople() < 0)
        errors += "NrPeople must be greater than 0.\n";

    if (!errors.empty())
        throw ValidationException(errors);

}
