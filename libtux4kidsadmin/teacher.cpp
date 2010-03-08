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

#include "teacher.h"
#include "teacher_p.h"

/***************************** TeacherPrivate *********************/

TeacherPrivate::TeacherPrivate()
		: id(-1)
{
}

TeacherPrivate::~TeacherPrivate()
{
}

/***************************** Teacher *********************/

Teacher::Teacher()
		: d_ptr(new TeacherPrivate())
{
	d_ptr->q_ptr = this;
}

Teacher::Teacher(QString firstName, QString lastName)
		: d_ptr(new TeacherPrivate())
{
	Q_D(Teacher);
	d->firstName = firstName;
	d->lastName = lastName;
	d_ptr->q_ptr = this;
}

Teacher::Teacher(TeacherPrivate &dd)
		: d_ptr(&dd)
{
	d_ptr->q_ptr = this;
}

Teacher::Teacher(const Teacher& other)
		: d_ptr(new TeacherPrivate())
{
	*d_ptr = *other.d_ptr;
	d_ptr->q_ptr = this;
}

Teacher::~Teacher()
{
	Q_D(Teacher);
	delete d;
}

QString Teacher::firstName() const
{
	Q_D(const Teacher);
	return d->firstName;
}

QString Teacher::lastName() const
{
	Q_D(const Teacher);
	return d->lastName;
}

void Teacher::setFirstName(QString firstName)
{
	Q_D(Teacher);
	d->firstName = firstName;
}

void Teacher::setLastName(QString lastName)
{
	Q_D(Teacher);
	d->lastName = lastName;
}

int Teacher::id() const
{
	Q_D(const Teacher);
	return d->id;
}

void Teacher::setId(int id)
{
	Q_D(Teacher);
	d->id = id;
}

Teacher &Teacher::operator=(const Teacher &other)
{
	if (this != &other) {
		*d_ptr = *other.d_ptr;
		d_ptr->q_ptr = this;
	}
	return *this;
}

bool Teacher::operator==(const Teacher &other) const
{
	Q_D(const Teacher);

	if (d->id >= 0 && other.d_ptr->id >= 0) {
		return d->id == other.d_ptr->id;
	} else {
		return d->firstName == other.d_ptr->firstName
			&& d->lastName == other.d_ptr->lastName;
	}
}

QList<Class> *Teacher::classes()
{
	Q_D(Teacher);
	return &d->classes;
}


