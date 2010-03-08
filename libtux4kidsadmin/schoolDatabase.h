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

#ifndef SCHOOLDATABASE_H
#define SCHOOLDATABASE_H

#include <QObject>
#include <QPointer>

#include "libtux4kidsadmin_global.h"
#include "studentDir.h"

class SchoolDatabasePrivate;
class Class;
class Teacher;

class LIBTUX4KIDSADMIN_SHARED_EXPORT SchoolDatabase : public QObject
{
	Q_OBJECT
public:
	SchoolDatabase(QObject *parent = 0);
	~SchoolDatabase();

	bool open(QString dbFilePath);
	void close();
	bool error();
	QString lastError();
	void addClass(Class &newClass);
	void updateClass(Class &updatedClass);
	void deleteClass(Class &deletedClass);

	void addTeacher(Teacher &newTeacher);
	void updateTeacher(Teacher &updatedTeacher);
	void deleteTeacher(Teacher &deletedTeacher);

	QList<Class> classList() const;
	QList<Teacher> teacherList() const;
	void synchronizeStudents(const QList<StudentDir *> &studentList);

protected:
	SchoolDatabasePrivate * const d_ptr;
	SchoolDatabase(SchoolDatabasePrivate &dd, QObject *parent = 0);

signals:
	void classAdded(Class &newClass);
	void classUpdated(Class &updatedClass);
	void classDeleted(Class &deletedClass);

	void teacherAdded(Teacher &newTeacher);
	void teacherUpdated(Teacher &updatedTeacher);
	void teacherDeleted(Teacher &deletedTeacher);

private:
	Q_DECLARE_PRIVATE(SchoolDatabase)
	Q_DISABLE_COPY(SchoolDatabase)
};

#endif // SCHOOLDATABASE_H
