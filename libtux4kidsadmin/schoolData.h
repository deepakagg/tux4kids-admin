#ifndef SCHOOLDATA_H
#define SCHOOLDATA_H

#include <QObject>
#include <QPointer>

#include "libtux4kidsadmin_global.h"

class QString;
class SchoolDataPrivate;
class StudentDir;
class SchoolDatabase;

class LIBTUX4KIDSADMIN_SHARED_EXPORT SchoolData : public QObject
{
	Q_OBJECT
public:
	SchoolData(QString path, QObject *parent = 0);
	~SchoolData();
	
	enum Status {
		NoError = 0,
		InitializationError = 1
	};

	Status status() const;
	StudentDir *addStudent();
	//const StudentDir & studentDirAt(int index);
	QList< QPointer<StudentDir> > students() const;
	SchoolDatabase *schoolDatabase();

protected:
	SchoolDataPrivate * const d_ptr;
	SchoolData(SchoolDataPrivate &dd, QObject *parent = 0);

signals:
	void studentAdded(StudentDir *newStudent);

private:
	Q_DECLARE_PRIVATE(SchoolData)
	Q_DISABLE_COPY(SchoolData)
};

#endif // SCHOOLDATA_H
