#ifndef SCHOOLDATABASE_H
#define SCHOOLDATABASE_H

#include <QObject>

#include "libtux4kidsadmin_global.h"

class SchoolDatabasePrivate;

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

protected:
	SchoolDatabasePrivate * const d_ptr;
	SchoolDatabase(SchoolDatabasePrivate &dd, QObject *parent = 0);

private:
	Q_DECLARE_PRIVATE(SchoolDatabase)
	Q_DISABLE_COPY(SchoolDatabase)
};

#endif // SCHOOLDATABASE_H
