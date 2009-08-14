#include "computerDir.h"
#include "computerDir_p.h"

/**************************** ComputerPrivate *************************/

ComputerDirPrivate::ComputerDirPrivate()
{
}

ComputerDirPrivate::~ComputerDirPrivate()
{
}

/**************************** ComputerDir *************************/

ComputerDir::ComputerDir(QObject *parent)
		: QObject(parent),
		d_ptr(new ComputerDirPrivate())
{
	Q_D(ComputerDir);
	d->q_ptr = this;
}

ComputerDir::ComputerDir(ComputerDirPrivate &dd, QObject *parent)
		: QObject(parent), d_ptr(&dd)
{
	Q_D(ComputerDir);
	d->q_ptr = this;
}

ComputerDir::~ComputerDir()
{
}

