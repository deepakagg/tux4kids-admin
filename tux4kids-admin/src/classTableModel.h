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

#ifndef CLASSTABLEMODEL_H
#define CLASSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QPointer>

#include "class.h"

class SchoolDatabase;

class ClassTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	ClassTableModel(QObject *parent = 0);
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	QList<Class> selectedClasses() const;
	void setSelectedClasses(const QList<Class> &selectedClasses);
	void clearSelection();
	Class &at(int i);

	void setSchoolDatabase(SchoolDatabase *schoolDatabase);

	enum ClassField {
		ClassSelected = 0,
		ClassName = 1,
	};
private:
	QPointer<SchoolDatabase> m_schoolDatabase;
	QList<Class> m_classes;
	QList<bool> m_classesSelection;

private slots:
	void addClass(Class & newClass);
	void updateClass(Class &updatedClass);
	void deleteClass(Class &deletedClass);
	void addTeacher(Teacher &teacher);
	void updateTeacher(Teacher &teacher);
	void deleteTeacher(Teacher &teacher);

};

#endif // CLASSTABLEMODEL_H
