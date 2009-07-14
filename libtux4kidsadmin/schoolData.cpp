#include "schoolData.h"
#include "schoolData_p.h"

#include <QString>

/****************** SchoolDataPrivate *******************/

SchoolDataPrivate::SchoolDataPrivate(QString path)
{
	mainDir.setPath(path);
	if (!mainDir.exists()) {
		if (!QDir::root().mkpath(path)) {
			status = SchoolData::InitializationError;
		}
	}
	mainDir.setPath(path);
}



SchoolDataPrivate::~SchoolDataPrivate()
{
}

/****************** SchoolData *******************/

SchoolData::SchoolData(QString path, QObject *parent)
		: QObject(parent), d_ptr(new SchoolDataPrivate(path))
{
	Q_D(SchoolData);
	d->q_ptr = this;
}

SchoolData::~SchoolData()
{
	Q_D(SchoolData);
	delete d;
}

SchoolData::Status SchoolData::status() const
{
	Q_D(const SchoolData);
	return d->status;
}

QString SchoolData::nextProfileDir() const
{
	Q_D(const SchoolData);
	QString baseName = "profile_";
	int number = 1;
	while(!d->mainDir.exists(baseName + QString::number(number)))
		++number;

	return baseName + QString::number(number);
}

