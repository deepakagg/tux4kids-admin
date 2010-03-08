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

#ifndef SCHOOLDATA_H
#define SCHOOLDATA_H

#include <QObject>
#include <QPointer>

#include "libtux4kidsadmin_global.h"

class QString;
class SchoolDataPrivate;
class StudentDir;
class SchoolDatabase;

class LIBTUX4KIDSADMIN_SHARED_EXPORT SchoolData : public QObject
{
	Q_OBJECT
public:
	SchoolData(QString path, QObject *parent = 0);
	~SchoolData();
	
	enum Status {
		NoError = 0,
		InitializationError = 1
	};

	Status status() const;
	StudentDir *addStudent();
	//const StudentDir & studentDirAt(int index);
	QList<StudentDir *> students() const;
	SchoolDatabase *schoolDatabase();
	int computerCount() const;
	void setComputerCount(int computerCount);
	void setStudentComputer(StudentDir *student, int computerNumber);

protected:
	SchoolDataPrivate * const d_ptr;
	SchoolData(SchoolDataPrivate &dd, QObject *parent = 0);

signals:
	void studentAdded(StudentDir *newStudent);

private:
	Q_DECLARE_PRIVATE(SchoolData)
	Q_DISABLE_COPY(SchoolData)
};

#endif // SCHOOLDATA_H
