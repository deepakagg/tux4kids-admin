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

void TeacherTableModel::setSchoolDatabase(SchoolDatabase *schoolDatabase)
{
	m_schoolDatabase = schoolDatabase;
	m_teachers = m_schoolDatabase->teacherList();
	connect(m_schoolDatabase, SIGNAL(teacherAdded(const Teacher &)),
		this, SLOT(teacherAdded(const Teacher &)));
	connect(m_schoolDatabase, SIGNAL(teacherUpdated(const Teacher &)),
		this, SLOT(updateTeacher(const Teacher &)));
	connect(m_schoolDatabase, SIGNAL(teacherDeleted(const Teacher &)),
		this, SLOT(deleteTeacher(const Teacher &)));

}

void TeacherTableModel::addTeacher(const Teacher &teacher)
{
	beginInsertRows(QModelIndex(), m_teachers.size(), m_teachers.size());
	m_teachers.append(teacher);
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
	endRemoveRows();
}
