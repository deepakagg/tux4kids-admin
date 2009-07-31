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

Teacher::Teacher(const Teacher& other)
		: d_ptr(new TeacherPrivate())
{
	*d_ptr = *other.d_ptr;
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
		TeacherPrivate *tmp = new TeacherPrivate();
		*tmp = *d_ptr;
		tmp->q_ptr = this;
		delete d_ptr;
		d_ptr = tmp;
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


