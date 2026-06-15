#include "adminAddWindow.h"

AddEventAdminWindow::AddEventAdminWindow(ServiceAdmin& servAdmin, QWidget* parent) :QWidget(parent), servAdmin(servAdmin)
{
	this->buildGUI();
	this->populateList();
	this->setWindowFlags(Qt::Window);

	QObject::connect(this->addButton, &QPushButton::clicked,
		this, &AddEventAdminWindow::onAdd);
	QObject::connect(this->backButton, &QPushButton::clicked,
		this, &AddEventAdminWindow::onBack);
	QObject::connect(this->undoButton, &QPushButton::clicked, this, &AddEventAdminWindow::onUndo);
	QObject::connect(this->redoButton, &QPushButton::clicked, this, &AddEventAdminWindow::onRedo);
	QShortcut* undoShortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
	QShortcut* redoShortcut = new QShortcut(QKeySequence("Ctrl+Y"), this);
	QObject::connect(undoShortcut, &QShortcut::activated, this, &AddEventAdminWindow::onUndo);
	QObject::connect(redoShortcut, &QShortcut::activated, this, &AddEventAdminWindow::onRedo);
}

void AddEventAdminWindow::buildGUI()
{
	QHBoxLayout* mainLayout = new QHBoxLayout{ this };
	this->eventsList = new QListWidget{};
	this->addButton = new QPushButton{ "Add" };
	this->backButton = new QPushButton{ "Back" };
	this->undoButton = new QPushButton{ "Undo" };
	this->redoButton = new QPushButton{ "Redo" };
	mainLayout->addWidget(this->eventsList);

	QGridLayout* rightLayout = new QGridLayout{};
	this->title = new QLineEdit{};
	rightLayout->addWidget(new QLabel{ "Title" }, 0, 0);
	rightLayout->addWidget(this->title, 0, 1);

	this->description = new QLineEdit{};
	rightLayout->addWidget(new QLabel{ "Description" }, 1, 0);
	rightLayout->addWidget(this->description, 1, 1);

	this->day = new QSpinBox{};
	this->day->setRange(1, 31);
	rightLayout->addWidget(new QLabel{ "Day" }, 2, 0);
	rightLayout->addWidget(this->day, 2, 1);

	this->month = new QSpinBox{};
	this->month->setRange(1, 12);
	rightLayout->addWidget(new QLabel{ "Month" }, 3, 0);
	rightLayout->addWidget(this->month, 3, 1);

	this->year = new QSpinBox{};
	this->year->setRange(2026, 2040);
	rightLayout->addWidget(new QLabel{ "Year" }, 4, 0);
	rightLayout->addWidget(this->year, 4, 1);

	this->hour = new QSpinBox{};
	this->hour->setRange(0, 23);
	rightLayout->addWidget(new QLabel{ "Hour" }, 5, 0);
	rightLayout->addWidget(this->hour, 5, 1);

	this->minute = new QSpinBox{};
	this->minute->setRange(0, 59);
	rightLayout->addWidget(new QLabel{ "Minute" }, 6, 0);
	rightLayout->addWidget(this->minute, 6, 1);

	this->nrPeople = new QLineEdit{};
	rightLayout->addWidget(new QLabel{ "NrPeople" }, 7, 0);
	rightLayout->addWidget(this->nrPeople, 7, 1);

	this->link = new QLineEdit{};
	rightLayout->addWidget(new QLabel{ "Link" }, 8, 0);
	rightLayout->addWidget(this->link, 8, 1);

	rightLayout->addWidget(this->addButton, 9, 0);
	rightLayout->addWidget(this->backButton, 9, 1);

	rightLayout->addWidget(this->undoButton, 10, 0);
	rightLayout->addWidget(this->redoButton,10, 1);

	mainLayout->addLayout(rightLayout);
}

void AddEventAdminWindow::populateList()
{
	this->eventsList->clear();
	std::vector<Event> events = this->servAdmin.servGetAllAdmin();
	for (auto& s : events) {
		this->eventsList->addItem(QString::fromStdString(s.toString()));
	}
}

void AddEventAdminWindow::onAdd()
{
	try
	{
		this->servAdmin.servAddAdmin(
			this->title->text().toStdString(),
			this->description->text().toStdString(),
			this->day->value(),
			this->month->value(),
			this->year->value(),
			this->hour->value(),
			this->minute->value(),
			this->nrPeople->text().toInt(),
			this->link->text().toStdString());
		this->populateList();
		QMessageBox::information(this, "Success", "Event added successfully!");
	}
	catch (const std::exception& ex)
	{
		QMessageBox::warning(this, "Error", QString::fromStdString(ex.what()));
	}
}

void AddEventAdminWindow::onBack()
{
	if (this->parent())
		qobject_cast<QWidget*>(this->parent())->show();
	this->hide();
}

void AddEventAdminWindow::onUndo()
{
	try {
		servAdmin.undo();
		populateList();
		QMessageBox::information(this,"Succes", "Undo");
	}
	catch (const std::exception& ex) {
		QMessageBox::warning(this, "Undo Error", QString::fromStdString(ex.what()));
	}
}

void AddEventAdminWindow::onRedo()
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