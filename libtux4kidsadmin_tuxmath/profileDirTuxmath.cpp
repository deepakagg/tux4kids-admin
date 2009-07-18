#include "profileDirTuxmath.h"
#include "profileDirTuxmath_p.h"

#include <QString>
#include <QDebug>

/************** ProfileDirTuxmathPrivate ****************/

ProfileDirTuxmathPrivate::ProfileDirTuxmathPrivate(QString path)
		: ProfileDirPrivate(path)
{
	attributes->setValue("profile_type", "tuxmath");
}

ProfileDirTuxmathPrivate::~ProfileDirTuxmathPrivate()
{
}

/************** ProfileDirTuxmath ****************/

ProfileDirTuxmath::ProfileDirTuxmath(QString path, QObject *parent)
		: ProfileDir(*new ProfileDirTuxmathPrivate(path), parent)
{
}

ProfileDirTuxmath::ProfileDirTuxmath(ProfileDirTuxmathPrivate &dd, QObject *parent)
		: ProfileDir(dd, parent)
{
}

ProfileDirTuxmath::~ProfileDirTuxmath()
{
}
