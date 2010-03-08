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

#include "computerDir.h"
#include "computerDir_p.h"

#include "studentDir.h"
#include "studentDir_p.h"
#include "profileDir.h"
#include "profileDir_p.h"

#include <QDebug>

/**************************** ComputerPrivate *************************/

ComputerDirPrivate::ComputerDirPrivate(QString path, int num)
		: studentDir(0)
{
	QDir parentDir(path);
	number = num;
	QString dirName = QString("computer_%1").arg(number);
	if (!parentDir.exists(dirName)) {
		if (!parentDir.mkdir(dirName)) {
			//report error
		}
	}
	mainDir.setPath(parentDir.absoluteFilePath(dirName));
}

ComputerDirPrivate::~ComputerDirPrivate()
{
}

/**************************** ComputerDir *************************/

ComputerDir::ComputerDir(QString path, int number, QObject *parent)
		: QObject(parent),
		d_ptr(new ComputerDirPrivate(path, number))
{
	Q_D(ComputerDir);
	d->q_ptr = this;
}

ComputerDir::ComputerDir(ComputerDirPrivate &dd, QObject *parent)
		: QObject(parent), d_ptr(&dd)
{
	Q_D(ComputerDir);
	d->q_ptr = this;
}

ComputerDir::~ComputerDir()
{
}

void ComputerDir::clear()
{
	Q_D(ComputerDir);
	if (d->studentDir != 0) {
		d->studentDir->d_func()->computerNumber = -1;
	}
	d->studentDir = 0;

	foreach (QString fileName, d->mainDir.entryList(QDir::Files
							| QDir::Dirs
							| QDir::NoDotAndDotDot)) {
		d->mainDir.remove(d->mainDir.absoluteFilePath(fileName));
	}

	foreach (QString dirName, d->mainDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
		d->mainDir.rmdir(dirName);
	}
}

void ComputerDir::setStudentDir(StudentDir *studentDir)
{
	Q_D(ComputerDir);

	clear();
	d->studentDir = studentDir;

	studentDir->d_func()->computerNumber = d->number;
	foreach(ProfileDir *profile, studentDir->profiles()) {
		QFile::link(profile->d_func()->mainDir.absolutePath(),
			    d->mainDir.absoluteFilePath(profile->type()));
	}
}

StudentDir *ComputerDir::studentDir()
{
	Q_D(ComputerDir);
	return d->studentDir;
}

