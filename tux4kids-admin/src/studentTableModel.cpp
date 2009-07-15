#include "studentTableModel.h"
#include "schoolData.h"
#include "studentDir.h"
#include <QDebug>

StudentTableModel::StudentTableModel(QObject *parent)
		: QAbstractTableModel(parent)
{
}

StudentTableModel::~StudentTableModel()
{
}

int StudentTableModel::rowCount(const QModelIndex &parent) const
{
	return m_students.size();
}


int StudentTableModel::columnCount(const QModelIndex &parent) const
{
	return 2;
}

QVariant StudentTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
		return QVariant();

	if (orientation == Qt::Vertical) {
		return section + 1;
	} else if (orientation == Qt::Horizontal) {
		switch (section) {
		case StudentFirstName:
			return tr("Name");
		case StudentLastName:
			return tr("Surname");
		}
	}

	return QVariant();
}

QVariant StudentTableModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (index.row() >= rowCount())
		return QVariant();

	if (index.column() >= columnCount())
		return QVariant();

	if (role == Qt::DisplayRole) {
		switch (index.column()) {
		case StudentFirstName:
			return m_students.at(index.row())->firstName();
		case StudentLastName:
			return m_students.at(index.row())->lastName();
		}
	}
	return QVariant();
}

void StudentTableModel::setSchoolData(const SchoolData *schoolData)
{
	m_students = schoolData->students();
	connect(schoolData, SIGNAL(studentAdded(StudentDir*)), this,
		SLOT(addStudent(StudentDir*)));
	reset();
}

void StudentTableModel::addStudent(StudentDir *newStudent)
{
	beginInsertRows(QModelIndex(), m_students.size(), m_students.size());
	m_students.append(newStudent);
	endInsertRows();
}
