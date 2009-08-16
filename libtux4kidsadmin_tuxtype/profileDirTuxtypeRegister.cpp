#include "profileDirFactory.h"
#include "profileDirTuxtype.h"
#include "libtux4kidsadmin_tuxtype_global.h"

#include <QDebug>

class LIBTUX4KIDSADMIN_TUXTYPE_SHARED_EXPORT ProfileDirTuxtypeRegister
{
public:
	ProfileDirTuxtypeRegister()
	{
		qDebug() << "tuxtype register";
		ProfileDirFactory::instance().registerType<ProfileDirTuxtype>("tuxtype");
	}

	~ProfileDirTuxtypeRegister()
	{
		ProfileDirFactory::instance().unregisterType("tuxtype");
	}
};

static const ProfileDirTuxtypeRegister regTuxtype;
