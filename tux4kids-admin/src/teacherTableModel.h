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

#ifndef TEACHERTABLEMODEL_H
#define TEACHERTABLEMODEL_H

#include <QAbstractTableModel>
#include <QPointer>

#include "teacher.h"

class SchoolDatabase;
class Class;

class TeacherTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	TeacherTableModel(QObject *parent = 0);
	void setSchoolDatabase(SchoolDatabase *schoolDatabase);
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);
	QList<Teacher> selectedTeachers() const;
	void setSelectedTeachers(const QList<Teacher> &selectedTeachers);
	void clearSelection();
	Teacher &at(int i);

	enum TeacherField {
		TeacherSelected = 0,
		TeacherFirstName = 1,
		TeacherLastName = 2
	};

protected:

	QPointer<SchoolDatabase> m_schoolDatabase;
	QList<Teacher> m_teachers;
	QList<bool> m_teachersSelection;

private slots:
	void addTeacher(Teacher &teacher);
	void updateTeacher(Teacher &teacher);
	void deleteTeacher(Teacher &teacher);
	void addClass(Class &newClass);
	void updateClass(Class &updatedClass);
	void deleteClass(Class &deletedClass);

};

#endif // TEACHERTABLEMODEL_H
