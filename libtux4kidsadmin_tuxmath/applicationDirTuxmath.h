#ifndef APPLICATIONDIRTUXMATH_H
#define APPLICATIONDIRTUXMATH_H

#include <QString>

#include "applicationDir.h"
#include "libtux4kidsadmin_tuxmath_global.h"

class LIBTUX4KIDSADMIN_TUXMATHSHARED_EXPORT ApplicationDirTuxmath : public ApplicationDir
{
public:
	ApplicationDirTuxmath();
	QString foo();
};

#endif // APPLICATIONDIRTUXMATH_H
