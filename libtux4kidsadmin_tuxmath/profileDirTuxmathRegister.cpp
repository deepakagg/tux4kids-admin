#include "profileDirFactory.h"
#include "profileDirTuxmath.h"

#include <QDebug>

class ProfileDirTuxmathRegister
{
public:
	ProfileDirTuxmathRegister()
	{
		ProfileDirFactory::instance().registerType<ProfileDirTuxmath>("tuxmath");
	}

	~ProfileDirTuxmathRegister()
	{
		ProfileDirFactory::instance().unregisterType("tuxmath");
	}
};

static const ProfileDirTuxmathRegister reg;
