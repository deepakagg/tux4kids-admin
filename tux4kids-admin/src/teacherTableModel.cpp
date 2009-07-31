#include "teacherTableModel.h"
#include "schoolDatabase.h"

TeacherTableModel::TeacherTableModel(QObject *parent)
		: QAbstractTableModel(parent)
{
}

int TeacherTableModel::columnCount(const QModelIndex &parent) const
{
	return m_teachers.size();
}

int TeacherTableModel::rowCount(const QModelIndex &parent) const
{
	return 3;
}

QVariant TeacherTableModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (index.row() >= rowCount())
		return QVariant();

	if (index.column() >= columnCount())
		return QVariant();

	if (role == Qt::DisplayRole) {
		switch (index.column()) {
		case TeacherFirstName:
			return m_teachers.at(index.row()).firstName();
		case TeacherLastName:
			return m_teachers.at(index.row()).lastName();
		}
	} else if (role == Qt::CheckStateRole) {
		if (index.column() == TeacherSelected) {
			if (m_teachersSelection[index.row()]) {
				return Qt::Checked;
			} else {
				return Qt::Unchecked;
			}
		}
	}
	return QVariant();
}

Qt::ItemFlags TeacherTableModel::flags(const QModelIndex &index) const
{
	Qt::ItemFlags result;
	result = Qt::ItemIsEnabled
			| Qt::ItemIsSelectable;
	if (index.column() == TeacherSelected) {
		result |= (Qt::ItemIsUserCheckable | Qt::ItemIsEditable);
	}
	return result;
}

bool TeacherTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (role == Qt::CheckStateRole && index.column() == TeacherSelected) {
		m_teachersSelection[index.row()] = !m_teachersSelection[index.row()];
		emit dataChanged(index, index);
		return true;
	}
	return false;
}

void TeacherTableModel::setSchoolDatabase(SchoolDatabase *schoolDatabase)
{
	m_schoolDatabase = schoolDatabase;
	m_teachers = m_schoolDatabase->teacherList();
	m_teachersSelection.clear();
	for (int i = 0; i< m_teachers.size(); i++) {
		m_teachersSelection.append(false);
	}
	connect(m_schoolDatabase, SIGNAL(teacherAdded(const Teacher &)),
		this, SLOT(teacherAdded(const Teacher &)));
	connect(m_schoolDatabase, SIGNAL(teacherUpdated(const Teacher &)),
		this, SLOT(updateTeacher(const Teacher &)));
	connect(m_schoolDatabase, SIGNAL(teacherDeleted(const Teacher &)),
		this, SLOT(deleteTeacher(const Teacher &)));
	reset();

}

void TeacherTableModel::addTeacher(const Teacher &teacher)
{
	beginInsertRows(QModelIndex(), m_teachers.size(), m_teachers.size());
	m_teachers.append(teacher);
	m_teachersSelection.append(false);
	endInsertRows();
}

void TeacherTableModel::updateTeacher(const Teacher &teacher)
{
	int pos = m_teachers.indexOf(teacher);
	m_teachers[pos] = teacher;
	emit dataChanged(index(pos, 0), index(pos, columnCount() - 1));
}

void TeacherTableModel::deleteTeacher(const Teacher &teacher)
{
	int pos = m_teachers.indexOf(teacher);
	beginRemoveRows(QModelIndex(), pos, pos);
	m_teachers.removeAt(pos);
	m_teachersSelection.removeAt(pos);
	endRemoveRows();
}
