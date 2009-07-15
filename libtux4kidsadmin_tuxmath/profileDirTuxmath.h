#ifndef PROFILEDIRTUXMATH_H
#define PROFILEDIRTUXMATH_H

#include "profileDir.h"
#include "libtux4kidsadmin_tuxmath_global.h"

class ProfileDirTuxmathPrivate;

class LIBTUX4KIDSADMIN_TUXMATH_SHARED_EXPORT ProfileDirTuxmath : public ProfileDir
{
	Q_OBJECT
public:
	ProfileDirTuxmath(QString path, QObject *parent = 0);
	~ProfileDirTuxmath();
protected:
	ProfileDirTuxmath(ProfileDirTuxmathPrivate &dd, QObject *parent);

private:
	Q_DECLARE_PRIVATE(ProfileDirTuxmath)
	Q_DISABLE_COPY(ProfileDirTuxmath)
};

#endif // PROFILEDIRTUXMATH_H
