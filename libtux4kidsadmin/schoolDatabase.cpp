#include "schoolDatabase.h"
#include "schoolDatabase_p.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>

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

	QSqlQuery createClasses("CREATE TABLE classes (id integer primary key, name text)", db);
	if (!createClasses.isActive()) {
		error = true;
		lastError = createClasses.lastError().text();
		return;
	}

	QSqlQuery createTeachers("CREATE TABLE teachers (id integer primary key, first_name text, last_name text)", db);
	if (!createClasses.isActive()) {
		error = true;
		lastError = createTeachers.lastError().text();
		return;
	}

	QSqlQuery createStudents("CREATE TABLE students (id integer primary key, profile_name text)", db);
	if (!createStudents.isActive()) {
		error = true;
		lastError = createStudents.lastError().text();
		return;
	}

	QSqlQuery createClassTeachers("CREATE TABLE class_teachers (id_class integer, id_teacher integer, primary key(id_class,id_teacher))", db);
	if (!createClassTeachers.isActive()) {
		error = true;
		lastError = createClassTeachers.lastError().text();
		return;
	}

	QSqlQuery createClassStudents("CREATE TABLE class_students (id_class integer, id_student integer, primary key(id_class,id_student))", db);
	if (!createClassStudents.isActive()) {
		error = true;
		lastError = createClassStudents.lastError().text();
		return;
	}

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



