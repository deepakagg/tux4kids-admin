#include "schoolData.h"
#include "schoolData_p.h"
#include "studentDir.h"
#include "studentDir_p.h"

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSettings>

/****************** SchoolDataPrivate *******************/

SchoolDataPrivate::SchoolDataPrivate(QString path)
		: status(SchoolData::NoError)
{
	mainDir.setPath(path);
	if (!mainDir.exists()) {
		if (!QDir::root().mkpath(path)) {
			status = SchoolData::InitializationError;
			return;
		}
	}
	mainDir.setPath(path);

	loadStudentDirs();

	if (!database.open(path + "/school_database.db")) {
		status = SchoolData::InitializationError;
		return;
	} else {
		database.synchronizeStudents(students);
	}

	attributes = new QSettings(mainDir.absoluteFilePath("attributes.ini"), QSettings::IniFormat);
	if (attributes->status() != QSettings::NoError) {
		status = SchoolData::InitializationError;
	}
}



SchoolDataPrivate::~SchoolDataPrivate()
{
	delete attributes;
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

SchoolDatabase *SchoolData::schoolDatabase()
{
	Q_D(SchoolData);
	return &(d->database);
}

int SchoolData::computerCount() const
{
	Q_D(const SchoolData);
	return d->attributes->value("computer_count", 20).toInt();
}

int SchoolData::setComputerCount(int computerCount)
{
}

int SchoolData::setStudentComputer(StudentDir *student, int computerNumber)
{
	student->d_func()->computerNumber = computerNumber;
}

