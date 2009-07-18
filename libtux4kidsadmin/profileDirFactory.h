#ifndef PROFILEDIRFACTORY_H
#define PROFILEDIRFACTORY_H

#include <QtGlobal>
#include <QString>
#include <QDebug>

#include "profileDirFactory_p.h"
#include "libtux4kidsadmin_global.h"

class LIBTUX4KIDSADMIN_SHARED_EXPORT ProfileDirFactory
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
		qDebug() << "registering" << uniqueId << "in the factory";
		return d->objectFactory.registerType<ClassType>(uniqueId);
	}

	bool unregisterType(QString uniqueId)
	{
		Q_D(ProfileDirFactory);
		qDebug() << "unregistering" << uniqueId;
		return d->objectFactory.unregisterType(uniqueId);
	}

	ProfileDir *create(QString uniqueId, QString path, QObject *parent = 0)
	{
		Q_D(ProfileDirFactory);
		return d->objectFactory.create(uniqueId, path, parent);
	}

protected:
	ProfileDirFactoryPrivate * const d_ptr;
	ProfileDirFactory(ProfileDirFactoryPrivate &dd);

	static ProfileDirFactory* m_instance;

private:
	Q_DECLARE_PRIVATE(ProfileDirFactory)
};

#endif // PROFILEDIRFACTORY_H
