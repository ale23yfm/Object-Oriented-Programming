#include "userAddWindow.h"

BrowseEventsWindow::BrowseEventsWindow(ServiceUser& servUser, QWidget* parent) : QWidget(parent), servUser(servUser)
{
	this->setWindowFlags(Qt::Window);
	this->buildGUI();
	QObject::connect(this->searchButton, &QPushButton::clicked,
		this, &BrowseEventsWindow::onSearch);
	QObject::connect(this->addButton, &QPushButton::clicked,
		this, &BrowseEventsWindow::onAdd);
	QObject::connect(this->nextButton, &QPushButton::clicked,
		this, &BrowseEventsWindow::onNext);
	QObject::connect(this->exitButton, &QPushButton::clicked,
		this, &BrowseEventsWindow::onBack);
	QObject::connect(this->undoButton, &QPushButton::clicked, this, &BrowseEventsWindow::onUndo);
	QObject::connect(this->redoButton, &QPushButton::clicked, this, &BrowseEventsWindow::onRedo);
	QShortcut* undoShortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
	QShortcut* redoShortcut = new QShortcut(QKeySequence("Ctrl+Y"), this);
	QObject::connect(undoShortcut, &QShortcut::activated, this, &BrowseEventsWindow::onUndo);
	QObject::connect(redoShortcut, &QShortcut::activated, this, &BrowseEventsWindow::onRedo);
}

void BrowseEventsWindow::displayCurrent()
{
	Event e = this->eventList[this->currentIndex];

	this->titleLabel->setText(QString::fromStdString(e.getTitle()));
	this->descriptionLabel->setText(QString::fromStdString(e.getDescription()));
	this->dateLabel->setText(QString::fromStdString(std::to_string(e.getHour()) + ":" + std::to_string(e.getMinute())));
	this->dateLabel->setText(QString::fromStdString(std::to_string(e.getDay()) + "/" + std::to_string(e.getMonth()) + "/" + std::to_string(e.getYear())));
	this->timeLabel->setText(QString::fromStdString(e.getDescription()));
	this->nrPeopleLabel->setText(QString::fromStdString(std::to_string(e.getNrPeople())));

	e.play();
}

void BrowseEventsWindow::buildGUI()
{
	QVBoxLayout* mainLayout = new QVBoxLayout{ this };
	QHBoxLayout* topLayout = new QHBoxLayout{ this };
	this->month = new QSpinBox{};
	this->month->setRange(0, 12);
	this->searchButton = new QPushButton{ "Search" };
	topLayout->addWidget(new QLabel{ "Month (0 = all)" });
	topLayout->addWidget(this->month);
	topLayout->addWidget(this->searchButton);
	mainLayout->addLayout(topLayout);

	this->titleLabel = new QLabel{ "-" };
	this->descriptionLabel = new QLabel{ "-" };
	this->dateLabel = new QLabel{ "-" };
	this->timeLabel = new QLabel{ "-" };
	this->nrPeopleLabel = new QLabel{ "-" };

	QGridLayout* middleLayout = new QGridLayout{ };
	middleLayout->addWidget(new QLabel{ "Title:" }, 0, 0);
	middleLayout->addWidget(this->titleLabel, 0, 1);
	middleLayout->addWidget(new QLabel{ "Description:" }, 1, 0);
	middleLayout->addWidget(this->descriptionLabel, 1, 1);
	middleLayout->addWidget(new QLabel{ "Date:" }, 2, 0);
	middleLayout->addWidget(this->dateLabel, 2, 1);
	middleLayout->addWidget(new QLabel{ "Time:" }, 3, 0);
	middleLayout->addWidget(this->timeLabel, 3, 1);
	middleLayout->addWidget(new QLabel{ "NrPeople:" }, 4, 0);
	middleLayout->addWidget(this->nrPeopleLabel, 4, 1);

	mainLayout->addLayout(middleLayout);

	QGridLayout* buttomLayout = new QGridLayout{};
	this->addButton = new QPushButton{ "Add" };
	buttomLayout->addWidget(this->addButton, 0, 0);
	this->nextButton = new QPushButton{ "Next" };
	buttomLayout->addWidget(this->nextButton, 0, 1);
	this->exitButton = new QPushButton{ "Stop" };
	buttomLayout->addWidget(this->exitButton, 0, 2); 
	this->undoButton = new QPushButton{ "Undo" };
	this->redoButton = new QPushButton{ "Redo" };
	buttomLayout->addWidget(this->undoButton, 1, 0);
	buttomLayout->addWidget(this->redoButton, 1, 1);

	mainLayout->addLayout(buttomLayout);
}

void BrowseEventsWindow::onSearch()
{
	int m = this->month->value();
	this->eventList = this->servUser.servFindEventbyMonthUser(m);
	if (this->eventList.empty())
	{
		QMessageBox::warning(this, "Warning", "There are no events");
		return;
	}
	this->currentIndex = 0;
	displayCurrent();
}

void BrowseEventsWindow::onAdd()
{
	if (eventList.empty())
		return;

	Event e = this->eventList[this->currentIndex];
	if (this->servUser.servFindUser(e) == -1)
	{
		this->servUser.servAddUser(e);
		this->servUser.addToFileList(e); 
		QMessageBox::information(this, "Success", "Event added successfully!");
	}
	else QMessageBox::warning(this, "Warning", "You already added this event");
}

void BrowseEventsWindow::onNext()
{
	if (eventList.empty())
		return;
	this->currentIndex = (this->currentIndex + 1) % eventList.size();
	displayCurrent();
}

void BrowseEventsWindow::onBack()
{
	if (this->parent())
		qobject_cast<QWidget*>(this->parent())->show();
	this->hide();
}

void BrowseEventsWindow::onUndo()
{
	try {
		servUser.undo();
		//populateList();
		QMessageBox::information(this, "Succes", "Undo");
	}
	catch (const std::exception& ex) {
		QMessageBox::warning(this, "Undo Error", QString::fromStdString(ex.what()));
	}
}

void BrowseEventsWindow::onRedo()
{
	try {
		servUser.redo();
		//populateList();
		QMessageBox::information(this, "Succes", "Redo");
	}
	catch (const std::exception& ex) {
		QMessageBox::warning(this, "Redo Error", QString::fromStdString(ex.what()));
	}
}