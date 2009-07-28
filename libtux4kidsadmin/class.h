#ifndef CLASS_H
#define CLASS_H

#include <QtGlobal>
#include <QString>

#include "libtux4kidsadmin_global.h"

class ClassPrivate;

class LIBTUX4KIDSADMIN_SHARED_EXPORT Class
{
public:
	Class(QString name = QString());
	~Class();

	QString name() const;
	void setName(QString name);
	int id() const;
	void setId(int id);
	Class &operator=(const Class&);

protected:

	ClassPrivate * d_ptr;
	Class(ClassPrivate &dd);

private:
	Q_DECLARE_PRIVATE(Class)
};

#endif // CLASS_H
