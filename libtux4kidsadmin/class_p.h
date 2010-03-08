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

#ifndef CLASS_P_H
#define CLASS_P_H

#include <QtGlobal>
#include <QString>
#include <QStringList>

class Teacher;

class  ClassPrivate
{
public:
	Q_DECLARE_PUBLIC(Class)

	ClassPrivate();
	virtual ~ClassPrivate();

	Class *q_ptr;

	int id;
	QString name;
	QStringList students;
	QList<Teacher> teachers;

};

#endif // CLASS_P_H
