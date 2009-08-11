#include "profileDirTuxmath.h"
#include "profileDirTuxmath_p.h"
#include "tuxmathOptions.h"

#include <QString>
#include <QDebug>

/************** ProfileDirTuxmathPrivate ****************/

ProfileDirTuxmathPrivate::ProfileDirTuxmathPrivate(QString path)
		: ProfileDirPrivate(path)
{
	if (status != ProfileDir::NoError) {
		return;
	}
	attributes->setValue("profile_type", "tuxmath");
	tuxmathOptions = new TuxmathOptions(dataDir.absoluteFilePath("options"));
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
