#ifndef APPLICATIONDIR_H
#define APPLICATIONDIR_H

#include <QObject>
#include <QString>

#include "libtux4kidsadmin_global.h"

class LIBTUX4KIDSADMINSHARED_EXPORT ApplicationDir : public QObject
{
	Q_OBJECT
public:
	ApplicationDir(QObject *parent = 0);
	virtual QString foo();
};

#endif // APPLICATIONDIR_H
