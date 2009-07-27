#include "class.h"

Class::Class(QString name)
		: m_name(name)
{
}

QString Class::name() const
{
	return m_name;
}

void Class::setName(QString name)
{
	m_name = name;
}
