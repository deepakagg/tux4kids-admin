#ifndef PROFILEDIR_H
#define PROFILEDIR_H

#include <QObject>
#include "libtux4kidsadmin_global.h"

class ProfileDirPrivate;

class LIBTUX4KIDSADMIN_SHARED_EXPORT ProfileDir : public QObject
{
	Q_OBJECT

public:
	ProfileDir(QString path, QObject *parent = 0);
	~ProfileDir();

	enum Status {
		NoError = 0,
		InitializationError = 1
	};

	Status status() const;
	static QString profileType(QString dirPath);
	QString type() const;

protected:
	ProfileDirPrivate * const d_ptr;
	ProfileDir(ProfileDirPrivate &dd, QObject *parent = 0);

private:
	Q_DECLARE_PRIVATE(ProfileDir)
	Q_DISABLE_COPY(ProfileDir)

	friend class ComputerDir;
};

#endif // PROFILEDIR_H
