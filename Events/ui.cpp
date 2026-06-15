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
			printMenuFile();
			int file;
			cout << "Choose the file type: ";
			cin >> file;

			if (file == 1)
				servUser.setFile(new CSVEventList("events.csv"));
			else if (file == 2)
				servUser.setFile(new HTMLEventList("events.html"));
			else
			{
				cout << "Wrong input. Try again";
				continue;
			}

			for (int i = 0; i < servUser.servGetSizeUser(); i++)
				servUser.addToFileList(servUser.servGetEventByIndexUser(i));

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
					servUser.display();
					break;
				case 5:
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
		cout << i + 1 << ". " << e.getTitle() << " | " << e.getDescription() << " | " << e.getDay() << "/" << e.getMonth() << "/" << e.getYear() << " | " << e.getHour() << ":" << e.getMinute() << " | " << e.getLink() << " | " << e.getNrPeople() << '\n';
	}
}

int readInt(const std::string& fieldName) {
	while (true) {
		std::string input;
		getline(cin, input);

		try {
			return stoi(input);
		}
		catch (...) {
			cout << "Invalid number for field: " << fieldName << ". Try again: ";
		}
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
	cout << "Day: ";
	day = readInt("Day");

	// Month
	cout << "Month: ";
	month = readInt("Month");

	// Year
	cout << "Year: ";
	year = readInt("Year");

	// Hour
	cout << "Hour: ";
	hour = readInt("Hour");

	// Minute
	cout << "Minute: ";
	minute = readInt("Minute");

	// NrPeople
	cout << "NrPeople: ";
	nrPeople = readInt("NrPeople");

	cout << "Link: ";
	getline(cin, link);

	try
	{
		servAdmin.servAddAdmin(title, description, day, month, year, hour, minute, nrPeople, link);
		cout << "\nEvent added successfully:\n";
		uiPrintAdmin();
	}
	catch (const ValidationException& ex) {
		cout << "Validation error:\n" << ex.what() << "\n";
	}
	catch (const RepositoryException& ex) {
		cout << "Repository error:\n" << ex.what() << "\n";
	}
	catch (const InputException& ex) {
		cout << "Input error:\n" << ex.what() << "\n";
	}
}

void UI::uiRemoveAdmin()
{
	string title;
	int day, month, year, hour, minute;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "What event do you want to remove?:\n";

	cout << "Title: ";
	getline(cin, title);

	// Day
	cout << "Day: ";
	day = readInt("Day");

	// Month
	cout << "Month: ";
	month = readInt("Month");

	// Year
	cout << "Year: ";
	year = readInt("Year");

	// Hour
	cout << "Hour: ";
	hour = readInt("Hour");

	// Minute
	cout << "Minute: ";
	minute = readInt("Minute");

	try {
		cout << "This WAS your data base:\n";
		uiPrintAdmin();

		servAdmin.servRemoveAdmin(title, day, month, year, hour, minute);

		cout << "\n\nEvent deleted successfully!\n This IS your data base:\n";
		uiPrintAdmin();
	}
	catch (const ValidationException& ex) {
		cout << "Validation error:\n" << ex.what() << "\n";
	}
	catch (const RepositoryException& ex) {
		cout << "Repository error:\n" << ex.what() << "\n";
	}
	catch (const InputException& ex) {
		cout << "Input error:\n" << ex.what() << "\n";
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

	// Day
	cout << "Day: ";
	day = readInt("Day");

	// Month
	cout << "Month: ";
	month = readInt("Month");

	// Year
	cout << "Year: ";
	year = readInt("Year");

	// Hour
	cout << "Hour: ";
	hour = readInt("Hour");

	// Minute
	cout << "Minute: ";
	minute = readInt("Minute");

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

	Event newEvent{ title, description, day, month, year, hour, minute, nrPeople, link };

	try {
		Validation::validate(newEvent);
		cout << "\nThis WAS your data base:\n";
		uiPrintAdmin();

		servAdmin.servUpdateAdmin(title, day, month, year, hour, minute, newEvent);

		cout << "\nEvent updated successfully!\n This IS your data base:\n";
		uiPrintAdmin();
	}
	catch (const ValidationException& ex) {
		cout << "Validation error:\n" << ex.what() << "\n";
	}
	catch (const RepositoryException& ex) {
		cout << "Repository error:\n" << ex.what() << "\n";
	}
	catch (const InputException& ex) {
		cout << "Input error:\n" << ex.what() << "\n";
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
	cout << "4. Display all events in CSV/HTML\n";
	cout << "5. Exit\n";
}

void UI::printMenuFile()
{
	cout << "Where to save?\n";
	cout << "1. CSV file\n";
	cout << "2. HTML file\n";
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
	cout << "Day: ";
	day = readInt("Day");

	// Month
	cout << "Month: ";
	month = readInt("Month");

	// Year
	cout << "Year: ";
	year = readInt("Year");

	// Hour
	cout << "Hour: ";
	hour = readInt("Hour");

	// Minute
	cout << "Minute: ";
	minute = readInt("Minute");

	// NrPeople
	cout << "NrPeople: ";
	nrPeople = readInt("NrPeople");

	cout << "Link: ";
	getline(cin, link);

	try
	{
		servAdmin.servAddAdmin(title, description, day, month, year, hour, minute, nrPeople, link);
		cout << "\nEvent added successfully:\n";
		uiPrintAdmin();
	}
	catch (const ValidationException& ex) {
		cout << "Validation error:\n" << ex.what() << "\n";
	}
	catch (const RepositoryException& ex) {
		cout << "Repository error:\n" << ex.what() << "\n";
	}
	catch (const InputException& ex) {
		cout << "Input error:\n" << ex.what() << "\n";
	}
}

void UI::uiRemoveUser()
{
	string title;
	int day, month, year, hour, minute;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "What event do you want to remove?:\n";

	cout << "Title: ";
	getline(cin, title);

	// Day
	cout << "Day: ";
	day = readInt("Day");

	// Month
	cout << "Month: ";
	month = readInt("Month");

	// Year
	cout << "Year: ";
	year = readInt("Year");

	// Hour
	cout << "Hour: ";
	hour = readInt("Hour");

	// Minute
	cout << "Minute: ";
	minute = readInt("Minute");

	try {
		cout << "This WAS your data base:\n";
		uiPrintUser();

		servUser.servRemoveUser(title, day, month, year, hour, minute);

		cout << "\n\nEvent deleted successfully!\n This IS your data base:\n";
		uiPrintUser();
	}
	catch (const ValidationException& ex) {
		cout << "Validation error:\n" << ex.what() << "\n";
	}
	catch (const RepositoryException& ex) {
		cout << "Repository error:\n" << ex.what() << "\n";
	}
	catch (const InputException& ex) {
		cout << "Input error:\n" << ex.what() << "\n";
	}
}

void UI::browseEvents() {
	cout << "Enter month (0 = all): ";
	int month;
	cin >> month;

	std::vector<Event> list = servUser.servFindEventbyMonthUser(month);

	if (list.size() == 0) {
		cout << "No events found.\n";
		return;
	}

	int index = 0;

	while (true) {
		Event e = list[index];

		cout << "\n--- EVENT ---\n";
		cout << "Title: " << e.getTitle() << "\n";
		cout << "Description: " << e.getDescription() << "\n";
		cout << "Date: " << e.getDay() << "/" << e.getMonth() << "/" << e.getYear() << "\n";
		cout << "Time: " << e.getHour() << ":" << e.getMinute() << "\n";
		cout << "People going: " << e.getNrPeople() << "\n";

		// open link in browser
		e.play();

		cout << "\n1. Add to my list\n";
		cout << "2. Next event\n";
		cout << "0. Stop browsing\n";

		int cmd;
		cin >> cmd;

		if (cmd == 1) {
			if (servUser.servFindUser(e) == -1) {
				servUser.servAddUser(e);
				servUser.addToFileList(e);
				cout << "Added!\n";
			}
			else {
				cout << "You have already added this event.\n";
			}
			index = (index + 1) % list.size();
		}
		else if (cmd == 2) {
			index = (index + 1) % list.size();
		}
		else break;
	}
	cout << "Those were the events!\n";
}