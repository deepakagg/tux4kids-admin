#include "profileDirFactory.h"
#include "profileDirFactory_p.h"

#include <QDebug>

ProfileDirFactory *ProfileDirFactory::m_instance = 0;

/************************* ProfileDirFactoryCleaner *******************/

class ProfileDirFactoryCleaner
{
public:
	ProfileDirFactoryCleaner() {}
	~ProfileDirFactoryCleaner()
	{
		ProfileDirFactory::destroy();
		qDebug() << "destroying ProfileDirFactory";
	}
};

static const ProfileDirFactoryCleaner ProfileDirFactoryCleanerInstance;

/************************* ProfileDirFactoryPrivate *******************/

ProfileDirFactoryPrivate::ProfileDirFactoryPrivate()
{
}

ProfileDirFactoryPrivate::~ProfileDirFactoryPrivate()
{
}

/************************* ProfileDirFactory *******************/

ProfileDirFactory::ProfileDirFactory()
		: d_ptr(new ProfileDirFactoryPrivate)
{
	Q_D(ProfileDirFactory);
	d->q_ptr = this;
}

ProfileDirFactory::ProfileDirFactory(ProfileDirFactoryPrivate &dd)
		: d_ptr(&dd)
{
}

ProfileDirFactory::~ProfileDirFactory()
{
	Q_D(ProfileDirFactory);
	delete d;
}

ProfileDirFactory &ProfileDirFactory::instance()
{
	if (m_instance == 0) {
		m_instance = new ProfileDirFactory();
	}
	return *m_instance;
}

void ProfileDirFactory::destroy()
{
	if(m_instance != 0)
	{
		delete m_instance;
		m_instance = 0;
	}
}

