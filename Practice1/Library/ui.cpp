#include "ui.h"
#include <iostream>
#include <string>

using namespace std;

void UI::uiRun()
{
	int cmd = 0;
	while (cmd != 5)
	{
		prinMenu();
		cout << "Type your option: ";
		cin >> cmd;
		while (cin.fail())
		{
			cout << "Type an integer!";
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> cmd;
		}
		switch (cmd)
		{
		case 1:
			uiAdd();
			break;
		case 2:
			uiDelete();
			break;
		case 3:
			uiPrint();
			break;
		case 4:
			uiClassic();
			break;
		case 5:
			cout << "\n Goodbye!";
			return;
		default:
			cout << "\n Try again!";
		}
	}
}

void UI::prinMenu()
{
	cout << "\nWELCOME\n";
	cout << "1. Add a book\n";
	cout << "2. Delete a book\n";
	cout << "3. Show all books\n";
	cout << "4. Show classic books\n";
	cout << "5. Exit\n";
}

void UI::uiAdd()
{
	string title, author, genre;
	int year;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Title: ";
	getline(cin, title);

	cout << "Author: ";
	getline(cin, author);

	cout << "Year: ";
	cin >> year;
	while (cin.fail())
	{
		cout << "Type integer";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> year;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Genre: ";
	getline(cin, genre);

	try
	{
		serv.servAdd(title, author, year, genre);
		cout << "Book added successfully:\n";
		uiPrint();
	}
	catch (exception& e)
	{
		cout << "Book already exists:\n";
		uiPrint();
	}
}

void UI::uiDelete()
{
	string title, author;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Title: ";
	getline(cin, title);

	cout << "Author: ";
	getline(cin, author);

	try
	{
		cout << "This WAS your data:";
		uiPrint();
		serv.servDelete(title, author);
		cout << "Book deleted successfully!\n This IS your data:\n";
		uiPrint();
	}
	catch (exception& e)
	{
		cout << "Book does not exist:\n";
		uiPrint();
	}
}

void UI::uiPrint()
{
	DynamicArray da = serv.servGetAllSorted();
	for (int i = 0; i < da.daGetSize(); i++)
		cout << i + 1 << ". " << da[i].getTitle() << " | " << da[i].getAuthor() << " | " << da[i].getYear() << " | " << da[i].getGenre() << '\n';
}

void UI::uiClassic()
{
	DynamicArray da = serv.servGetClassic();
	for (int i = 0; i < da.daGetSize(); i++)
		cout << i + 1 << ". " << da[i].getTitle() << " | " << da[i].getAuthor() << " | " << da[i].getYear() << " | " << da[i].getGenre() << '\n';
}