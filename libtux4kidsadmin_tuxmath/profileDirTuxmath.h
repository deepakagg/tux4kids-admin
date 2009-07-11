#ifndef PROFILEDIRTUXMATH_H
#define PROFILEDIRTUXMATH_H

#include "profileDir.h"
#include "profileDirTuxmathPrivate.h"

class ProfileDirTuxmath : public ProfileDir
{
	Q_OBJECT
public:
	ProfileDirTuxmath();
	~ProfileDirTuxmath();
private:
	ProfileDirTuxmathPrivate *d;
};

#endif // PROFILEDIRTUXMATH_H
