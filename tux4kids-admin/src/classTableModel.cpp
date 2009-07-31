#include "classTableModel.h"
#include "schoolDatabase.h"

ClassTableModel::ClassTableModel(QObject *parent)
		: QAbstractTableModel(parent)
{
}

int ClassTableModel::columnCount(const QModelIndex &parent) const
{
	return 2;
}

int ClassTableModel::rowCount(const QModelIndex &parent) const
{
	return m_classes.size();
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
	} else if (role == Qt::CheckStateRole) {
		if (index.column() == ClassSelected) {
			if (m_classesSelection.at(index.row())) {
				return Qt::Checked;
			} else {
				return Qt::Unchecked;
			}
		}
	}
	return QVariant();
}

QVariant ClassTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
		return QVariant();

	if (orientation == Qt::Vertical) {
		return section + 1;
	} else if (orientation == Qt::Horizontal) {
		switch (section) {
		case ClassName:
			return tr("Class name");
		}
	}

	return QVariant();
}

Qt::ItemFlags ClassTableModel::flags(const QModelIndex &index) const
{
	Qt::ItemFlags result;
	result = Qt::ItemIsEnabled
			| Qt::ItemIsSelectable;
	if (index.column() == ClassSelected) {
		result |= (Qt::ItemIsUserCheckable | Qt::ItemIsEditable);
	}
	return result;
}

bool ClassTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (role == Qt::CheckStateRole && index.column() == ClassSelected) {
		m_classesSelection[index.row()] = !m_classesSelection[index.row()];
		emit dataChanged(index, index);
		return true;
	}
	return false;
}

void ClassTableModel::setSchoolDatabase(SchoolDatabase *schoolDatabase)
{
	m_schoolDatabase = schoolDatabase;
	m_classes = m_schoolDatabase->classList();
	m_classesSelection.clear();
	for (int i = 0; i < m_classes.size(); i++) {
		m_classesSelection.append(false);
	}
	reset();
}

