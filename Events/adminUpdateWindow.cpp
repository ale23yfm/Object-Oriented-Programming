#include "adminUpdateWindow.h"

UpdateEventAdminWindow::UpdateEventAdminWindow(ServiceAdmin& servAdmin, QWidget* parent) :QWidget(parent), servAdmin(servAdmin)
{
	this->buildGUI();
	this->populateList();
	this->setWindowFlags(Qt::Window);

	QObject::connect(this->updateButton, &QPushButton::clicked,
		this, &UpdateEventAdminWindow::onUpdate);
	QObject::connect(this->backButton, &QPushButton::clicked,
		this, &UpdateEventAdminWindow::onBack);
	QObject::connect(this->undoButton, &QPushButton::clicked, this, &UpdateEventAdminWindow::onUndo);
	QObject::connect(this->redoButton, &QPushButton::clicked, this, &UpdateEventAdminWindow::onRedo);
	QShortcut* undoShortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
	QShortcut* redoShortcut = new QShortcut(QKeySequence("Ctrl+Y"), this);
	QObject::connect(undoShortcut, &QShortcut::activated, this, &UpdateEventAdminWindow::onUndo);
	QObject::connect(redoShortcut, &QShortcut::activated, this, &UpdateEventAdminWindow::onRedo);
}

void UpdateEventAdminWindow::buildGUI()
{
	QHBoxLayout* mainLayout = new QHBoxLayout{ this };
	this->eventsList = new QListWidget{};
	this->updateButton = new QPushButton{ "UPDATE" };
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

	this->newDescription = new QLineEdit{};
	rightLayout->addWidget(new QLabel{ "newDescription" }, 6, 0);
	rightLayout->addWidget(this->newDescription, 6, 1);

	this->newNrPeople = new QLineEdit{};
	rightLayout->addWidget(new QLabel{ "newNrPeople" }, 7, 0);
	rightLayout->addWidget(this->newNrPeople, 7, 1);

	this->newLink = new QLineEdit{};
	rightLayout->addWidget(new QLabel{ "newLink" }, 8, 0);
	rightLayout->addWidget(this->newLink, 8, 1);

	rightLayout->addWidget(this->updateButton, 9, 0);
	rightLayout->addWidget(this->backButton, 9, 1);

	rightLayout->addWidget(this->undoButton, 10, 0);
	rightLayout->addWidget(this->redoButton, 10, 1);

	mainLayout->addLayout(rightLayout);
}

void UpdateEventAdminWindow::populateList()
{
	this->eventsList->clear();
	std::vector<Event> events = this->servAdmin.servGetAllAdmin();
	for (auto& s : events) {
		this->eventsList->addItem(QString::fromStdString(s.toString()));
	}
}

void UpdateEventAdminWindow::onUpdate()
{
	std::string title = this->title->text().toStdString();
	int day = this->day->value();
	int month = this->month->value();
	int year = this->year->value();
	int hour = this->hour->value();
	int minute = this->minute->value();

	int index = this->servAdmin.servFindEventAdmin(title, day, month, year, hour, minute);
	if (index == -1)
	{
		QMessageBox::warning(this, "Error", "Event not found!");
		return;
	}

	Event& oldEvent = this->servAdmin.servGetEventByIndexAdmin(index);

	std::string newDescription = this->newDescription->text().toStdString();
	int newNrPeople = this->newNrPeople->text().toInt();
	std::string newLink = this->newLink->text().toStdString();

	if (newDescription.empty()) newDescription = oldEvent.getDescription();
	if (newLink.empty()) newLink = oldEvent.getLink();
	if (newNrPeople == 0) newNrPeople = oldEvent.getNrPeople();

	Event newEvent{ title, newDescription, day, month, year, hour, minute , newNrPeople, newLink };

	try
	{
		this->servAdmin.servUpdateAdmin(
			this->title->text().toStdString(),
			this->day->value(),
			this->month->value(),
			this->year->value(),
			this->hour->value(),
			this->minute->value(),
			newEvent);
		this->populateList();
		QMessageBox::information(this, "Success", "Event updated successfully!");
	}
	catch (const std::exception& ex)
	{
		QMessageBox::warning(this, "Error", QString::fromStdString(ex.what()));
	}
}

void UpdateEventAdminWindow::onBack()
{
	if (this->parent())
		qobject_cast<QWidget*>(this->parent())->show();
	this->hide();
}
void UpdateEventAdminWindow::onUndo()
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

void UpdateEventAdminWindow::onRedo()
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