#pragma once
#include "Service.h"
#include "ideea.h"
#include <QAbstractTableModel>

class Model : public QAbstractTableModel
{
	Q_OBJECT
private:
	Service& serv;
	std::vector<Idea*> ideas;

public:
	Model(Service& serv, QObject* parent = nullptr) :QAbstractTableModel(parent), serv(serv) {
		this->ideas = this->serv.getIdeas();
	}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override
	{
		return ideas.size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override
	{
		return 4;
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
	{
		if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
			return QVariant();
		switch (section)
		{
		case 0: return "Description";
		case 1: return "Status";
		case 2: return "Creator";
		case 3: return "Act";
		}
		return QVariant();
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
	{
		if (role != Qt::DisplayRole)
			return QVariant();

		Idea* idea = ideas[index.row()];
		switch (index.column())
		{
		case 0: return QString::fromStdString(idea->getDesc());
		case 1: return QString::fromStdString(idea->getStatus());
		case 2: return QString::fromStdString(idea->getCreator());
		case 3: return QString::number(idea->getAct());
		}
		return QVariant();
	}

	void update()
	{
		this->ideas = this->serv.getIdeas();
		emit layoutChanged();
	}
};