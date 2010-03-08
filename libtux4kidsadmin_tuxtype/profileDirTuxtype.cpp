/*

This file is part of Libtux4kidsadmin-tuxtype

Libtux4kidsadmin-tuxtype is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Libtux4kidsadmin-tuxtype is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Libtux4kidsadmin-tuxtype.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#include "profileDirTuxtype.h"
#include "profileDirTuxtype_p.h"

#include <QString>
#include <QDebug>

/************** ProfileDirTuxtypePrivate ****************/

ProfileDirTuxtypePrivate::ProfileDirTuxtypePrivate(QString path)
		: ProfileDirPrivate(path)
{
	attributes->setValue("profile_type", "tuxtype");
}

ProfileDirTuxtypePrivate::~ProfileDirTuxtypePrivate()
{
}

/************** ProfileDirTuxtype *********************/

ProfileDirTuxtype::ProfileDirTuxtype(QString path, QObject *parent)
		: ProfileDir(*new ProfileDirTuxtypePrivate(path), parent)
{
}

ProfileDirTuxtype::ProfileDirTuxtype(ProfileDirTuxtypePrivate &dd, QObject *parent)
		: ProfileDir(dd, parent)
{
}

ProfileDirTuxtype::~ProfileDirTuxtype()
{
}
