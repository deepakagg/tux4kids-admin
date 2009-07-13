#include "profileDir.h"
#include "profileDirPrivate_p.h"

ProfileDir::ProfileDir(QString path, QObject *parent) :
		QObject(parent), d_ptr(new ProfileDirPrivate(path))
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

