#include "schoolDatabase.h"
#include "schoolDatabase_p.h"
#include "class.h"
#include "teacher.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QVariant>

/*********************** SchoolDatabasePrivate ***********************/

SchoolDatabasePrivate::SchoolDatabasePrivate()
{
	db = QSqlDatabase::addDatabase("QSQLITE");
}

SchoolDatabasePrivate::~SchoolDatabasePrivate()
{
	db.close();
}

void SchoolDatabasePrivate::createTables()
{
	error = false;
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}

	QSqlQuery createClasses("CREATE TABLE classes (id integer primary key, name text);", db);
	if (!createClasses.isActive()) {
		error = true;
		lastError = createClasses.lastError().text();
		return;
	}

	QSqlQuery createTeachers("CREATE TABLE teachers (id integer primary key, first_name text, last_name text);", db);
	if (!createClasses.isActive()) {
		error = true;
		lastError = createTeachers.lastError().text();
		return;
	}

	QSqlQuery createStudents("CREATE TABLE students (id integer primary key, profile_name text);", db);
	if (!createStudents.isActive()) {
		error = true;
		lastError = createStudents.lastError().text();
		return;
	}

	QSqlQuery createClassTeachers("CREATE TABLE class_teachers (id_class integer, id_teacher integer, primary key(id_class,id_teacher));", db);
	if (!createClassTeachers.isActive()) {
		error = true;
		lastError = createClassTeachers.lastError().text();
		return;
	}

	QSqlQuery createClassStudents("CREATE TABLE class_students (id_class integer, id_student integer, primary key(id_class,id_student));", db);
	if (!createClassStudents.isActive()) {
		error = true;
		lastError = createClassStudents.lastError().text();
		return;
	}

}

void SchoolDatabasePrivate::addClass(Class &newClass)
{
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}
	QSqlQuery insertClass;

	error = false;

	insertClass.prepare("INSERT INTO classes(name) VALUES(:name);");
	insertClass.bindValue(":name", newClass.name());
	insertClass.exec();

	if (!insertClass.isActive()) {
		error = true;
		lastError = insertClass.lastError().text();
		return;
	} else {
		QSqlQuery getClassId;
		getClassId.prepare("SELECT MAX(id) FROM classes;");
		getClassId.exec();

		if (!getClassId.isActive()) {
			error = true;
			lastError = getClassId.lastError().text();
			return;
		}

		if (!getClassId.first()){
			error = true;
			lastError = getClassId.lastError().text();
			return;
		} else {
			newClass.setId(getClassId.value(0).toInt());
			Q_Q(SchoolDatabase);
			emit q->classAdded(newClass);
		}
	}
}

void SchoolDatabasePrivate::updateClass(const Class &updatedClass)
{
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}

	QSqlQuery updateClass;

	error = false;

	updateClass.prepare("UPDATE classes SET name = :name WHERE id = :id;");
	updateClass.bindValue(":name", updatedClass.name());
	updateClass.bindValue(":id", updatedClass.id());
	updateClass.exec();

	if (!updateClass.isActive()) {
		error = true;
		lastError = updateClass.lastError().text();
		return;
	}

	Q_Q(SchoolDatabase);
	emit q->classUpdated(updatedClass);
}

void SchoolDatabasePrivate::deleteClass(const Class &deletedClass)
{
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}

	QSqlQuery deleteClass;

	error = false;

	deleteClass.prepare("DELETE FROM classes WHERE id = :id;");
	deleteClass.bindValue(":id", deletedClass.id());
	deleteClass.exec();

	if (!deleteClass.isActive()) {
		error = true;
		lastError = deleteClass.lastError().text();
		return;
	}

	Q_Q(SchoolDatabase);
	emit q->classDeleted(deletedClass);
}

void SchoolDatabasePrivate::addTeacher(Teacher &newTeacher)
{
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}
	QSqlQuery insertTeacher;

	error = false;

	insertTeacher.prepare("INSERT INTO teacher(first_name, last_name) VALUES(:first_name, :last_name);");
	insertTeacher.bindValue(":first_name", newTeacher.firstName());
	insertTeacher.bindValue(":last_name", newTeacher.lastName());
	insertTeacher.exec();

	if (!insertTeacher.isActive()) {
		error = true;
		lastError = insertTeacher.lastError().text();
		return;
	} else {
		QSqlQuery getTeacherId;
		getTeacherId.prepare("SELECT MAX(id) FROM teachers;");
		getTeacherId.exec();

		if (!getTeacherId.isActive()) {
			error = true;
			lastError = getTeacherId.lastError().text();
			return;
		}

		if (!getTeacherId.first()){
			error = true;
			lastError = getTeacherId.lastError().text();
			return;
		} else {
			newTeacher.setId(getTeacherId.value(0).toInt());
			Q_Q(SchoolDatabase);
			emit q->teacherAdded(newTeacher);
		}
	}
}

void SchoolDatabasePrivate::updateTeacher(const Teacher &updatedTeacher)
{
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}

	QSqlQuery updateTeacher;

	error = false;

	updateTeacher.prepare("UPDATE teachers SET first_name = :first_name, last_name = :last_name WHERE id = :id;");
	updateTeacher.bindValue(":first_name", updatedTeacher.firstName());
	updateTeacher.bindValue(":last_name", updatedTeacher.lastName());
	updateTeacher.bindValue(":id", updatedTeacher.id());
	updateTeacher.exec();

	if (!updateTeacher.isActive()) {
		error = true;
		lastError = updateTeacher.lastError().text();
		return;
	}

	Q_Q(SchoolDatabase);
	emit q->teacherUpdated(updatedTeacher);
}

void SchoolDatabasePrivate::deleteTeacher(const Teacher &deletedTeacher)
{
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}

	QSqlQuery deleteTeacher;

	error = false;

	deleteTeacher.prepare("DELETE FROM teachers WHERE id = :id");
	deleteTeacher.bindValue(":id", deletedTeacher.id());
	deleteTeacher.exec();

	if (!deleteTeacher.isActive()) {
		error = true;
		lastError = deleteTeacher.lastError().text();
		return;
	}

	Q_Q(SchoolDatabase);
	emit q->teacherDeleted(deletedTeacher);
}

/************************ SchoolDatabase **************************/

SchoolDatabase::SchoolDatabase(QObject *parent)
		: QObject(parent),
		d_ptr(new SchoolDatabasePrivate())
{
}

SchoolDatabase::SchoolDatabase(SchoolDatabasePrivate &dd, QObject *parent)
		: QObject(parent),
		d_ptr(&dd)
{
}

SchoolDatabase::~SchoolDatabase()
{
	Q_D(SchoolDatabase);
	delete d;
}

bool SchoolDatabase::open(QString dbFilePath)
{
	Q_D(SchoolDatabase);

	if (d->db.isOpen()) {
		close();
	}

	QFile dbFile(dbFilePath);
	d->db.setDatabaseName(dbFilePath);
	if (dbFile.exists()) {
		return d->db.open();
	} else {
		bool result = d->db.open();
		if (result)
			d->createTables();
		return result;
	}
}

void SchoolDatabase::close()
{
	Q_D(SchoolDatabase);
	d->db.close();
}

bool SchoolDatabase::error()
{
	Q_D(SchoolDatabase);
	return d->error;
}

QString SchoolDatabase::lastError()
{
	Q_D(SchoolDatabase);
	return d->lastError;
}

void SchoolDatabase::addClass(Class &newClass)
{
	Q_D(SchoolDatabase);
	d->addClass(newClass);
}

void SchoolDatabase::updateClass(const Class &updatedClass)
{
	Q_D(SchoolDatabase);
	d->updateClass(updatedClass);
}

void SchoolDatabase::deleteClass(const Class &deletedClass)
{
	Q_D(SchoolDatabase);
	d->deleteClass(deletedClass);
}

void SchoolDatabase::addTeacher(Teacher &newTeacher)
{
	Q_D(SchoolDatabase);
	d->addTeacher(newTeacher);
}

void SchoolDatabase::updateTeacher(const Teacher &updatedTeacher)
{
	Q_D(SchoolDatabase);
	d->updateTeacher(updatedTeacher);
}

void SchoolDatabase::deleteTeacher(const Teacher &deletedTeacher)
{
	Q_D(SchoolDatabase);
	d->deleteTeacher(deletedTeacher);
}

