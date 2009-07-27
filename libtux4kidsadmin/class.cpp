#include "class.h"
#include "class_p.h"

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
}

Class::Class(ClassPrivate &dd)
		: d_ptr(&dd)
{
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


