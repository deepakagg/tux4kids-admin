#include "profileDirPrivate_p.h"

#include <QString>

ProfileDirPrivate::ProfileDirPrivate(QString path)
{
	mainDir.setPath(path);
	if (!mainDir.exists()) {
		if (!QDir::root().mkpath(path)) {
			status = ProfileDir::InitializationError;
			return;
		}
	}
	mainDir.setPath(path);

	if (!mainDir.mkdir("data")) {
		status = ProfileDir::InitializationError;
		return;
	}
	dataDir = QDir(mainDir.absolutePath() + "/data");

	attributes = new QSettings(path + "/attributes.ini", QSettings::IniFormat);
	if (!attributes->status() != QSettings::NoError) {
		status = ProfileDir::InitializationError;
		return;
	}

}

ProfileDirPrivate::~ProfileDirPrivate()
{
	delete attributes;
}

