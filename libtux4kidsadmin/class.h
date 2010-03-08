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

#ifndef CLASS_H
#define CLASS_H

#include <QtGlobal>
#include <QString>

#include "libtux4kidsadmin_global.h"

class ClassPrivate;
class QStringList;
class Teacher;

class LIBTUX4KIDSADMIN_SHARED_EXPORT Class
{
public:
	Class(QString name = QString());
	Class(const Class& other);
	~Class();

	QString name() const;
	void setName(QString name);
	int id() const;
	void setId(int id);
	QStringList *students();
	//void setStudents(const QStringList &students);
	QList<Teacher> *teachers();
	//void setTeachers(const QList<Teacher> &teachers);
	Class &operator=(const Class&);
	bool operator==(const Class &other) const;

protected:

	ClassPrivate * d_ptr;
	Class(ClassPrivate &dd);

private:
	Q_DECLARE_PRIVATE(Class)
};

#endif // CLASS_H
