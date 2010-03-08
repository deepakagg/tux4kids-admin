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

#include "schoolData.h"
#include "schoolData_p.h"
#include "studentDir.h"
#include "studentDir_p.h"
#include "computerDir.h"

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSettings>

/****************** SchoolDataPrivate *******************/

SchoolDataPrivate::SchoolDataPrivate(QString path)
		: status(SchoolData::NoError),
		attributes(0)
{
	mainDir.setPath(path);
	if (!mainDir.exists()) {
		if (!QDir::root().mkpath(path)) {
			status = SchoolData::InitializationError;
			return;
		}
	}
	mainDir.setPath(path);
	if (!mainDir.exists("students")) {
		if (!mainDir.mkdir("students")) {
			status = SchoolData::InitializationError;
			return;
		}
	}
	studentsDir.setPath(mainDir.absoluteFilePath("students"));

	if (!mainDir.exists("computers")) {
		if (!mainDir.mkdir("computers")) {
			status = SchoolData::InitializationError;
			return;
		}
	}
	computersDir.setPath(mainDir.absoluteFilePath("computers"));

	loadStudentDirs();

	if (!database.open(path + "/school_database.db")) {
		status = SchoolData::InitializationError;
		return;
	} else {
		database.synchronizeStudents(students);
	}

	attributes = new QSettings(mainDir.absoluteFilePath("attributes.ini"), QSettings::IniFormat);
	if (attributes->status() != QSettings::NoError) {
		status = SchoolData::InitializationError;
	}
	attributes->setValue("computer_count", 8);
	createComputerDirs();
}

SchoolDataPrivate::~SchoolDataPrivate()
{
	delete attributes;
}

QString SchoolDataPrivate::nextStudentDir() const
{
	QString baseName = "student_";
	int number = 1;
	while(studentsDir.exists(baseName + QString::number(number)))
		++number;

	return baseName + QString::number(number);
}

void SchoolDataPrivate::loadStudentDirs()
{
	foreach(QString dirName,
		studentsDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name)) {

		StudentDir *studentDir = new StudentDir(studentsDir.absoluteFilePath(dirName));
		if (studentDir->status() == StudentDir::NoError) {
			students.append(studentDir);
		} else {
			delete studentDir;
		}
	}
}

void SchoolDataPrivate::createComputerDirs()
{
	int computerCount = attributes->value("computer_count", 0).toInt();
	for (int i = 1; i <= computerCount; ++i) {
		ComputerDir *computerDir = new ComputerDir(computersDir.absolutePath(), i);
		computers.append(computerDir);
	}
}


/****************** SchoolData *******************/

SchoolData::SchoolData(QString path, QObject *parent)
		: QObject(parent), d_ptr(new SchoolDataPrivate(path))
{
	Q_D(SchoolData);
	d->q_ptr = this;
}

SchoolData::SchoolData(SchoolDataPrivate &dd, QObject *parent)
		: QObject(parent), d_ptr(&dd)
{
	Q_D(SchoolData);
	d->q_ptr = this;
}

SchoolData::~SchoolData()
{
	Q_D(SchoolData);
	delete d;
}

SchoolData::Status SchoolData::status() const
{
	Q_D(const SchoolData);
	return d->status;
}

StudentDir *SchoolData::addStudent()
{
	Q_D(SchoolData);

	StudentDir *studentDir = new StudentDir(d->studentsDir.absoluteFilePath(d->nextStudentDir()));
	d->students.append(studentDir);
	emit studentAdded(studentDir);

	return studentDir;
}

/*const StudentDir & SchoolData::studentDirAt(int index)
{
	Q_D(SchoolData);
	return *(d->students.at(index));
}
*/

QList<StudentDir *> SchoolData::students() const
{
	Q_D(const SchoolData);
	return d->students;
}

SchoolDatabase *SchoolData::schoolDatabase()
{
	Q_D(SchoolData);
	return &(d->database);
}

int SchoolData::computerCount() const
{
	Q_D(const SchoolData);
	return d->attributes->value("computer_count", 0).toInt();
}

void SchoolData::setComputerCount(int computerCount)
{
	//TODO
}

void SchoolData::setStudentComputer(StudentDir *student, int computerNumber)
{
	Q_D(const SchoolData);
	if (computerNumber <= 0) {
		if (student->computerNumber() > 0) {
			d->computers[student->computerNumber() - 1]->clear();
		}
	} else {
		d->computers[computerNumber - 1]->setStudentDir(student);
	}
}

