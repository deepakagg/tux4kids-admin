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

#include "class.h"
#include "class_p.h"
#include "teacher.h"

#include <QDebug>

/***************************** ClassPrivate *********************/

ClassPrivate::ClassPrivate()
		: id(-1)
{
}

ClassPrivate::~ClassPrivate()
{
}

/***************************** Class *********************/

Class::Class(QString name)
		: d_ptr(new ClassPrivate())
{
	Q_D(Class);
	d->name = name;
	d->q_ptr = this;
}

Class::Class(ClassPrivate &dd)
		: d_ptr(&dd)
{
	d_ptr->q_ptr = this;
}

Class::Class(const Class& other)
		: d_ptr(new ClassPrivate())
{
	*d_ptr = *other.d_ptr;
	d_ptr->q_ptr = this;
}

Class::~Class()
{
	Q_D(Class);
	delete d;
}

QString Class::name() const
{
	Q_D(const Class);
	return d->name;
}

void Class::setName(QString name)
{
	Q_D(Class);
	d->name = name;
}

int Class::id() const
{
	Q_D(const Class);
	return d->id;
}

void Class::setId(int id)
{
	Q_D(Class);
	d->id = id;
}

QStringList *Class::students()
{
	Q_D(Class);
	return &d->students;
}

/*void Class::setStudents(const QStringList &students)
{
	Q_D(Class);
	d->students = students;
}*/

QList<Teacher> *Class::teachers()
{
	Q_D(Class);
	return &d->teachers;
}

/*void Class::setTeachers(const QList<Teacher> &teachers)
{
	Q_D(Class);
	d->teachers = teachers;
}*/

Class &Class::operator=(const Class &other)
{
	if (this != &other) {
		*d_ptr = *other.d_ptr;
		d_ptr->q_ptr = this;
	}
	return *this;
}

bool Class::operator==(const Class &other) const
{

	Q_D(const Class);

	if (d->id >= 0 && other.d_ptr->id >= 0) {
		return d->id == other.d_ptr->id;
	} else {
		return d->name == other.d_ptr->name
			&& d->students == other.d_ptr->students
			&& d->teachers == other.d_ptr->teachers;
	}
}

