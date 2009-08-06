#ifndef STUDENTDIR_H
#define STUDENTDIR_H

#include <QObject>

#include "libtux4kidsadmin_global.h"
#include "class.h"

class StudentDirPrivate;
class ProfileDir;
class QString;

class LIBTUX4KIDSADMIN_SHARED_EXPORT StudentDir : public QObject
{
	Q_OBJECT
public:
	StudentDir(QString path, QObject *parent = 0);
	~StudentDir();

	enum Status {
		NoError = 0,
		InitializationError = 1
	};

	Status status() const;

	QString dirName() const;
	QString firstName() const;
	QString lastName() const;
	void setFirstName(const QString &firstName);
	void setLastName(const QString &lastName);
	void addProfileDir(ProfileDir *profileDir);
	ProfileDir *addProfileDir(QString profileType);
	QList<Class> *classes();
	//void setClasses(const QList<Class>& classes);

protected:
	StudentDirPrivate * const d_ptr;
	StudentDir(StudentDirPrivate &dd, QObject *parent = 0);
private:
	Q_DECLARE_PRIVATE(StudentDir)
	Q_DISABLE_COPY(StudentDir)
};

#endif // STUDENTDIR_H
