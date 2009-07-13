#ifndef PROFILEDIRPRIVATE_H
#define PROFILEDIRPRIVATE_H

#include <QtGlobal>
#include <QDir>
#include <QSettings>
#include "profileDir.h"

class QString;

class ProfileDirPrivate
{
public:
	Q_DECLARE_PUBLIC(ProfileDir)

	ProfileDirPrivate(QString path);
	virtual ~ProfileDirPrivate();

	ProfileDir *q_ptr;

	ProfileDir::Status status;
	QSettings *attributes;
	QDir mainDir, dataDir;
};

#endif // PROFILEDIRPRIVATE_H
