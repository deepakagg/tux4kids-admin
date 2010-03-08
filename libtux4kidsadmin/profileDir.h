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

#ifndef PROFILEDIR_H
#define PROFILEDIR_H

#include <QObject>
#include "libtux4kidsadmin_global.h"

class ProfileDirPrivate;

class LIBTUX4KIDSADMIN_SHARED_EXPORT ProfileDir : public QObject
{
	Q_OBJECT

public:
	ProfileDir(QString path, QObject *parent = 0);
	~ProfileDir();

	enum Status {
		NoError = 0,
		InitializationError = 1
	};

	Status status() const;
	static QString profileType(QString dirPath);
	QString type() const;

protected:
	ProfileDirPrivate * const d_ptr;
	ProfileDir(ProfileDirPrivate &dd, QObject *parent = 0);

private:
	Q_DECLARE_PRIVATE(ProfileDir)
	Q_DISABLE_COPY(ProfileDir)

	friend class ComputerDir;
};

#endif // PROFILEDIR_H
