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

#ifndef STUDENTDIR_H
#define STUDENTDIR_H

#include <QObject>

#include "libtux4kidsadmin_global.h"
#include "class.h"

class StudentDirPrivate;
class ProfileDir;
class QString;

class LIBTUX4KIDSADMIN_SHARED_EXPORT StudentDir : public QObject
{
	Q_OBJECT
public:
	StudentDir(QString path, QObject *parent = 0);
	~StudentDir();

	enum Status {
		NoError = 0,
		InitializationError = 1
	};

	Status status() const;

	QString dirName() const;
	QString firstName() const;
	QString lastName() const;
	void setFirstName(const QString &firstName);
	void setLastName(const QString &lastName);
	void addProfileDir(ProfileDir *profileDir);
	ProfileDir *addProfileDir(QString profileType);
	QList<Class> *classes();
	QList<ProfileDir *> profiles();
	int computerNumber() const;
	//void setClasses(const QList<Class>& classes);

protected:
	StudentDirPrivate * const d_ptr;
	StudentDir(StudentDirPrivate &dd, QObject *parent = 0);
private:
	Q_DECLARE_PRIVATE(StudentDir)
	Q_DISABLE_COPY(StudentDir)

	friend class SchoolData;
	friend class ComputerDir;
};

#endif // STUDENTDIR_H
