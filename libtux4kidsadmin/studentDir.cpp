#include "studentDir.h"
#include "studentDir_p.h"

#include <QString>

/****************** StudentDirPrivate *******************/

StudentDirPrivate::StudentDirPrivate(QString path)
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
	if (!attributes->status() != QSettings::NoError) {
		status = StudentDir::InitializationError;
		return;
	}
}

StudentDirPrivate::~StudentDirPrivate()
{
	delete attributes;
}

/****************** StudentDir *******************/

StudentDir::StudentDir(QString path, QObject *parent) :
		QObject(parent), d_ptr(new StudentDirPrivate(path))
{
	Q_D(StudentDir);
	d->q_ptr = this;
}

StudentDir::~StudentDir()
{
	Q_D(StudentDir);
	delete d;
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

