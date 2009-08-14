#ifndef COMPUTERDIR_P_H
#define COMPUTERDIR_P_H

#include <QtGlobal>
#include <QDir>
#include "libtux4kidsadmin_global.h"

class LIBTUX4KIDSADMIN_SHARED_EXPORT ComputerDirPrivate
{
public:
	Q_DECLARE_PUBLIC(ComputerDir)

	ComputerDirPrivate();
	virtual ~ComputerDirPrivate();

	ComputerDir *q_ptr;

	QDir mainDir;
};


#endif // COMPUTERDIR_P_H
