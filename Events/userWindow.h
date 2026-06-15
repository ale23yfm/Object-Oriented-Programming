#pragma once
#include "CSVEventList.h"
#include "HTMLEventList.h"
#include "adminService.h"
#include "userService.h"
#include "userAddWindow.h"
#include "userDeleteWindow.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qspinbox.h>
#include <qpushbutton.h>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QApplication>
#include <QMessageBox>
#include <QLabel>
#include <QComboBox>

class UserWindow : public QWidget
{
private:
	ServiceUser& servUser;
	ServiceAdmin& servAdmin;

	QListWidget* eventsList;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* openButton;
	QPushButton* backButton;
	QPushButton* chooseFileButton;
	QPushButton* tableViewButton;

	QComboBox* fileTypeBox;

protected:
	void showEvent(QShowEvent* event) override;

public:
	UserWindow(ServiceUser& servUser, ServiceAdmin& servAdmin, QWidget* parent);

	void buildGUI();
	void populateList();
	void onAdd();
	void onDelete();
	void onOpen();
	void onBack();
	void onChooseFile();
	void onShowTable();
};