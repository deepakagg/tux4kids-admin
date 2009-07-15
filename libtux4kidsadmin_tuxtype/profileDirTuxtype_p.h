#ifndef PROFILEDIRTUXTYPEPRIVATE_H
#define PROFILEDIRTUXTYPEPRIVATE_H

#include "profileDir_p.h"

class ProfileDirTuxtypePrivate : public ProfileDirPrivate
{
public:
	Q_DECLARE_PUBLIC(ProfileDir)

	ProfileDirTuxtypePrivate(QString path);
	virtual ~ProfileDirTuxtypePrivate();
};

#endif // PROFILEDIRTUXTYPEPRIVATE_H
