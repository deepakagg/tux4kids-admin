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

protected:

	ClassPrivate * const d_ptr;
	Class(ClassPrivate &dd);

private:
	Q_DECLARE_PRIVATE(Class)
};

#endif // CLASS_H
