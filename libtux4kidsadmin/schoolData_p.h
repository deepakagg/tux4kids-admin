#ifndef SCHOOLDATAPRIVATE_P_H
#define SCHOOLDATAPRIVATE_P_H

#include <QtGlobal>
#include <QDir>
#include <QList>
#include <QPointer>

#include "schoolData.h"
#include "schoolDatabase.h"

class QString;
class ProfileDir;
class StudentDir;
class QSettings;

class SchoolDataPrivate
{
public:
	Q_DECLARE_PUBLIC(SchoolData)

	SchoolDataPrivate(QString path);
	virtual ~SchoolDataPrivate();

	QString nextStudentDir() const;
	void loadStudentDirs();

	SchoolData *q_ptr;

	QDir mainDir;
	SchoolData::Status status;
	QList< QPointer<StudentDir> > students;
	QList< QPointer<ProfileDir> > profiles;
	QSettings *attributes;

	SchoolDatabase database;
};

#endif // SCHOOLDATAPRIVATE_P_H
