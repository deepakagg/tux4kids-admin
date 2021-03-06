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

#include "studentDir.h"
#include "studentDir_p.h"
#include "profileDir.h"
#include "profileDirFactory.h"

#include <QString>
#include <QDebug>

/****************** StudentDirPrivate *******************/

StudentDirPrivate::StudentDirPrivate(QString path) :
		status(StudentDir::NoError),
		attributes(0),
		computerNumber(-1)
{
	mainDir.setPath(path);
	if (!mainDir.exists()) {
		if (!QDir::root().mkpath(path)) {
			status = StudentDir::InitializationError;
			return;
		}
	}
	mainDir.setPath(path);

	attributes = new QSettings(path + "/attributes.ini", QSettings::IniFormat);
	if (attributes->status() != QSettings::NoError) {
		status = StudentDir::InitializationError;
		return;
	}
	if (attributes->value("first_name").toString().isNull()
		&& attributes->value("last_name").toString().isNull()) {
		status = StudentDir::InitializationError;
		return;
	}

	loadProfileDirs();
}

StudentDirPrivate::~StudentDirPrivate()
{
	delete attributes;
}

void StudentDirPrivate::loadProfileDirs()
{
	foreach(QString dirName,
		mainDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name)) {

		QString path = mainDir.filePath(dirName);
		QString profileType = ProfileDir::profileType(path);
		profiles.append(ProfileDirFactory::instance().create(profileType, path, 0));
	}
}

ProfileDir *StudentDirPrivate::findProfileDir(QString profileType)
{
	foreach (ProfileDir *profileDir, profiles) {
		if (profileDir->type() == profileType)
			return profileDir;
	}

	return 0;
}

/****************** StudentDir *******************/

StudentDir::StudentDir(QString path, QObject *parent) :
		QObject(parent), d_ptr(new StudentDirPrivate(path))
{
	Q_D(StudentDir);
	d->q_ptr = this;
}

StudentDir::StudentDir(StudentDirPrivate &dd, QObject *parent)
		: QObject(parent), d_ptr(&dd)
{
}

StudentDir::~StudentDir()
{
	Q_D(StudentDir);
	delete d;
}

StudentDir::Status StudentDir::status() const
{
	Q_D(const StudentDir);
	return d->status;
}


QString StudentDir::firstName() const
{
	Q_D(const StudentDir);
	return d->attributes->value("first_name").toString();
}

QString StudentDir::lastName() const
{
	Q_D(const StudentDir);
	return d->attributes->value("last_name").toString();
}

void StudentDir::setFirstName(const QString &firstName)
{
	Q_D(const StudentDir);
	d->attributes->setValue("first_name", firstName);
}

void StudentDir::setLastName(const QString &lastName)
{
	Q_D(const StudentDir);
	d->attributes->setValue("last_name", lastName);
}

void StudentDir::addProfileDir(ProfileDir *profileDir)
{
	Q_D(StudentDir);
	profileDir->setParent(this);
	d->profiles.append(profileDir);
}

ProfileDir *StudentDir::addProfileDir(QString profileType)
{
	Q_D(StudentDir);

	ProfileDir *tmp = ProfileDirFactory::instance().create(profileType, d->mainDir.absoluteFilePath(profileType), this);
	if (tmp != 0) {
		d->profiles.append(tmp);
		return tmp;
	}

	return 0;
}

QString StudentDir::dirName() const
{
	Q_D(const StudentDir);
	return d->mainDir.dirName();
}

QList<Class> *StudentDir::classes()
{
	Q_D(StudentDir);
	return &d->classes;
}

QList<ProfileDir *> StudentDir::profiles()
{
	Q_D(StudentDir);
	return d->profiles;
}

int StudentDir::computerNumber() const
{
	Q_D(const StudentDir);
	return d->computerNumber;
}

/*void StudentDir::setClasses(const QList<Class> &classes)
{
	Q_D(StudentDir);
	d->classes = classes;
}*/

