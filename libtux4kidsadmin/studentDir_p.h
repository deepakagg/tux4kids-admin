#ifndef STUDENTDIR_P_H
#define STUDENTDIR_P_H

#include <QtGlobal>
#include <QDir>
#include <QSettings>
#include <QList>
#include <QPointer>
#include "libtux4kidsadmin_global.h"
#include "class.h"

class QString;
class ProfileDir;

class StudentDirPrivate
{
public:
	Q_DECLARE_PUBLIC(StudentDir)

	StudentDirPrivate(QString path);
	virtual ~StudentDirPrivate();

	void loadProfileDirs();
	ProfileDir *findProfileDir(QString profileType);

	StudentDir *q_ptr;

	StudentDir::Status status;
	QSettings *attributes;
	QDir mainDir;
	QList<ProfileDir *> profiles;
	QList<Class> classes;
};

#endif // STUDENTDIR_P_H
