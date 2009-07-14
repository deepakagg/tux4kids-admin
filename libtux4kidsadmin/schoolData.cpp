#include "schoolData.h"
#include "schoolData_p.h"
#include "studentDir.h"

#include <QString>
#include <QDebug>

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

QString SchoolDataPrivate::nextStudentDir() const
{
	QString baseName = "student_";
	int number = 1;
	while(mainDir.exists(baseName + QString::number(number)))
		++number;

	return baseName + QString::number(number);
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

StudentDir *SchoolData::addStudent()
{
	Q_D(SchoolData);

	StudentDir *studentDir = new StudentDir(d->mainDir.absoluteFilePath(d->nextStudentDir()));
	d->students.append(studentDir);

	return studentDir;
}

