#ifndef PROFILEDIRFACTORY_H
#define PROFILEDIRFACTORY_H

#include <QtGlobal>
#include <QString>

#include "profileDirFactory_p.h"

class ProfileDirFactory
{
public:
	ProfileDirFactory();
	~ProfileDirFactory();

	static ProfileDirFactory &instance();
	static void destroy();
	template<typename ClassType>
	bool registerType(QString uniqueId)
	{
		Q_D(ProfileDirFactory);
		return d->objectFactory.registerType<ClassType>(uniqueId);
	}

protected:
	ProfileDirFactoryPrivate * const d_ptr;
	ProfileDirFactory(ProfileDirFactoryPrivate &dd);

	static ProfileDirFactory* m_instance;

private:
	Q_DECLARE_PRIVATE(ProfileDirFactory)
};

#endif // PROFILEDIRFACTORY_H
