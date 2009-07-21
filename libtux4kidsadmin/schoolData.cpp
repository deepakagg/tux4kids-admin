#include "schoolData.h"
#include "schoolData_p.h"
#include "studentDir.h"

#include <QString>
#include <QDebug>
#include <QSqlDatabase>

/****************** SchoolDataPrivate *******************/

SchoolDataPrivate::SchoolDataPrivate(QString path)
		: status(SchoolData::NoError)
{
	mainDir.setPath(path);
	if (!mainDir.exists()) {
		if (!QDir::root().mkpath(path)) {
			status = SchoolData::InitializationError;
		}
	}
	mainDir.setPath(path);

	loadStudentDirs();

	//qDebug() << database.open("/home/swistak/test.db");
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

void SchoolDataPrivate::loadStudentDirs()
{
	foreach(QString dirName,
		mainDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name)) {

		StudentDir *studentDir = new StudentDir(mainDir.absoluteFilePath(dirName));
		if (studentDir->status() == StudentDir::NoError) {
			students.append(studentDir);
		} else {
			delete studentDir;
		}
	}
}


/****************** SchoolData *******************/

SchoolData::SchoolData(QString path, QObject *parent)
		: QObject(parent), d_ptr(new SchoolDataPrivate(path))
{
	Q_D(SchoolData);
	d->q_ptr = this;
}

SchoolData::SchoolData(SchoolDataPrivate &dd, QObject *parent)
		: QObject(parent), d_ptr(&dd)
{
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
	emit studentAdded(studentDir);

	return studentDir;
}

/*const StudentDir & SchoolData::studentDirAt(int index)
{
	Q_D(SchoolData);
	return *(d->students.at(index));
}
*/

QList< QPointer<StudentDir> > SchoolData::students() const
{
	Q_D(const SchoolData);
	return d->students;
}

