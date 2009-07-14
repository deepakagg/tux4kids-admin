#ifndef STUDENTDIR_H
#define STUDENTDIR_H

#include <QObject>

#include "libtux4kidsadmin_global.h"

class StudentDirPrivate;
class QString;

class LIBTUX4KIDSADMINSHARED_EXPORT StudentDir : public QObject
{
	Q_OBJECT
public:
	StudentDir(QString path, QObject *parent = 0);
	~StudentDir();

	enum Status {
		NoError = 0,
		InitializationError = 1
	};

	QString firstName() const;
	QString lastName() const;
	void setFirstName(const QString &firstName);
	void setLastName(const QString &lastName);

protected:
	StudentDirPrivate * const d_ptr;
	StudentDir(StudentDirPrivate &dd, QObject *parent = 0);
private:
	Q_DECLARE_PRIVATE(StudentDir)
	Q_DISABLE_COPY(StudentDir)
};

#endif // STUDENTDIR_H
