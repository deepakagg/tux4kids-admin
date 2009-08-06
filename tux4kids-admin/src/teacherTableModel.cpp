#include "teacherTableModel.h"
#include "schoolDatabase.h"
#include "class.h"

#include <QDebug>
#include <QStringList>

TeacherTableModel::TeacherTableModel(QObject *parent)
		: QAbstractTableModel(parent)
{
}

int TeacherTableModel::columnCount(const QModelIndex &parent) const
{
	return 3;
}

int TeacherTableModel::rowCount(const QModelIndex &parent) const
{
	return m_teachers.size();
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

QVariant TeacherTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
		return QVariant();

	if (orientation == Qt::Vertical) {
		return section + 1;
	} else if (orientation == Qt::Horizontal) {
		switch (section) {
		case TeacherFirstName:
			return tr("First name");
		case TeacherLastName:
			return tr("Last name");
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
	for (int i = 0; i < m_teachers.size(); ++i) {
		m_teachersSelection.append(false);
	}
	connect(m_schoolDatabase, SIGNAL(teacherAdded(const Teacher &)),
		this, SLOT(addTeacher(const Teacher &)));
	connect(m_schoolDatabase, SIGNAL(teacherUpdated(const Teacher &)),
		this, SLOT(updateTeacher(const Teacher &)));
	connect(m_schoolDatabase, SIGNAL(teacherDeleted(const Teacher &)),
		this, SLOT(deleteTeacher(const Teacher &)));
	connect(schoolDatabase, SIGNAL(classAdded()),
		this, SLOT(addClass(const Class &)));
	connect(schoolDatabase, SIGNAL(classUpdated(const Class &)),
		this, SLOT(updateClass(const Class &)));
	connect(schoolDatabase, SIGNAL(classDeleted(const Class &)),
		this, SLOT(deleteClass(const Class &)));
	reset();

}

void TeacherTableModel::addTeacher(Teacher &teacher)
{
	beginInsertRows(QModelIndex(), m_teachers.size(), m_teachers.size());
	m_teachers.append(teacher);
	m_teachersSelection.append(false);
	endInsertRows();
}

void TeacherTableModel::updateTeacher(Teacher &teacher)
{
	int pos = m_teachers.indexOf(teacher);
	if (pos != -1) {
		m_teachers[pos] = teacher;
		emit dataChanged(index(pos, 0), index(pos, columnCount() - 1));
	}
}

void TeacherTableModel::deleteTeacher(Teacher &teacher)
{
	int pos = m_teachers.indexOf(teacher);
	if (pos != -1) {
		beginRemoveRows(QModelIndex(), pos, pos);
		m_teachers.removeAt(pos);
		m_teachersSelection.removeAt(pos);
		endRemoveRows();
	}
}

QList<Teacher> TeacherTableModel::selectedTeachers() const
{
	QList<Teacher> result;
	for (int i = 0; i < m_teachersSelection.size(); ++i) {
		if (m_teachersSelection.at(i)) {
			result.append(m_teachers.at(i));
		}
	}
	return result;
}

void TeacherTableModel::setSelectedTeachers(const QList<Teacher> &selectedTeachers)
{
	for (int i = 0; i < m_teachers.size(); ++i) {
		if (selectedTeachers.contains(m_teachers.at(i))) {
			m_teachersSelection[i] = true;
		} else {
			m_teachersSelection[i] = false;
		}
	}
	emit dataChanged(index(0, TeacherSelected), index(rowCount() - 1, TeacherSelected));
}

void TeacherTableModel::clearSelection()
{
	for (int i = 0; i < m_teachersSelection.size(); ++i) {
		m_teachersSelection[i] = false;
	}
	emit dataChanged(index(0, TeacherSelected), index(rowCount() - 1, TeacherSelected));
}

void TeacherTableModel::addClass(Class &newClass)
{
	for (int i = 0; i < m_teachers.size(); ++i) {
		if (newClass.teachers()->contains(m_teachers.at(i))) {
			m_teachers[i].classes()->append(newClass);
		}
	}
}

void TeacherTableModel::updateClass(Class &updatedClass)
{
	for(int i = 0; i < m_teachers.size(); ++i) {
		m_teachers[i].classes()->removeOne(updatedClass);
		if (updatedClass.teachers()->contains(m_teachers.at(i))) {
			m_teachers[i].classes()->append(updatedClass);
		}
	}
}

void TeacherTableModel::deleteClass(Class &deletedClass)
{
	for (int i = 0; i < m_teachers.size(); ++i) {
		m_teachers[i].classes()->removeOne(deletedClass);
	}
}

