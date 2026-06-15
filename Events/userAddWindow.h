#pragma once
#include "userService.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qspinbox.h>
#include <qpushbutton.h>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QApplication>
#include <QMessageBox>
#include <QShortcut>
#include <QLabel>

class BrowseEventsWindow : public QWidget
{
private:
	ServiceUser& servUser;

	std::vector<Event> eventList;
	int currentIndex;

	QSpinBox* month;
	QPushButton* searchButton;

	QLabel* titleLabel;
	QLabel* descriptionLabel;
	QLabel* dateLabel;
	QLabel* timeLabel;
	QLabel* nrPeopleLabel;

	QPushButton* exitButton;
	QPushButton* addButton;
	QPushButton* nextButton;
	QPushButton* undoButton;
	QPushButton* redoButton;

public:
	BrowseEventsWindow(ServiceUser& servUser, QWidget* parent = nullptr);

	void displayCurrent();
	void buildGUI();
	void onSearch();
	void onAdd();
	void onNext();
	void onBack();
	void onUndo();
	void onRedo();
};