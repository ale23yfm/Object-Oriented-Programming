#pragma once
#include "adminService.h"
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

class AddEventAdminWindow : public QWidget
{
private:
	ServiceAdmin& servAdmin;

	QListWidget* eventsList;
	QLineEdit* title;
	QLineEdit* description;
	QLineEdit* link;
	QLineEdit* nrPeople;
	QSpinBox* day;
	QSpinBox* month;
	QSpinBox* year;
	QSpinBox* hour;
	QSpinBox* minute;

	QPushButton* addButton;
	QPushButton* backButton;
	QPushButton* undoButton;
	QPushButton* redoButton;

public:
	AddEventAdminWindow(ServiceAdmin& servAdmin, QWidget* parent = nullptr);

	void buildGUI();
	void populateList();
	void onAdd();
	void onBack();
	void onUndo();
	void onRedo();
};

