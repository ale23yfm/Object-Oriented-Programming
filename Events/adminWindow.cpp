#include "adminWindow.h"
#include <QTableView>
#include "tableModel.h"

AdminWindow::AdminWindow(ServiceAdmin& servAdmin, QWidget* parent) : QWidget(parent), servAdmin(servAdmin)
{
	this->buildGUI();
	this->populateList();
	this->setWindowFlags(Qt::Window);
	QObject::connect(this->addButton, &QPushButton::clicked,
		this, &AdminWindow::onAdd);
	QObject::connect(this->deleteButton, &QPushButton::clicked,
		this, &AdminWindow::onDelete);
	QObject::connect(this->updateButton, &QPushButton::clicked,
		this, &AdminWindow::onUpdate); 
	QObject::connect(this->backButton, &QPushButton::clicked,
		this, &AdminWindow::onBack);
	QObject::connect(this->chartButton, &QPushButton::clicked,
		this, &AdminWindow::onShow);
	QObject::connect(this->sortedButton, &QRadioButton::clicked,
		this, &AdminWindow::populateList);
	QObject::connect(this->shuffledButton, &QRadioButton::clicked,
		this, &AdminWindow::populateList);

	QObject::connect(this->tableViewButton, &QPushButton::clicked,
		this, &AdminWindow::onShowTable);
}

void AdminWindow::buildGUI()
{
	this->resize(500, 600);
	QVBoxLayout* mainLayout = new QVBoxLayout{ this };
	QGridLayout* rightLayout = new QGridLayout{ this };

	QLabel* label = new QLabel{ "ADMIN MENU" };
	mainLayout->addWidget(label);
	this->eventsList = new QListWidget{};
	mainLayout->addWidget(this->eventsList);

	this->addButton = new QPushButton{ "Add" };
	this->deleteButton = new QPushButton{ "Delete" };
	this->updateButton = new QPushButton{ "Update" };
	this->backButton = new QPushButton{ "Back" };
	this->chartButton = new QPushButton{ "Show Chart" };
	this->sortedButton = new QRadioButton{ "Sorted" };
	this->shuffledButton = new QRadioButton{ "Shuffled" };
	this->tableViewButton = new QPushButton{ "Table View" };

	this->shuffledButton->setChecked(true);
	mainLayout->addWidget(this->sortedButton);
	mainLayout->addWidget(this->shuffledButton);

	rightLayout->addWidget(this->addButton);
	rightLayout->addWidget(this->deleteButton);
	rightLayout->addWidget(this->updateButton);
	rightLayout->addWidget(this->backButton);
	rightLayout->addWidget(this->chartButton);
	rightLayout->addWidget(this->tableViewButton);

	mainLayout->addLayout(rightLayout);
}

void AdminWindow::populateList()
{
	this->eventsList->clear();
	std::vector<Event> events = this->servAdmin.servGetAllAdmin();

	if (this->sortedButton->isChecked())
		std::sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
		return a.getTitle() < b.getTitle();
			});
	for (auto& s : events) {
		this->eventsList->addItem(QString::fromStdString(s.toString()));
	}
}

void AdminWindow::onAdd()
{
	AddEventAdminWindow* w = new AddEventAdminWindow(this->servAdmin, this);
	w->show(); 
	this->hide();
}

void AdminWindow::onDelete()
{
	DeleteEventAdminWindow* w = new DeleteEventAdminWindow(this->servAdmin, this);
	w->show();
	this->hide();
}

void AdminWindow::onUpdate()
{
	UpdateEventAdminWindow* w = new UpdateEventAdminWindow(this->servAdmin, this);
	w->show();
	this->hide();
}

void AdminWindow::onBack()
{
	if (this->parent())
		qobject_cast<QWidget*>(this->parent())->show();
	this->hide();
}

void AdminWindow::onShow()
{
	QGraphicsScene* scene = new QGraphicsScene();
	QGraphicsView* view = new QGraphicsView(scene);

	std::vector<std::string> months = { "Jan","Feb","Mar","Apr","May",
										"Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	int maxHeight = 200;

	for (int m = 1; m <= 12; m++)
	{
		int count = 0;
		for (int i = 0; i < servAdmin.servGetSizeAdmin(); i++)
			if (servAdmin.servGetEventByIndexAdmin(i).getMonth() == m)
				count++;

		int x = (m - 1) * 60;
		int barHeight = count * 20;  

		scene->addRect(x, maxHeight - barHeight, 40, barHeight,
			QPen(Qt::black), QBrush(Qt::darkGreen));

		scene->addText(QString::fromStdString(months[m - 1]))->setPos(x, maxHeight + 5);

		scene->addText(QString::number(count))->setPos(x, maxHeight - barHeight - 20);
	}

	view->setWindowFlags(Qt::Window);
	view->resize(800, 400);
	view->show();

}

void AdminWindow::showEvent(QShowEvent* event)
{
	QWidget::showEvent(event);
	this->populateList();
}		

void AdminWindow::onShowTable()
{
	std::vector<Event> events = servAdmin.servGetAllAdmin();

	EventTableModel* model = new EventTableModel(events);
	QTableView* view = new QTableView();
	view->setModel(model);
	view->setWindowFlags(Qt::Window);
	view->resize(600, 400);
	view->show();
}