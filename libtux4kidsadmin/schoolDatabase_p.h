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

#ifndef SCHOOLDATABASE_P_H
#define SCHOOLDATABASE_P_H

#include <QtGlobal>
#include <QSqlDatabase>

#include "libtux4kidsadmin_global.h"

class SchoolDatabase;

class LIBTUX4KIDSADMIN_SHARED_EXPORT SchoolDatabasePrivate
{
public:
	Q_DECLARE_PUBLIC(SchoolDatabase)

	SchoolDatabasePrivate();
	virtual ~SchoolDatabasePrivate();

	void createTables();
	void createTriggers();
	void addClass(Class &newClass);
	void updateClass(Class &updatedClass);
	void deleteClass(Class &deletedClass);

	void addTeacher(Teacher &newTeacher);
	void updateTeacher(Teacher &updatedTeacher);
	void deleteTeacher(Teacher &deletedTeacher);

	bool addClassTeachers(Class &newClass);
	bool addClassStudents(Class &newClass);
	void addTeacherClasses(Teacher &teacher);
	bool deleteClassStudents(int classId);
	bool deleteClassTeachers(int classId);
	void deleteTeacherClasses(int teacherId);

	QList<Class> classList() const;
	QList<Class> classListNoJoin() const;
	QList<Teacher> teacherList() const;
	QList<Teacher> teacherListNoJoin() const;
	void synchronizeStudents(const QList<StudentDir *> &studentList);
	QStringList studentList() const;
	QStringList studentListNoJoin() const;
	void joinStudentsToClass(QList<Class> &classes) const;
	void joinTeachersToClass(QList<Class> &classes) const;
	void joinClassesToTeachers(QList<Teacher> &teachers) const;

	SchoolDatabase *q_ptr;

	QSqlDatabase db;

	mutable bool error;
	mutable QString lastError;

};

#endif // SCHOOLDATABASE_P_H
