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

#ifndef PROFILEDIRTUXTYPEPRIVATE_H
#define PROFILEDIRTUXTYPEPRIVATE_H

#include "profileDir_p.h"

class ProfileDirTuxtypePrivate : public ProfileDirPrivate
{
public:
	Q_DECLARE_PUBLIC(ProfileDir)

	ProfileDirTuxtypePrivate(QString path);
	virtual ~ProfileDirTuxtypePrivate();
};

#endif // PROFILEDIRTUXTYPEPRIVATE_H
