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

class DeleteEventAdminWindow : public QWidget
{
private:
	ServiceAdmin& servAdmin;

	QListWidget* eventsList;
	QLineEdit* title;
	QSpinBox* day;
	QSpinBox* month;
	QSpinBox* year;
	QSpinBox* hour;
	QSpinBox* minute;

	QPushButton* deleteButton;
	QPushButton* backButton;
	QPushButton* undoButton;
	QPushButton* redoButton;

public:
	DeleteEventAdminWindow(ServiceAdmin& servAdmin, QWidget* parent = nullptr);

	void buildGUI();
	void populateList();
	void onDelete();
	void onBack();
	void onUndo();
	void onRedo();
};