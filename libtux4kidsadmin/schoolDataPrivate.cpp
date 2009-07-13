#include "schoolDataPrivate_p.h"

#include <QString>

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

