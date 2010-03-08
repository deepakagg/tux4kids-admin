/*

This file is part of Libtux4kidsadmin-tuxmath

Libtux4kidsadmin-tuxmath is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Libtux4kidsadmin-tuxmath is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Libtux4kidsadmin-tuxmath.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#include "profileDirTuxmath.h"
#include "profileDirTuxmath_p.h"
#include "tuxmathOptions.h"

#include <QString>
#include <QDebug>

/************** ProfileDirTuxmathPrivate ****************/

ProfileDirTuxmathPrivate::ProfileDirTuxmathPrivate(QString path)
		: ProfileDirPrivate(path)
{
	if (status != ProfileDir::NoError) {
		return;
	}
	attributes->setValue("profile_type", "tuxmath");
	tuxmathOptions = new TuxmathOptions(dataDir.absoluteFilePath("options"));
}

ProfileDirTuxmathPrivate::~ProfileDirTuxmathPrivate()
{
}

/************** ProfileDirTuxmath ****************/

ProfileDirTuxmath::ProfileDirTuxmath(QString path, QObject *parent)
		: ProfileDir(*new ProfileDirTuxmathPrivate(path), parent)
{
}

ProfileDirTuxmath::ProfileDirTuxmath(ProfileDirTuxmathPrivate &dd, QObject *parent)
		: ProfileDir(dd, parent)
{
}

ProfileDirTuxmath::~ProfileDirTuxmath()
{
}

TuxmathOptions *ProfileDirTuxmath::tuxmathOptions()
{
	Q_D(ProfileDirTuxmath);
	return d->tuxmathOptions;
}
