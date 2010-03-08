/*

This file is part of Libtux4kidsadmin

Libtux4kidsadmin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Libtux4kidsadmin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Libtux4kidsadmin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#ifndef SCHOOLDATAPRIVATE_P_H
#define SCHOOLDATAPRIVATE_P_H

#include <QtGlobal>
#include <QDir>
#include <QList>
#include <QPointer>
#include <QHash>

#include "schoolData.h"
#include "schoolDatabase.h"

class QString;
class ProfileDir;
class StudentDir;
class QSettings;
class ComputerDir;

class SchoolDataPrivate
{
public:
	Q_DECLARE_PUBLIC(SchoolData)

	SchoolDataPrivate(QString path);
	virtual ~SchoolDataPrivate();

	QString nextStudentDir() const;
	void loadStudentDirs();
	void createComputerDirs();

	SchoolData *q_ptr;

	QDir mainDir;
	QDir studentsDir;
	QDir computersDir;
	SchoolData::Status status;
	QList<StudentDir *> students;
	QList<ProfileDir *> profiles;
	QList<ComputerDir *> computers;
	QSettings *attributes;

	SchoolDatabase database;
};

#endif // SCHOOLDATAPRIVATE_P_H
