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

#ifndef STUDENTDIR_P_H
#define STUDENTDIR_P_H

#include <QtGlobal>
#include <QDir>
#include <QSettings>
#include <QList>
#include <QPointer>
#include "libtux4kidsadmin_global.h"
#include "class.h"

class QString;
class ProfileDir;

class StudentDirPrivate
{
public:
	Q_DECLARE_PUBLIC(StudentDir)

	StudentDirPrivate(QString path);
	virtual ~StudentDirPrivate();

	void loadProfileDirs();
	ProfileDir *findProfileDir(QString profileType);

	StudentDir *q_ptr;

	StudentDir::Status status;
	QSettings *attributes;
	QDir mainDir;
	QList<ProfileDir *> profiles;
	QList<Class> classes;
	int computerNumber;
};

#endif // STUDENTDIR_P_H
