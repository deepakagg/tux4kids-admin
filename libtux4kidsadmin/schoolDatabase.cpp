#include "schoolDatabase.h"
#include "schoolDatabase_p.h"

/*********************** SchoolDatabasePrivate ***********************/

SchoolDatabasePrivate::SchoolDatabasePrivate()
{
}

SchoolDatabase::SchoolDatabase(SchoolDatabasePrivate &dd, QObject *parent)
		: QObject(parent),
		d_ptr(&dd)
{

}


SchoolDatabasePrivate::~SchoolDatabasePrivate()
{
}

/************************ SchoolDatabase **************************/

SchoolDatabase::SchoolDatabase(QObject *parent)
		: QObject(parent),
		d_ptr(new SchoolDatabasePrivate())
{
}

SchoolDatabase::~SchoolDatabase()
{
}

