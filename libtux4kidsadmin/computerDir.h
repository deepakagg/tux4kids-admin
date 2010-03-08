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

#ifndef COMPUTERDIR_H
#define COMPUTERDIR_H

#include <QObject>
#include <QDir>

class ComputerDirPrivate;
class StudentDir;

class ComputerDir : public QObject
{
	Q_OBJECT
public:
	ComputerDir(QString path, int num, QObject *parent = 0);
	~ComputerDir();

	void clear();
	void setStudentDir(StudentDir *studentDir);
	StudentDir *studentDir();

protected:
	ComputerDirPrivate * const d_ptr;
	ComputerDir(ComputerDirPrivate &dd, QObject *parent = 0);

private:
	Q_DECLARE_PRIVATE(ComputerDir)
	Q_DISABLE_COPY(ComputerDir)
};

#endif // COMPUTERDIR_H
