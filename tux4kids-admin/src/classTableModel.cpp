/*

This file is part of Tux4kids-admin

Tux4kids-admin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#include "classTableModel.h"
#include "schoolDatabase.h"
#include "teacher.h"

#include <QDebug>

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
	for (int i = 0; i < m_classes.size(); ++i) {
		m_classesSelection.append(false);
	}

	connect(m_schoolDatabase, SIGNAL(classAdded(Class &)), this, SLOT(addClass(Class &)));
	connect(m_schoolDatabase, SIGNAL(classUpdated(Class &)), this, SLOT(updateClass(Class &)));
	connect(m_schoolDatabase, SIGNAL(classDeleted(Class &)), this, SLOT(deleteClass(Class &)));
	connect(m_schoolDatabase, SIGNAL(teacherAdded(Teacher &)), this, SLOT(addTeacher(Teacher &)));
	connect(m_schoolDatabase, SIGNAL(teacherUpdated(Teacher &)), this, SLOT(updateTeacher(Teacher &)));
	connect(m_schoolDatabase, SIGNAL(teacherDeleted(Teacher &)), this, SLOT(deleteTeacher(Teacher &)));


	reset();
}

void ClassTableModel::addClass(Class & newClass)
{
	beginInsertRows(QModelIndex(), m_classes.size(), m_classes.size());
	m_classes.append(newClass);
	m_classesSelection.append(false);
	endInsertRows();
}

void ClassTableModel::updateClass(Class &updatedClass)
{
	int pos = m_classes.indexOf(updatedClass);
	if (pos != -1) {
		m_classes[pos] = updatedClass;
		emit dataChanged(index(pos, 0) , index(pos, columnCount() - 1));
	}
}

void ClassTableModel::deleteClass(Class &deletedClass)
{
	int pos = m_classes.indexOf(deletedClass);
	if (pos != -1) {
		beginRemoveRows(QModelIndex(), pos, pos);
		m_classes.removeAt(pos);
		m_classesSelection.removeAt(pos);
		endRemoveRows();
	}
}

QList<Class> ClassTableModel::selectedClasses() const
{
	QList<Class> result;
	for (int i = 0; i < m_classesSelection.size(); ++i) {
		if (m_classesSelection.at(i)) {
			result.append(m_classes.at(i));
		}
	}
	return result;
}

void ClassTableModel::setSelectedClasses(const QList<Class> &selectedClasses)
{
	for (int i = 0; i < m_classes.size(); ++i) {
		if (selectedClasses.contains(m_classes.at(i))) {
			m_classesSelection[i] = true;
		} else {
			m_classesSelection[i] = false;
		}
	}
	emit dataChanged(index(0, ClassSelected), index(rowCount() - 1, ClassSelected));
}

void ClassTableModel::clearSelection()
{
	for (int i = 0; i < m_classesSelection.size(); ++i) {
		m_classesSelection[i] = false;
	}
	emit dataChanged(index(0, ClassSelected), index(rowCount() - 1, ClassSelected));
}

Class &ClassTableModel::at(int i)
{
	return m_classes[i];
}

void ClassTableModel::addTeacher(Teacher &teacher)
{
	for (int i = 0; i < m_classes.size(); ++i) {
		if (teacher.classes()->contains(m_classes.at(i))) {
			m_classes[i].teachers()->append(teacher);
		}
	}
}

void ClassTableModel::updateTeacher(Teacher &teacher)
{
	for (int i = 0; i < m_classes.size(); ++i) {
		m_classes[i].teachers()->removeOne(teacher);
		if (teacher.classes()->contains(m_classes.at(i))) {
			m_classes[i].teachers()->append(teacher);
		}
	}
}

void ClassTableModel::deleteTeacher(Teacher &teacher)
{
	for (int i = 0; i < m_classes.size(); ++i) {
		m_classes[i].teachers()->removeOne(teacher);
	}
}

