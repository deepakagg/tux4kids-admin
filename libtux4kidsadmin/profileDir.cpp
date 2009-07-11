#include "profileDir.h"
#include "profileDirPrivate.h"

ProfileDir::ProfileDir()
{
	d = new ProfileDirPrivate();
}

ProfileDir::~ProfileDir()
{
	delete d;
}

