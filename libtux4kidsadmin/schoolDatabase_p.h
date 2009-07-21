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

	SchoolDatabase *q_ptr;

	QSqlDatabase db;

	bool isOpen;
	bool error;
	QString lastError;

};

#endif // SCHOOLDATABASE_P_H
