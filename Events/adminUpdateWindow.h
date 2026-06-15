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

class UpdateEventAdminWindow : public QWidget
{
private:
	ServiceAdmin& servAdmin;

	QLineEdit* newDescription;
	QLineEdit* newLink;
	QLineEdit* newNrPeople;

	QListWidget* eventsList;
	QLineEdit* title;
	QSpinBox* day;
	QSpinBox* month;
	QSpinBox* year;
	QSpinBox* hour;
	QSpinBox* minute;

	QPushButton* updateButton;
	QPushButton* backButton;
	QPushButton* undoButton;
	QPushButton* redoButton;

public:
	UpdateEventAdminWindow(ServiceAdmin& servAdmin, QWidget* parent = nullptr);

	void buildGUI();
	void populateList();
	void onUpdate();
	void onBack();
	void onUndo();
	void onRedo();
};