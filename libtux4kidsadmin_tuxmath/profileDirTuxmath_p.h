#ifndef PROFILEDIRTUXMATHPRIVATE_H
#define PROFILEDIRTUXMATHPRIVATE_H

#include "profileDir_p.h"

class ProfileDirTuxmathPrivate : public ProfileDirPrivate
{
public:
	Q_DECLARE_PUBLIC(ProfileDir)

	ProfileDirTuxmathPrivate(QString path);
	virtual ~ProfileDirTuxmathPrivate();
};

#endif // PROFILEDIRTUXMATHPRIVATE_H
