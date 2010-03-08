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

#include "profileDirFactory.h"
#include "profileDirFactory_p.h"

#include <QDebug>

ProfileDirFactory *ProfileDirFactory::m_instance = 0;

/************************* ProfileDirFactoryCleaner *******************/

class ProfileDirFactoryCleaner
{
public:
	ProfileDirFactoryCleaner() {}
	~ProfileDirFactoryCleaner()
	{
		ProfileDirFactory::destroy();
	}
};

static const ProfileDirFactoryCleaner ProfileDirFactoryCleanerInstance;

/************************* ProfileDirFactoryPrivate *******************/

ProfileDirFactoryPrivate::ProfileDirFactoryPrivate()
{
}

ProfileDirFactoryPrivate::~ProfileDirFactoryPrivate()
{
}

/************************* ProfileDirFactory *******************/

ProfileDirFactory::ProfileDirFactory()
		: d_ptr(new ProfileDirFactoryPrivate)
{
	Q_D(ProfileDirFactory);
	d->q_ptr = this;
}

ProfileDirFactory::ProfileDirFactory(ProfileDirFactoryPrivate &dd)
		: d_ptr(&dd)
{
}

ProfileDirFactory::~ProfileDirFactory()
{
	Q_D(ProfileDirFactory);
	delete d;
}

ProfileDirFactory &ProfileDirFactory::instance()
{
	if (m_instance == 0) {
		m_instance = new ProfileDirFactory();
	}
	return *m_instance;
}

void ProfileDirFactory::destroy()
{
	if(m_instance != 0)
	{
		delete m_instance;
		m_instance = 0;
	}
}

