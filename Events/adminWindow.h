#pragma once
#include "adminService.h"
#include "adminAddWindow.h"
#include "adminDeleteWindow.h"
#include "adminUpdateWindow.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qspinbox.h>
#include <qpushbutton.h>
#include <qradioButton.h>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QApplication>
#include <QMessageBox>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>


class AdminWindow : public QWidget
{
private:
	ServiceAdmin& servAdmin;

	QListWidget* eventsList;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QPushButton* backButton;
	QPushButton* chartButton;
	QPushButton* showAdminTableButton;
	QPushButton* tableViewButton;
	QRadioButton* sortedButton;
	QRadioButton* shuffledButton;

protected:
	void showEvent(QShowEvent* event) override;

public:
	AdminWindow(ServiceAdmin& servAdmin, QWidget* parent);

	void buildGUI();
	void populateList();
	void onAdd();
	void onDelete();
	void onUpdate();
	void onBack();
	void onShow();
	void onShowTable();
};