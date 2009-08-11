#include "studentTableModel.h"
#include "schoolData.h"
#include "studentDir.h"
#include "schoolDatabase.h"
#include "class.h"

#include <QDebug>
#include <QStringList>

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
	return 3;
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
	} else if (role == Qt::CheckStateRole) {
		if (index.column() == StudentSelected) {
			if (m_studentsSelection[index.row()]) {
				return Qt::Checked;
			} else {
				return Qt::Unchecked;
			}
		}
	}
	return QVariant();
}

Qt::ItemFlags StudentTableModel::flags(const QModelIndex &index) const
{
	Qt::ItemFlags result;
	result = Qt::ItemIsEnabled
			| Qt::ItemIsSelectable;
	if (index.column() == StudentSelected) {
		result |= (Qt::ItemIsUserCheckable | Qt::ItemIsEditable);
	}
	return result;
}

bool StudentTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (role == Qt::CheckStateRole && index.column() == StudentSelected) {
		m_studentsSelection[index.row()] = !m_studentsSelection[index.row()];
		emit dataChanged(index, index);
		return true;
	}
	return false;
}

void StudentTableModel::setSchoolData(SchoolData *schoolData)
{
	m_students = schoolData->students();

	for (int i = 0; i < m_students.size(); i++) {
		m_studentsSelection.append(false);
	}
	connect(schoolData, SIGNAL(studentAdded(StudentDir*)), this,
		SLOT(addStudent(StudentDir*)));
	connect(schoolData->schoolDatabase(), SIGNAL(classAdded(Class &)), this, SLOT(addClass(Class &)));
	connect(schoolData->schoolDatabase(), SIGNAL(classUpdated(Class &)), this, SLOT(updateClass(Class &)));
	connect(schoolData->schoolDatabase(), SIGNAL(classDeleted(Class &)), this, SLOT(deleteClass(Class &)));

	reset();
}

void StudentTableModel::addStudent(StudentDir *newStudent)
{
	beginInsertRows(QModelIndex(), m_students.size(), m_students.size());
	m_students.append(newStudent);
	endInsertRows();
}

QStringList StudentTableModel::selectedStudentsDirNames() const
{
	QStringList result;
	for(int i = 0; i < m_studentsSelection.size(); i++) {
		if (m_studentsSelection.at(i)) {
			result.append(m_students.at(i)->dirName());
		}
	}
	return result;
}

QList<StudentDir *> StudentTableModel::selectedStudents() const
{
	QList<StudentDir *> result;
	for(int i = 0; i < m_studentsSelection.size(); i++) {
		if (m_studentsSelection.at(i)) {
			result.append(m_students.at(i));
		}
	}
	return result;
}

void StudentTableModel::setSelectedStudents(const QStringList &selectedStudentsDirNames)
{
	for (int i = 0; i < m_students.size(); ++i) {
		if (selectedStudentsDirNames.contains(m_students.at(i)->dirName())) {
			m_studentsSelection[i] = true;
		} else {
			m_studentsSelection[i] = false;
		}
	}
	emit dataChanged(index(0, StudentSelected), index(rowCount() - 1, StudentSelected));
}

void StudentTableModel::clearSelection()
{
	for (int i = 0; i < m_studentsSelection.size(); ++i) {
		m_studentsSelection[i] = false;
	}

	emit dataChanged(index(0, StudentSelected), index(rowCount() - 1, StudentSelected));
}

void StudentTableModel::addClass(Class &newClass)
{
	foreach (StudentDir * student, m_students) {
		if (newClass.students()->contains(student->dirName())) {
			student->classes()->append(newClass);
		}
	}
}

void StudentTableModel::updateClass(Class &updatedClass)
{
	foreach (StudentDir *student, m_students) {
		student->classes()->removeOne(updatedClass);
		if (updatedClass.students()->contains(student->dirName())) {
			student->classes()->append(updatedClass);
		}
	}
}

void StudentTableModel::deleteClass(Class &deletedClass)
{
	foreach (StudentDir *student, m_students) {
		student->classes()->removeOne(deletedClass);
	}
}

