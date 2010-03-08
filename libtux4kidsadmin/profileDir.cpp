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

#include "profileDir.h"
#include "profileDir_p.h"
#include "objectFactory.h"

#include <QString>

/****************** ProfileDirPrivate *******************/

ProfileDirPrivate::ProfileDirPrivate(QString path)
		: status(ProfileDir::NoError),
		attributes(0)
{
	mainDir.setPath(path);
	if (!mainDir.exists()) {
		if (!QDir::root().mkpath(path)) {
			status = ProfileDir::InitializationError;
			return;
		}
	}
	mainDir.setPath(path);

	/*if (!mainDir.mkdir("data")) {
		status = ProfileDir::InitializationError;
		return;
	}*/
	if (!mainDir.exists("data")) {
		if (!mainDir.mkdir("data")) {
			status = ProfileDir::InitializationError;
			return;
		}
	}
	dataDir = QDir(mainDir.absoluteFilePath("data"));

	attributes = new QSettings(mainDir.absolutePath() + "/attributes.ini", QSettings::IniFormat);
	if (attributes->status() != QSettings::NoError) {
		status = ProfileDir::InitializationError;
		return;
	}

}

ProfileDirPrivate::~ProfileDirPrivate()
{
	delete attributes;
}

/****************** ProfileDir *******************/

ProfileDir::ProfileDir(QString path, QObject *parent) :
		QObject(parent),
		d_ptr(new ProfileDirPrivate(path))
{
	Q_D(ProfileDir);
	d->q_ptr = this;
}

ProfileDir::ProfileDir(ProfileDirPrivate &dd, QObject *parent)
		: QObject(parent), d_ptr(&dd)
{
	Q_D(ProfileDir);
	d->q_ptr = this;
}

ProfileDir::~ProfileDir()
{
	Q_D(ProfileDir);
	delete d;
}

ProfileDir::Status ProfileDir::status() const
{
	Q_D(const ProfileDir);
	return d->status;
}

QString ProfileDir::profileType(QString path)
{
	QSettings tmp(path + "/attributes.ini", QSettings::IniFormat);
	return tmp.value("profile_type", "unknown").toString();
}

QString ProfileDir::type() const
{
	Q_D(const ProfileDir);
	return d->attributes->value("profile_type").toString();
}

