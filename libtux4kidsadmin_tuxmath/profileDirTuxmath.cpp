#include "profileDirTuxmath.h"

#include "profileDirTuxmathPrivate_p.h"


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
