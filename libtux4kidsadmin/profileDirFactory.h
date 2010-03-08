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

#ifndef PROFILEDIRFACTORY_H
#define PROFILEDIRFACTORY_H

#include <QtGlobal>
#include <QString>
#include <QDebug>

#include "profileDirFactory_p.h"
#include "libtux4kidsadmin_global.h"

class LIBTUX4KIDSADMIN_SHARED_EXPORT ProfileDirFactory
{
public:
	ProfileDirFactory();
	~ProfileDirFactory();

	static ProfileDirFactory &instance();
	static void destroy();

	template<typename ClassType>
	bool registerType(QString uniqueId)
	{
		Q_D(ProfileDirFactory);
		qDebug() << "registering" << uniqueId << "in the factory";
		return d->objectFactory.registerType<ClassType>(uniqueId);
	}

	bool unregisterType(QString uniqueId)
	{
		Q_D(ProfileDirFactory);
		qDebug() << "unregistering" << uniqueId;
		return d->objectFactory.unregisterType(uniqueId);
	}

	ProfileDir *create(QString uniqueId, QString path, QObject *parent = 0)
	{
		Q_D(ProfileDirFactory);
		return d->objectFactory.create(uniqueId, path, parent);
	}

protected:
	ProfileDirFactoryPrivate * const d_ptr;
	ProfileDirFactory(ProfileDirFactoryPrivate &dd);

	static ProfileDirFactory* m_instance;

private:
	Q_DECLARE_PRIVATE(ProfileDirFactory)
};

#endif // PROFILEDIRFACTORY_H
