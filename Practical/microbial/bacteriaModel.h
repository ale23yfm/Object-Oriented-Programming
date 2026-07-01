// bacteriamodel.h
#pragma once
#include <QAbstractTableModel>
#include "service.h"

class BacteriaModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    Service& serv;
    std::vector<Bacterium*> bacteria; // current filtered list

public:
    BacteriaModel(Service& serv, QObject* parent = nullptr)
        : QAbstractTableModel(parent), serv(serv)
    {
        bacteria = serv.getBacterias();
    }

    // --- required overrides ---

    int rowCount(const QModelIndex& parent = QModelIndex()) const override
    {
        return bacteria.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override
    {
        return 4; // name, species, size, diseases
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
    {
        if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
            return QVariant();
        switch (section)
        {
        case 0: return "Name";
        case 1: return "Species";
        case 2: return "Size";
        case 3: return "Diseases";
        }
        return QVariant();
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
    {
        if (!index.isValid() || role != Qt::DisplayRole)
            return QVariant();

        Bacterium* b = bacteria[index.row()];
        switch (index.column())
        {
        case 0: return QString::fromStdString(b->getName());
        case 1: return QString::fromStdString(b->getSpecies());
        case 2: return b->getSize();
        case 3: return QString::fromStdString(joinDiseases(b->getDiseases()));
        }
        return QVariant();
    }

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override
    {
        if (!index.isValid() || role != Qt::EditRole)
            return false;

        Bacterium* b = bacteria[index.row()];
        switch (index.column())
        {
        case 0: b->setName(value.toString().toStdString()); break;
        case 1: b->setSpecies(value.toString().toStdString()); break;
        case 2: b->setSize(value.toInt()); break;
        case 3: break; // diseases edited separately
        }
        emit dataChanged(index, index);
        return true;
    }

    Qt::ItemFlags flags(const QModelIndex& index) const override
    {
        if (!index.isValid()) return Qt::NoItemFlags;
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
    }

     //--- filter ---

    void filterBySpecies(const std::string& species)
    {
        if (species.empty())
            bacteria = serv.getBacterias();
        else
            bacteria = serv.getBacteriaBySpecies(species);
        emit layoutChanged();
    }

    void refresh()
    {
        bacteria = serv.getBacterias();
        emit layoutChanged();
    }

    Bacterium* getBacteriumAt(int row)
    {
        if (row < 0 || row >= bacteria.size()) return nullptr;
        return bacteria[row];
    }

private:
    std::string joinDiseases(const std::vector<std::string>& diseases) const
    {
        std::string result;
        for (int i = 0; i < diseases.size(); i++)
        {
            result += diseases[i];
            if (i < diseases.size() - 1) result += ", ";
        }
        return result;
    }
};