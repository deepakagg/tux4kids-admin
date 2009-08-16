#include "profileDirFactory.h"
#include "profileDirTuxmath.h"
#include "libtux4kidsadmin_tuxmath_global.h"

#include <QDebug>

class LIBTUX4KIDSADMIN_TUXMATH_SHARED_EXPORT ProfileDirTuxmathRegister
{
public:
	ProfileDirTuxmathRegister()
	{
		qDebug() << "tuxmath register";
		ProfileDirFactory::instance().registerType<ProfileDirTuxmath>("tuxmath");
	}

	~ProfileDirTuxmathRegister()
	{
		ProfileDirFactory::instance().unregisterType("tuxmath");
	}
};

static const ProfileDirTuxmathRegister regTuxmath;
