#include "classTableModel.h"
#include "schoolDatabase.h"

ClassTableModel::ClassTableModel(QObject *parent)
		: QAbstractTableModel(parent)
{
}

QVariant ClassTableModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (index.row() >= rowCount())
		return QVariant();

	if (index.column() >= columnCount())
		return QVariant();

	if (role == Qt::DisplayRole) {
		switch (index.column()) {
		case ClassName:
			return m_classes.at(index.row()).name();
		}
	}

	return QVariant();
}

int ClassTableModel::columnCount(const QModelIndex &parent) const
{
	return 2;
}

int ClassTableModel::rowCount(const QModelIndex &parent) const
{
	return m_classes.size();
}

void ClassTableModel::setSchoolDatabase(SchoolDatabase *schoolDatabase)
{
	m_schoolDatabase = schoolDatabase;
}

