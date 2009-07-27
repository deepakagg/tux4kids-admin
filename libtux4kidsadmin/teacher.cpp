#include "teacher.h"
#include "teacher_p.h"

/***************************** TeacherPrivate *********************/

TeacherPrivate::TeacherPrivate()
{
}

TeacherPrivate::~TeacherPrivate()
{
}

/***************************** Teacher *********************/

Teacher::Teacher(QString firstName, QString lastName)
		: d_ptr(new TeacherPrivate())
{
	Q_D(Teacher);
	d->firstName = firstName;
	d->lastName = lastName;
}

Teacher::Teacher(TeacherPrivate &dd)
		: d_ptr(&dd)
{
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


