#include "adminDeleteWindow.h"

DeleteEventAdminWindow::DeleteEventAdminWindow(ServiceAdmin& servAdmin, QWidget* parent) :QWidget(parent), servAdmin(servAdmin)
{
	this->buildGUI();
	this->populateList();
	this->setWindowFlags(Qt::Window);

	QObject::connect(this->deleteButton, &QPushButton::clicked,
		this, &DeleteEventAdminWindow::onDelete);
	QObject::connect(this->backButton, &QPushButton::clicked,
		this, &DeleteEventAdminWindow::onBack);
	QObject::connect(this->undoButton, &QPushButton::clicked, this, &DeleteEventAdminWindow::onUndo);
	QObject::connect(this->redoButton, &QPushButton::clicked, this, &DeleteEventAdminWindow::onRedo);
	QShortcut* undoShortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
	QShortcut* redoShortcut = new QShortcut(QKeySequence("Ctrl+Y"), this);
	QObject::connect(undoShortcut, &QShortcut::activated, this, &DeleteEventAdminWindow::onUndo);
	QObject::connect(redoShortcut, &QShortcut::activated, this, &DeleteEventAdminWindow::onRedo);
}

void DeleteEventAdminWindow::buildGUI()
{
	QHBoxLayout* mainLayout = new QHBoxLayout{ this };
	this->eventsList = new QListWidget{};
	this->deleteButton = new QPushButton{ "Delete" };
	this->backButton = new QPushButton{ "Back" };
	this->undoButton = new QPushButton{ "Undo" };
	this->redoButton = new QPushButton{ "Redo" };
	mainLayout->addWidget(this->eventsList);

	QGridLayout* rightLayout = new QGridLayout{};
	this->title = new QLineEdit{};
	rightLayout->addWidget(new QLabel{ "Title" }, 0, 0);
	rightLayout->addWidget(this->title, 0, 1);

	this->day = new QSpinBox{};
	this->day->setRange(1, 31);
	rightLayout->addWidget(new QLabel{ "Day" }, 1, 0);
	rightLayout->addWidget(this->day, 1, 1);

	this->month = new QSpinBox{};
	this->month->setRange(1, 12);
	rightLayout->addWidget(new QLabel{ "Month" }, 2, 0);
	rightLayout->addWidget(this->month, 2, 1);

	this->year = new QSpinBox{};
	this->year->setRange(2026, 2040);
	rightLayout->addWidget(new QLabel{ "Year" }, 3, 0);
	rightLayout->addWidget(this->year, 3, 1);

	this->hour = new QSpinBox{};
	this->hour->setRange(0, 23);
	rightLayout->addWidget(new QLabel{ "Hour" }, 4, 0);
	rightLayout->addWidget(this->hour, 4, 1);

	this->minute = new QSpinBox{};
	this->minute->setRange(0, 59);
	rightLayout->addWidget(new QLabel{ "Minute" }, 5, 0);
	rightLayout->addWidget(this->minute, 5, 1);

	rightLayout->addWidget(this->deleteButton, 9, 0);
	rightLayout->addWidget(this->backButton, 9, 1);

	rightLayout->addWidget(this->undoButton, 10, 0);
	rightLayout->addWidget(this->redoButton, 10, 1);

	mainLayout->addLayout(rightLayout);
}

void DeleteEventAdminWindow::populateList()
{
	this->eventsList->clear();
	std::vector<Event> events = this->servAdmin.servGetAllAdmin();
	for (auto& s : events) {
		this->eventsList->addItem(QString::fromStdString(s.toString()));
	}
}

void DeleteEventAdminWindow::onDelete()
{
	try
	{
		this->servAdmin.servRemoveAdmin(
			this->title->text().toStdString(),
			this->day->value(),
			this->month->value(),
			this->year->value(),
			this->hour->value(),
			this->minute->value());
		this->populateList();
		QMessageBox::information(this, "Success", "Event deleted successfully!");
	}
	catch (const std::exception& ex)
	{
		QMessageBox::warning(this, "Error", QString::fromStdString(ex.what()));
	}
}

void DeleteEventAdminWindow::onBack()
{
	if (this->parent())
		qobject_cast<QWidget*>(this->parent())->show();
	this->hide();
}

void DeleteEventAdminWindow::onUndo()
{
	try {
		servAdmin.undo();
		populateList();
		QMessageBox::information(this, "Succes", "Undo");
	}
	catch (const std::exception& ex) {
		QMessageBox::warning(this, "Undo Error", QString::fromStdString(ex.what()));
	}
}

void DeleteEventAdminWindow::onRedo()
{
	try {
		servAdmin.redo();
		populateList();
		QMessageBox::information(this, "Succes", "Redo");
	}
	catch (const std::exception& ex) {
		QMessageBox::warning(this, "Redo Error", QString::fromStdString(ex.what()));
	}
}