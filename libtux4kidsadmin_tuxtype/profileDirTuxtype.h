#ifndef PROFILEDIRTUXTYPE_H
#define PROFILEDIRTUXTYPE_H

#include "profileDir.h"
#include "libtux4kidsadmin_tuxtype_global.h"

class ProfileDirTuxtypePrivate;

class LIBTUX4KIDSADMIN_TUXTYPE_SHARED_EXPORT ProfileDirTuxtype : public ProfileDir
{
	Q_OBJECT
public:
	ProfileDirTuxtype(QString path, QObject *parent = 0);
	~ProfileDirTuxtype();
protected:
	ProfileDirTuxtype(ProfileDirTuxtypePrivate &dd, QObject *parent);

private:
	Q_DECLARE_PRIVATE(ProfileDirTuxtype)
	Q_DISABLE_COPY(ProfileDirTuxtype)
};

#endif // PROFILEDIRTUXTYPE_H
