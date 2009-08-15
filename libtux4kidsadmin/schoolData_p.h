#ifndef SCHOOLDATAPRIVATE_P_H
#define SCHOOLDATAPRIVATE_P_H

#include <QtGlobal>
#include <QDir>
#include <QList>
#include <QPointer>
#include <QHash>

#include "schoolData.h"
#include "schoolDatabase.h"

class QString;
class ProfileDir;
class StudentDir;
class QSettings;
class ComputerDir;

class SchoolDataPrivate
{
public:
	Q_DECLARE_PUBLIC(SchoolData)

	SchoolDataPrivate(QString path);
	virtual ~SchoolDataPrivate();

	QString nextStudentDir() const;
	void loadStudentDirs();
	void createComputerDirs();

	SchoolData *q_ptr;

	QDir mainDir;
	QDir studentsDir;
	QDir computersDir;
	SchoolData::Status status;
	QList<StudentDir *> students;
	QList<ProfileDir *> profiles;
	QList<ComputerDir *> computers;
	QSettings *attributes;

	SchoolDatabase database;
};

#endif // SCHOOLDATAPRIVATE_P_H
