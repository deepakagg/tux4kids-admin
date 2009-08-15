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

