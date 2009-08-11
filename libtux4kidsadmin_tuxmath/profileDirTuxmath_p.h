#ifndef PROFILEDIRTUXMATHPRIVATE_H
#define PROFILEDIRTUXMATHPRIVATE_H

#include "profileDir_p.h"

class TuxmathOptions;

class ProfileDirTuxmathPrivate : public ProfileDirPrivate
{
public:
	Q_DECLARE_PUBLIC(ProfileDir)

	ProfileDirTuxmathPrivate(QString path);
	virtual ~ProfileDirTuxmathPrivate();

	TuxmathOptions *tuxmathOptions;
};

#endif // PROFILEDIRTUXMATHPRIVATE_H
