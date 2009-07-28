#ifndef SCHOOLDATABASE_P_H
#define SCHOOLDATABASE_P_H

#include <QtGlobal>
#include <QSqlDatabase>

#include "libtux4kidsadmin_global.h"

class SchoolDatabase;

class LIBTUX4KIDSADMIN_SHARED_EXPORT SchoolDatabasePrivate
{
public:
	Q_DECLARE_PUBLIC(SchoolDatabase)

	SchoolDatabasePrivate();
	virtual ~SchoolDatabasePrivate();

	void createTables();
	void addClass(Class &newClass);
	void updateClass(const Class &updatedClass);
	void deleteClass(const Class &deletedClass);

	void addTeacher(Teacher &newTeacher);
	void updateTeacher(const Teacher &updatedTeacher);
	void deleteTeacher(const Teacher &deletedTeacher);

	QList<Class> classList() const;
	QList<Teacher> teacherList() const;
	void synchronizeStudents(const QList< QPointer<StudentDir> > &studentList);
	SchoolDatabase *q_ptr;

	QSqlDatabase db;

	mutable bool error;
	mutable QString lastError;

};

#endif // SCHOOLDATABASE_P_H
