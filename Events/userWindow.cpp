#include "userWindow.h"
#include <QTableView>
#include "tableModel.h"

UserWindow::UserWindow(ServiceUser& servUser, ServiceAdmin& servAdmin, QWidget* parent) : QWidget (parent),servUser(servUser), servAdmin(servAdmin)
{
	this->buildGUI();
	this->populateList();
	this->setWindowFlags(Qt::Window);
	QObject::connect(this->addButton, &QPushButton::clicked,
		this, &UserWindow::onAdd);
	QObject::connect(this->deleteButton, &QPushButton::clicked,
		this, &UserWindow::onDelete);
	QObject::connect(this->openButton, &QPushButton::clicked,
		this, &UserWindow::onOpen);
	QObject::connect(this->backButton, &QPushButton::clicked,
		this, &UserWindow::onBack);
	QObject::connect(this->chooseFileButton, &QPushButton::clicked,
		this, &UserWindow::onChooseFile);
	QObject::connect(this->tableViewButton, &QPushButton::clicked,
		this, &UserWindow::onShowTable);
}

void UserWindow::buildGUI()
{
	this->resize(500, 600);
	QVBoxLayout* mainLayout = new QVBoxLayout{ this };
	QGridLayout* rightLayout = new QGridLayout{ this };

	QLabel* label = new QLabel{ "USER MENU" };
	mainLayout->addWidget(label);
	this->eventsList = new QListWidget{};
	mainLayout->addWidget(this->eventsList);

	this->addButton = new QPushButton{ "Add" };
	this->deleteButton = new QPushButton{ "Delete" };
	this->openButton = new QPushButton{ "Open CSV/ HTML" };
	this->backButton = new QPushButton{ "Back" };
	this->tableViewButton = new QPushButton{ "Table View" };

	QHBoxLayout* fileLayout = new QHBoxLayout{};
	this->fileTypeBox = new QComboBox{};
	fileTypeBox->addItem("CSV");
	fileTypeBox->addItem("HTML");

	this->chooseFileButton = new QPushButton{ "Choose File Type" };

	fileLayout->addWidget(new QLabel{ "File type:" });
	fileLayout->addWidget(fileTypeBox);
	fileLayout->addWidget(chooseFileButton);

	mainLayout->addLayout(fileLayout);

	mainLayout->addLayout(rightLayout);
	rightLayout->addWidget(this->addButton);
	rightLayout->addWidget(this->deleteButton);
	rightLayout->addWidget(this->openButton);
	rightLayout->addWidget(this->backButton);
	rightLayout->addWidget(this->tableViewButton);
}

void UserWindow::populateList()
{
	this->eventsList->clear();
	std::vector<Event> events = this->servUser.servGetAllUser();
	for (auto& s : events) {
		this->eventsList->addItem(QString::fromStdString(s.toString()));
	}
}

void UserWindow::onAdd()
{
	BrowseEventsWindow* w = new BrowseEventsWindow(this->servUser, this);
	w->show();
	this->hide();
}

void UserWindow::onDelete()
{
	DeleteEventUserWindow* w = new DeleteEventUserWindow(this->servUser, this->servAdmin, this);
	w->show();
	this->hide();
}

void UserWindow::onOpen()
{
	this->servUser.display();
}

void UserWindow::onBack()
{
	if (this->parent())
		qobject_cast<QWidget*>(this->parent())->show();
	this->hide();
}

void UserWindow::onChooseFile()
{
	QString type = fileTypeBox->currentText();

	if (type == "CSV")
		servUser.setFile(new CSVEventList("events.csv"));
	else
		servUser.setFile(new HTMLEventList("events.html"));

	for (int i = 0; i < servUser.servGetSizeUser(); i++)
		servUser.addToFileList(servUser.servGetEventByIndexUser(i));

	QMessageBox::information(this, "Success", "File type selected!");
}

void UserWindow::showEvent(QShowEvent* event)
{
	QWidget::showEvent(event);
	this->populateList();
}

void UserWindow::onShowTable()
{
	std::vector<Event> events = servUser.servGetAllUser();

	EventTableModel* model = new EventTableModel(events);
	QTableView* view = new QTableView();
	view->setModel(model);
	view->setWindowFlags(Qt::Window);
	view->resize(600, 400);
	view->show();
}