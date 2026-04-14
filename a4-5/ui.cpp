#include <iostream>
#include "ui.h"

using namespace std;

void UI::run()
{
	int mode = 0;
	cout << "Welcome to the Life After School. Who are you? \n1. Admin \n2. User \n\nType your option:\n";
	cin >> mode;
	while (true)
	{
		if (mode == 1)
		{
			int cmd = 0;
			while (cmd != 5)
			{
				printMenuAdmin();
				cout << "Type the command:";
				cin >> cmd;
				switch (cmd) {
				case 1:
					uiAddAdmin();
					break;
				case 2:
					uiRemoveAdmin();
					break;
				case 3:
					uiUpdateAdmin();
					break;
				case 4:
					uiPrintAdmin();
					break;
				case 5:
					cout << "\nGood bye, dear ADMIN!";
					return;
				default:
					cout << "\nInvalid command. Try again with a number between 1-5\n";
				}
			}
		}
		else if (mode == 2)
		{
			int cmd = 0;
			while (cmd != 5)
			{
				printMenuUser();
				cout << "Type the command:";
				cin >> cmd;
				switch (cmd) {
				case 1:
					browseEvents();
					break;
				case 2:
					uiRemoveUser();
					break;
				case 3:
					uiPrintUser();
					break;
				case 4:
					cout << "\nGood bye, dear USER!";
					return;
				default:
					cout << "\nInvalid command. Try again with a number between 1-5\n";
					break;
				}
			}
		}
		else
		{
			cout << "Invalid command, try again!";
			break;
		}
	}
}


////////////////////////////////////
//            ADMIN              //
//////////////////////////////////

void UI::printMenuAdmin()
{
	cout << "\n~~~~ADMIN MENU~~~~\n";
	cout << "1. Add event\n";
	cout << "2. Delete event\n";
	cout << "3. Update event\n";
	cout << "4. List events\n";
	cout << "5. Exit\n";
}

void UI::uiPrintAdmin()
{
	int n = servAdmin.servGetSizeAdmin();
	for (int i = 0; i < n; i++)
	{
		Event& e = servAdmin.servGetEventByIndexAdmin(i);
		cout << i+1 << ". " << e.getTitle() << " | " << e.getDescription() << " | "  << e.getDay() << "/" << e.getMonth() << "/" << e.getYear() << " | " << e.getHour() << ":" << e.getMinute() << " | " << e.getLink() << " | " << e.getNrPeople() << '\n';
	}
}

void UI::uiAddAdmin()
{
	string title, description, link, input;
	int nrPeople, day, month, year, hour, minute;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Title: ";
	getline(cin, title);

	cout << "Description: ";
	getline(cin, description);

	// Day
	while (true) {
		cout << "Day: ";
		getline(cin, input);
		day = stoi(input);
		if (day >= 1 && day <= 31) break;
		cout << "Invalid day. Try again.\n";
	}

	// Month
	while (true) {
		cout << "Month: ";
		getline(cin, input);
		month = stoi(input);
		if (month >= 1 && month <= 12) break;
		cout << "Invalid month. Try again.\n";
	}

	// Year
	while (true) {
		cout << "Year: ";
		getline(cin, input);
		year = stoi(input);
		if (year >= 2026 && year <= 2036) break;
		cout << "Invalid year. Try again.\n";
	}

	// Hour
	while (true) {
		cout << "Hour: ";
		getline(cin, input);
		hour = stoi(input);
		if (hour >= 0 && hour <= 23) break;
		cout << "Invalid hour. Try again.\n";
	}

	// Minute
	while (true) {
		cout << "Minute: ";
		getline(cin, input);
		minute = stoi(input);
		if (minute >= 0 && minute <= 59) break;
		cout << "Invalid minute. Try again.\n";
	}

	// NrPeople
	while (true) {
		cout << "NrPeople: ";
		getline(cin, input);
		nrPeople = stoi(input);
		if (nrPeople >= 0) break;
		cout << "Invalid number. Try again.\n";
	}

	//cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Link: ";
	getline(cin, link);

	try
	{
		servAdmin.servAddAdmin(title, description, day, month, year, hour, minute, nrPeople, link);
		cout << "\nEvent added successfully:\n";
		uiPrintAdmin();
	}
	catch (exception& e)
	{
		cout << "Event already exists.\n";
		uiPrintAdmin();
	}
}

void UI::uiRemoveAdmin()
{
	string title;
	int day, month, year, hour, minute;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	cout << "What event do you want to remove?:\n";
	cout << "Title: ";
	getline(cin, title);
	cout << "Day: ";
	cin >> day;
	while (day < 1 || day > 31)
	{
		cout << "day is between 0 and 31. Try again. \nDay: ";
		cin >> day;
	}
	cout << "Month: ";
	cin >> month;
	while (month < 1 || month > 12)
	{
		cout << "month is between 0 and 12. Try again. \nMonth: ";
		cin >> month;
	}
	cout << "Year: ";
	cin >> year;
	while (year < 2026 || year > 2036)
	{
		cout << "year is between 2026 and 2036. Try again. \nYear: ";
		cin >> year;
	}
	cout << "Hour: ";
	cin >> hour;
	while (hour < 0 || hour > 23)
	{
		cout << "hour is between 0 and 23. Try again. \nHour: ";
		cin >> hour;
	}
	cout << "Minute: ";
	cin >> minute;
	while (minute < 0 || minute > 59)
	{
		cout << "minute is between 0 and 59. Try again. \nMinute: ";
		cin >> minute;
	}

	try {
		cout << "This WAS your data base:\n";
		uiPrintAdmin();

		servAdmin.servRemoveAdmin(title, day, month, year, hour, minute);

		cout << "\n\nEvent deleted successfully!\n This IS your data base:\n";
		uiPrintAdmin();
	}
	catch (std::exception& e) {
		cout << e.what() << "\n";
	}
}

void UI::uiUpdateAdmin()
{
	string title, description, link;
	int nrPeople, day, month, year, hour, minute;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "What event do you want to update?:\n";
	cout << "Title: ";
	getline(cin, title);
	cout << "Day: ";
	cin >> day;
	while (day < 1 || day > 31)
	{
		cout << "day is between 0 and 31. Try again. \nDay: ";
		cin >> day;
	}
	cout << "Month: ";
	cin >> month;
	while (month < 1 || month > 12)
	{
		cout << "month is between 0 and 12. Try again. \nMonth: ";
		cin >> month;
	}
	cout << "Year: ";
	cin >> year;
	while (year < 2026 || year > 2036)
	{
		cout << "year is between 2026 and 2036. Try again. \nYear: ";
		cin >> year;
	}
	cout << "Hour: ";
	cin >> hour;
	while (hour < 0 || hour > 23)
	{
		cout << "hour is between 0 and 23. Try again. \nHour: ";
		cin >> hour;
	}
	cout << "Minute: ";
	cin >> minute;
	while (minute < 0 || minute > 59)
	{
		cout << "minute is between 0 and 59. Try again. \nMinute: ";
		cin >> minute;
	}

	int index = servAdmin.servFindEventAdmin(title, day, month, year, hour, minute);
	if (index == -1)
	{
		cout << "Event not found.\n";
		return;
	}

	Event& oldEvent = servAdmin.servGetEventByIndexAdmin(index);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "\nType - or -1 to keep old values.\n";
	cout << "Update the following fields:\n";
	cout << "Description: ";
	getline(cin, description);
	cout << "NrPeople: ";
	cin >> nrPeople;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Link: ";
	getline(cin, link);

	if (nrPeople == -1)
		nrPeople = oldEvent.getNrPeople();
	if (description == "-")
		description = oldEvent.getDescription();
	if (link == "-")
		link = oldEvent.getLink();

	Event newEvent { title, description, day, month, year, hour, minute, nrPeople, link };

	try {
		cout << "\nThis WAS your data base:\n";
		uiPrintAdmin();

		servAdmin.servUpdateAdmin(title, day, month, year, hour, minute, newEvent);

		cout << "\nEvent updated successfully!\n This IS your data base:\n";
		uiPrintAdmin();
	}
	catch (std::exception& e) {
		cout << e.what() << "\n";
	}
}


////////////////////////////////////
//            USER               //
//////////////////////////////////
void UI::printMenuUser()
{
	cout << "\n~~~~USER MENU~~~~\n";
	cout << "1. Browse events\n";
	cout << "2. Delete event\n";
	cout << "3. List all events\n";
	cout << "4. Exit\n";
}

void UI::uiPrintUser()
{
	int n = servUser.servGetSizeUser();
	for (int i = 0; i < n; i++)
	{
		Event& e = servUser.servGetEventByIndexUser(i);
		cout << i + 1 << ". " << e.getTitle() << " | " << e.getDescription() << " | " << e.getDay() << "/" << e.getMonth() << "/" << e.getYear() << " | " << e.getHour() << ":" << e.getMinute() << " | " << e.getLink() << " | " << e.getNrPeople() << '\n';
	}
}

void UI::uiAddUser()
{
	string title, description, link, input;
	int nrPeople, day, month, year, hour, minute;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Title: ";
	getline(cin, title);

	cout << "Description: ";
	getline(cin, description);

	// Day
	while (true) {
		cout << "Day: ";
		getline(cin, input);
		day = stoi(input);
		if (day >= 1 && day <= 31) break;
		cout << "Invalid day. Try again.\n";
	}

	// Month
	while (true) {
		cout << "Month: ";
		getline(cin, input);
		month = stoi(input);
		if (month >= 1 && month <= 12) break;
		cout << "Invalid month. Try again.\n";
	}

	// Year
	while (true) {
		cout << "Year: ";
		getline(cin, input);
		year = stoi(input);
		if (year >= 2026 && year <= 2036) break;
		cout << "Invalid year. Try again.\n";
	}

	// Hour
	while (true) {
		cout << "Hour: ";
		getline(cin, input);
		hour = stoi(input);
		if (hour >= 0 && hour <= 23) break;
		cout << "Invalid hour. Try again.\n";
	}

	// Minute
	while (true) {
		cout << "Minute: ";
		getline(cin, input);
		minute = stoi(input);
		if (minute >= 0 && minute <= 59) break;
		cout << "Invalid minute. Try again.\n";
	}

	// NrPeople
	while (true) {
		cout << "NrPeople: ";
		getline(cin, input);
		nrPeople = stoi(input);
		if (nrPeople >= 0) break;
		cout << "Invalid number. Try again.\n";
	}

	//cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Link: ";
	getline(cin, link);

	try
	{
		servAdmin.servAddAdmin(title, description, day, month, year, hour, minute, nrPeople, link);
		cout << "\nEvent added successfully:\n";
		uiPrintAdmin();
	}
	catch (exception& e)
	{
		cout << "Event already exists.\n";
		uiPrintAdmin();
	}
}

void UI::uiRemoveUser()
{
	string title;
	int day, month, year, hour, minute;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "What event do you want to remove?:\n";
	cout << "Title: ";
	getline(cin, title);
	cout << "Day: ";
	cin >> day;
	while (day < 1 || day > 31)
	{
		cout << "day is between 0 and 31. Try again. \nDay: ";
		cin >> day;
	}
	cout << "Month: ";
	cin >> month;
	while (month < 1 || month > 12)
	{
		cout << "month is between 0 and 12. Try again. \nMonth: ";
		cin >> month;
	}
	cout << "Year: ";
	cin >> year;
	while (year < 2026 || year > 2036)
	{
		cout << "year is between 2026 and 2036. Try again. \nYear: ";
		cin >> year;
	}
	cout << "Hour: ";
	cin >> hour;
	while (hour < 0 || hour > 23)
	{
		cout << "hour is between 0 and 23. Try again. \nHour: ";
		cin >> hour;
	}
	cout << "Minute: ";
	cin >> minute;
	while (minute < 0 || minute > 59)
	{
		cout << "minute is between 0 and 59. Try again. \nMinute: ";
		cin >> minute;
	}

	try {
		cout << "This WAS your data base:\n";
		uiPrintUser();

		servUser.servRemoveUser(title, day, month, year, hour, minute);

		cout << "\n\nEvent deleted successfully!\n This IS your data base:\n";
		uiPrintUser();
	}
	catch (std::exception& e) {
		cout << e.what() << "\n";
	}
}

void UI::browseEvents() {
	cout << "Enter month (0 = all): ";
	int month;
	cin >> month;

	DynamicArray<Event> list = servUser.servFindEventbyMonthUser(month);

	if (list.daGetSize() == 0) {
		cout << "No events found.\n";
		return;
	}

	int index = 0;

	while(true) {
		Event e = list[index];

		cout << "\n--- EVENT ---\n";
		cout << "Title: " << e.getTitle() << "\n";
		cout << "Description: " << e.getDescription() << "\n";
		cout << "Date: " << e.getDay() << "/" << e.getMonth() << "/" << e.getYear() << "\n";
		cout << "Time: " << e.getHour() << ":" << e.getMinute() << "\n";
		cout << "People going: " << e.getNrPeople() << "\n";

		// open link in browser
		system(("start " + e.getLink()).c_str());

		cout << "\n1. Add to my list\n";
		cout << "2. Next event\n";
		cout << "0. Stop browsing\n";

		int cmd;
		cin >> cmd;

		if (cmd == 1) {
			if (servUser.servFindUser(e) == -1) {
				servUser.servAddUser(e);
				cout << "Added!\n";
			}
			else {
				cout << "You have already added this event.\n";
			}
			index = (index + 1) % list.daGetSize();
		}
		else if (cmd == 2) {
			index = (index + 1) % list.daGetSize();
		}
		else break;
	}
	cout << "Those were the events!\n";
}
