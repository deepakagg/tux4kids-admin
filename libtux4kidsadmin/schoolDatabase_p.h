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
	void createTriggers();
	void addClass(Class &newClass);
	void updateClass(Class &updatedClass);
	void deleteClass(Class &deletedClass);

	void addTeacher(Teacher &newTeacher);
	void updateTeacher(Teacher &updatedTeacher);
	void deleteTeacher(Teacher &deletedTeacher);

	bool addClassTeachers(Class &newClass);
	bool addClassStudents(Class &newClass);
	void addTeacherClasses(Teacher &teacher);
	bool deleteClassStudents(int classId);
	bool deleteClassTeachers(int classId);
	void deleteTeacherClasses(int teacherId);

	QList<Class> classList() const;
	QList<Class> classListNoJoin() const;
	QList<Teacher> teacherList() const;
	QList<Teacher> teacherListNoJoin() const;
	void synchronizeStudents(const QList<StudentDir *> &studentList);
	QStringList studentList() const;
	QStringList studentListNoJoin() const;
	void joinStudentsToClass(QList<Class> &classes) const;
	void joinTeachersToClass(QList<Class> &classes) const;
	void joinClassesToTeachers(QList<Teacher> &teachers) const;

	SchoolDatabase *q_ptr;

	QSqlDatabase db;

	mutable bool error;
	mutable QString lastError;

};

#endif // SCHOOLDATABASE_P_H
