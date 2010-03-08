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

#ifndef TEACHER_H
#define TEACHER_H

#include <QtGlobal>
#include <QString>
#include <QList>

#include "libtux4kidsadmin_global.h"
#include "class.h"

class TeacherPrivate;

class LIBTUX4KIDSADMIN_SHARED_EXPORT Teacher
{
public:
	Teacher();
	Teacher(QString firstName, QString lastName);
	Teacher(const Teacher &other);
	~Teacher();

	QString firstName() const;
	QString lastName() const;
	int id() const;
	void setFirstName(QString firstName);
	void setLastName(QString lastName);
	void setId(int id);
	Teacher &operator=(const Teacher &other);
	bool operator==(const Teacher &other) const;
	QList<Class> *classes();

protected:

	TeacherPrivate * d_ptr;
	Teacher(TeacherPrivate &dd);

private:
	Q_DECLARE_PRIVATE(Teacher)
};

#endif // TEACHER_H
