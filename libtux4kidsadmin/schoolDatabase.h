#ifndef SCHOOLDATABASE_H
#define SCHOOLDATABASE_H

#include <QObject>
#include <QPointer>

#include "libtux4kidsadmin_global.h"
#include "studentDir.h"

class SchoolDatabasePrivate;
class Class;
class Teacher;

class LIBTUX4KIDSADMIN_SHARED_EXPORT SchoolDatabase : public QObject
{
	Q_OBJECT
public:
	SchoolDatabase(QObject *parent = 0);
	~SchoolDatabase();

	bool open(QString dbFilePath);
	void close();
	bool error();
	QString lastError();
	void addClass(Class &newClass);
	void updateClass(const Class &updatedClass);
	void deleteClass(const Class &deletedClass);

	void addTeacher(Teacher &newTeacher);
	void updateTeacher(const Teacher &updatedTeacher);
	void deleteTeacher(const Teacher &deletedTeacher);

	QList<Class> classList() const;
	QList<Teacher> teacherList() const;
	void synchronizeStudents(const QList< QPointer<StudentDir> > &studentList);

protected:
	SchoolDatabasePrivate * const d_ptr;
	SchoolDatabase(SchoolDatabasePrivate &dd, QObject *parent = 0);

signals:
	void classAdded(const Class &newClass);
	void classUpdated(const Class &updatedClass);
	void classDeleted(const Class &deletedClass);

	void teacherAdded(const Teacher &newTeacher);
	void teacherUpdated(const Teacher &updatedTeacher);
	void teacherDeleted(const Teacher &deletedTeacher);

private:
	Q_DECLARE_PRIVATE(SchoolDatabase)
	Q_DISABLE_COPY(SchoolDatabase)
};

#endif // SCHOOLDATABASE_H
