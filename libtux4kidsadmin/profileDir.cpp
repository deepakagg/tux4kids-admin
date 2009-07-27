#include "profileDir.h"
#include "profileDir_p.h"
#include "objectFactory.h"

#include <QString>

/****************** ProfileDirPrivate *******************/

ProfileDirPrivate::ProfileDirPrivate(QString path)
		: status(ProfileDir::NoError)
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
	dataDir = QDir(mainDir.absolutePath() + "/data");

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
	QSettings tmp(path + "/attributes.ini");
	return tmp.value("profile_type", "unknown").toString();
}

QString ProfileDir::type() const
{
	Q_D(const ProfileDir);
	d->attributes->value("profile_type");
}

