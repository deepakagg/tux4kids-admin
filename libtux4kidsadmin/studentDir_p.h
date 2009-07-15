#ifndef STUDENTDIR_P_H
#define STUDENTDIR_P_H

#include <QtGlobal>
#include <QDir>
#include <QSettings>
#include "libtux4kidsadmin_global.h"

class QString;

class StudentDirPrivate
{
public:
	Q_DECLARE_PUBLIC(StudentDir)

	StudentDirPrivate(QString path);
	virtual ~StudentDirPrivate();

	StudentDir *q_ptr;

	StudentDir::Status status;
	QSettings *attributes;
	QDir mainDir;
};

#endif // STUDENTDIR_P_H