#ifndef PROFILEDIRFACTORY_P_H
#define PROFILEDIRFACTORY_P_H

#include <QtGlobal>
#include "objectFactory.h"

class ProfileDir;
class ProfileDirFactory;
class QObject;
class QString;

class ProfileDirFactoryPrivate
{
public:
	Q_DECLARE_PUBLIC(ProfileDirFactory)
	ProfileDirFactoryPrivate();
	virtual ~ProfileDirFactoryPrivate();

	ProfileDirFactory *q_ptr;
	ObjectFactory<ProfileDir (QString, QObject), QString> objectFactory;

};

#endif // PROFILEDIRFACTORY_P_H
