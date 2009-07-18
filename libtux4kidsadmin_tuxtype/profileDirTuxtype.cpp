#include "profileDirTuxtype.h"
#include "profileDirTuxtype_p.h"

#include <QString>
#include <QDebug>

/************** ProfileDirTuxtypePrivate ****************/

ProfileDirTuxtypePrivate::ProfileDirTuxtypePrivate(QString path)
		: ProfileDirPrivate(path)
{
	attributes->setValue("profile_type", "tuxtype");
}

ProfileDirTuxtypePrivate::~ProfileDirTuxtypePrivate()
{
}

/************** ProfileDirTuxtype *********************/

ProfileDirTuxtype::ProfileDirTuxtype(QString path, QObject *parent)
		: ProfileDir(*new ProfileDirTuxtypePrivate(path), parent)
{
}

ProfileDirTuxtype::ProfileDirTuxtype(ProfileDirTuxtypePrivate &dd, QObject *parent)
		: ProfileDir(dd, parent)
{
}

ProfileDirTuxtype::~ProfileDirTuxtype()
{
}
