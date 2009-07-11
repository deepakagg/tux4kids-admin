#include "profileDirTuxmath.h"

ProfileDirTuxmath::ProfileDirTuxmath()
{
	d = new ProfileDirTuxmathPrivate();
}

ProfileDirTuxmath::~ProfileDirTuxmath()
{
	delete d;
}
