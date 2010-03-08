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

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QList>

#include "pluginManager.h"
#include "studentTableModel.h"
#include "classTableModel.h"
#include "teacherTableModel.h"

class SchoolData;

class MainController : public QObject
{
	Q_OBJECT

public:
	MainController(QObject *parent = 0);
	~MainController();

	enum Status {
		NoError,
		InitializtionError
	};

	PluginManager *pluginManager();
	SchoolData *schoolData();
	StudentTableModel *studentTableModel();
	ClassTableModel *classTableModel();
	TeacherTableModel *teacherTableModel();
	Status status() const;

private:

	PluginManager m_pluginManager;
	StudentTableModel m_studentTableModel;
	ClassTableModel m_classTableModel;
	TeacherTableModel m_teacherTableModel;
	QPointer<SchoolData> m_schoolData;
	mutable Status m_status;

};

#endif // MAINCONTROLLER_H
