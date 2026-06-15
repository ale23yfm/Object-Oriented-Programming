#pragma once
#include <QAbstractTableModel>
#include <vector>
#include "event.h"

class EventTableModel : public QAbstractTableModel
{
private:
    std::vector<Event> events;

public:
    EventTableModel(std::vector<Event> events, QObject* parent = nullptr)
        : QAbstractTableModel(parent), events(events) {
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override
    {
        return events.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override
    {
        return 5;  // title, date, time, people, link
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
    {
        if (role != Qt::DisplayRole) return QVariant();

        Event e = events[index.row()];
        switch (index.column())
        {
        case 0: return QString::fromStdString(e.getTitle());
        case 1: return QString::fromStdString(
            std::to_string(e.getDay()) + "/" +
            std::to_string(e.getMonth()) + "/" +
            std::to_string(e.getYear()));
        case 2: return QString::fromStdString(
            std::to_string(e.getHour()) + ":" +
            std::to_string(e.getMinute()));
        case 3: return e.getNrPeople();
        case 4: return QString::fromStdString(e.getLink());
        }
        return QVariant();
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
    {
        if (role != Qt::DisplayRole) return QVariant();
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0: return "Title";
            case 1: return "Date";
            case 2: return "Time";
            case 3: return "People";
            case 4: return "Link";
            }
        }
        return QVariant();
    }
};