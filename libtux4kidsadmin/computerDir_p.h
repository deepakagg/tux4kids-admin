#ifndef COMPUTERDIR_P_H
#define COMPUTERDIR_P_H

#include <QtGlobal>
#include <QDir>
#include "libtux4kidsadmin_global.h"

class LIBTUX4KIDSADMIN_SHARED_EXPORT ComputerDirPrivate
{
public:
	Q_DECLARE_PUBLIC(ComputerDir)

	ComputerDirPrivate(QString path, int number);
	virtual ~ComputerDirPrivate();

	ComputerDir *q_ptr;

	QDir mainDir;
	int number;
};


#endif // COMPUTERDIR_P_H
