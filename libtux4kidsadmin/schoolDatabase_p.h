#ifndef SCHOOLDATABASE_P_H
#define SCHOOLDATABASE_P_H

#include <QtGlobal>

#include "libtux4kidsadmin_global.h"

class SchoolDatabase;

class LIBTUX4KIDSADMIN_SHARED_EXPORT SchoolDatabasePrivate
{
public:
	Q_DECLARE_PUBLIC(SchoolDatabase)

	SchoolDatabasePrivate();
	virtual ~SchoolDatabasePrivate();

	SchoolDatabase *q_ptr;

};

#endif // SCHOOLDATABASE_P_H
