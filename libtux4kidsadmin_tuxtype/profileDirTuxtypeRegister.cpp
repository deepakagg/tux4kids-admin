#include "profileDirFactory.h"
#include "profileDirTuxtype.h"

#include <QDebug>

class ProfileDirTuxtypeRegister
{
public:
	ProfileDirTuxtypeRegister()
	{
		ProfileDirFactory::instance().registerType<ProfileDirTuxtype>("tuxtype");
	}

	~ProfileDirTuxtypeRegister()
	{
		ProfileDirFactory::instance().unregisterType("tuxtype");
	}
};

static const ProfileDirTuxtypeRegister reg;
